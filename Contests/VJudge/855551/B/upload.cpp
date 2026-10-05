#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int n, m;
string s[N + 5], t[N + 5];
struct Hash {
    int a, b, c;
} hs[N + 5], ht[N + 5];
bool operator == (Hash x, Hash y) {
    return x.a == y.a && x.b == y.b && x.c == y.c;
}
bool operator < (Hash x, Hash y) {
    if (x.a != y.a) return x.a < y.a;
    if (x.b != y.b) return x.b < y.b;
    return x.c < y.c;
}
deque<Hash> q;
map<Hash, int> tot, mp;
Hash calc(string s) {
    int rs1 = 0, rs2 = 0, rs3 = 0;
    const int mod1 = 65537, mod2 = 998244353, mod3 = 1e9 + 7;
    for (char c : s) {
        rs1 = rs1 * 128 + c;
        rs2 = rs2 * 128 + c; 
        rs3 = rs3 * 128 + c;
        rs1 %= mod1;
        rs2 %= mod2;
        rs3 %= mod3;
    }
    return {rs1, rs2, rs3};
}
bool check(int len, int cnt) {
    q.clear();
    tot.clear();
    int diff = 0;
    for (int i = 1; i < len; i ++) {
        q.push_back(ht[i]);
        if (mp.count(q.back())) {
            int j = mp[q.back()];
            tot[hs[j]] ++;
            if (tot[hs[j]] == 1)
                diff ++;
        }
    }
    for (int i = len; i <= m; i ++) {
        // push
        q.push_back(ht[i]);
        if (mp.count(q.back())) {
            int j = mp[q.back()];
            tot[hs[j]] ++;
            if (tot[hs[j]] == 1)
                diff ++;
        }
        // calc
        if (diff >= cnt)
            return 1;
        // pop
        if (mp.count(q.front())) {
            int j = mp[q.front()];
            tot[hs[j]] --;
            if (tot[hs[j]] == 0)
                diff --;
        }
        q.pop_front();
    }
    return 0;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> s[i], hs[i] = calc(s[i]), mp[hs[i]] = i;
    cin >> m;
    for (int i = 1; i <= m; i ++)
        cin >> t[i], ht[i] = calc(t[i]);
    int ans1 = 0, ans2 = 9e18;
    for (int i = 1; i <= n; i ++) 
        for (int j = 1; j <= m; j ++) 
            if (hs[i] == ht[j]) {
                ans1 ++;
                break;
            }
    int l = 0, r = m;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid, ans1))
            ans2 = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans1 << endl << ans2;
    return 0;
}