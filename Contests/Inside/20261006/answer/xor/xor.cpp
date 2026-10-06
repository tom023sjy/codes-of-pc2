#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf "xor.in"
#define ouf "xor.out"
const int N = 1e5;
int a[N + 5], s[N + 5];
void bruh();
signed main() {
    #ifndef ONLINE_JUDGE
        freopen(inf, "r", stdin);
        freopen(ouf, "w", stdout);
    #endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i]; 
    if (n <= 1e4) {
        int cnt = 0;
        for (int i = 1; i <= n; i ++)
            s[i] = s[i - 1] ^ a[i];
        for (int l = 1; l <= n; l ++) {
            int mx = 0;
            for (int r = l; r <= n; r ++) {
                mx = max(mx, a[r]);
                if ((s[r] ^ s[l - 1]) <= mx)
                    cnt ++;
            }
        }
        cout << cnt;
        return 0;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
        s[i] = s[i - 1] ^ a[i];
    map<int, int> mp;
    mp[0] = 1;
    for (int i = 1; i <= n; i ++) {
        cnt += mp[s[i - 1]];
        mp[s[i - 1]] ++;
    }
    cout << cnt;
    return 0;
}