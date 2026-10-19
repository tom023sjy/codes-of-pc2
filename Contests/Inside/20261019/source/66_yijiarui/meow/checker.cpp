#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

struct SplitMix64 {
    uint64_t x;
    explicit SplitMix64(uint64_t seed = 0) : x(seed) {}
    uint64_t next() {
        uint64_t z = (x += 0x9e3779b97f4a7c15ULL);
        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
        z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
        return z ^ (z >> 31);
    }
    uint64_t bounded(uint64_t mod) {
        uint64_t threshold = -mod % mod, r;
        do r = next(); while (r < threshold);
        return r % mod;
    }
};

vector<int> generate_cards(int n, uint64_t seed) {
    size_t m = (size_t)n * 2;
    uint64_t mix = seed ^ ((uint64_t)n * 0x9e3779b97f4a7c15ULL)
                        ^ 0x123456789abcdef0ULL;
    SplitMix64 rng(mix);
    vector<int> a(m);
    for (int i = 0; i < n; ++i) a[2 * i] = a[2 * i + 1] = i + 1;
    for (size_t i = m - 1; i > 0; --i)
        swap(a[i], a[(size_t)rng.bounded((uint64_t)i + 1)]);
    return a;
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    // registerLemonChecker(argc, argv);
    int n = inf.readInt(1, 500000, "n");
    uint64_t seed = inf.readUnsignedLong();
    vector<int> card = generate_cards(n, seed);

    vector<int> put(2 * n);
    int mx = 0;
    for (int i = 0; i < 2 * n; ++i) {
        put[i] = ouf.readInt(1, 1000000000, format("stack[%d]", i + 1));
        mx = max(mx, put[i]);
        if(mx > 1000000) quitf(_wa,"Your stack id exceeds 1e6 QAQ");
    }
    if (!ouf.seekEof())
        quitf(_pe, "extra tokens after the required %d stack numbers QAQ", 2 * n);

    // Compress arbitrary positive stack labels; the score still uses their
    // actual maximum, as required by the statement.
    unordered_map<int, int> id;
    id.reserve(2 * n + 1);
    vector<vector<int>> st;
    for (int i = 0; i < 2 * n; ++i) {
        auto [it, inserted] = id.emplace(put[i], (int)id.size());
        if (inserted) st.emplace_back();
        st[it->second].push_back(card[i]);
    }

    vector<int> owner(n + 1, -1);
    queue<int> q;
    for (int i = 0; i < (int)st.size(); ++i) if (!st[i].empty()) q.push(i);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (st[x].empty()) continue;
        int v = st[x].back();
        if (owner[v] == -1) {
            owner[v] = x;
        } else if (owner[v] != x) {
            int y = owner[v];
            if (st[y].empty() || st[y].back() != v) continue; // stale event
            owner[v] = -1;
            st[x].pop_back();
            st[y].pop_back();
            if (!st[x].empty()) q.push(x);
            if (!st[y].empty()) q.push(y);
        }
    }

    int left = 0, badStack = -1;
    for (int i = 0; i < (int)st.size(); ++i) {
        left += (int)st[i].size();
        if (!st[i].empty() && badStack == -1) badStack = i;
    }
    if (left) {
        int original = 0;
        for (auto [label, compressed] : id) if (compressed == badStack) original = label;
        quitf(_wa, "Unaccepted... %d cards remain; stack %d has %d cards (top=%d) QAQ",
              left, original, (int)st[badStack].size(), st[badStack].back());
    }
    double score;
    if (mx <= 190) quitf(_ok,"Accepted!!!!! mx = %d, f(mx) = 1 QWQ", mx);
    else if (mx <= 260) score = 1.0 - (mx - 190) / 600.0;
    else if (mx < 1415) score = max(0.9 - sqrt((double)mx - 260.0) / 100.0, 0.55);
    else if (mx <= 1500) score = 0.45 + (1500 - mx)/850;
    else if (mx <= 500000) score = 0.1 + max(700-sqrt((double)mx),0.0)/2e3;
    else if (mx == 500001) score = 0.1;
    else score = 0.05;
    if(n <= 5) quitp(score*5, format("Accepted!!!!! mx = %d, f(mx) = %.10f QWQ", mx, score));
    else quitp(score*95, format("Accepted!!!!! mx = %d, f(mx) = %.10f QWQ", mx, score));
}
