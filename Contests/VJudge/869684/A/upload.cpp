#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353, N = 4e5;
int a[N + 5];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T --) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i ++)
            cin >> a[i];
        int mul = 1;
        map<int, int> mp;
        for (int i = 1; i <= n; i ++) {
            mp[a[i]] ++;
            mul *= (m - mp[a[i]] + 1);
            mul %= mod;
            cout << mul << " ";
        }
        cout << endl;
    }
    return 0;
}