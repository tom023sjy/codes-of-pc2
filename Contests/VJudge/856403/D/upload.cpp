#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6, mod = 19930726;
char s[N * 2 + 5];
int pos[N * 2 + 5], box[N + 5];
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
signed main() {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    int curr = 0;
    s[0] = 15;
    s[++ curr] = 31;
    for (char c : str)
        s[++ curr] = c, s[++ curr] = 31;
    s[curr + 1] = 127;
    int maxr = 0, tmid = 0;
    for (int i = 1; i <= curr; i ++) {
        if (i <= maxr) 
            pos[i] = min(pos[tmid * 2 - i], maxr - i + 1);
        while (s[i - pos[i]] == s[i + pos[i]]) 
            pos[i] ++;
        if (pos[i] + i > maxr)
            maxr = pos[i] + i - 1, tmid = i;
    }
    for (int i = 2; i <= curr; i += 2)
        if (pos[i] >= 2)
            box[pos[i] - 1] ++;
    int s = 0, ans = 1;
    for (int i = n; i >= 1; i --) {
        if (i & 1 ^ 1)
            continue;
        s += box[i];
        if (k < s) {
            ans *= fp(i, k, mod);
            ans %= mod;
            k = 0;
            break;
        }
        else {
            ans *= fp(i, s, mod);
            ans %= mod;
            k -= s;
        }
    }
    if (k)
        return puts("-1"), 0;
    cout << ans;
    return 0;
}
