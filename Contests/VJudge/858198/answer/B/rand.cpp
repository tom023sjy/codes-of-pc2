#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6, X = 1e6;
signed main() {
    auto sd = chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count();
    mt19937 rnd1(sd);
    int T = X;
    set<pair<int, int>> st;
    while (T --) {
        while (1) {
            auto sd = chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count();
            mt19937 rnd(sd);
            int x = rnd() % N + 1, y = rnd() % N + 1;
                st.insert({x, y});
                break;
        }
    }
    cout << st.size() << endl;
    for (auto kv : st) 
        cout << kv.first << " " << kv.second << endl;
    return 0;
}