#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5, mod = 998244353;
int fct[N + 5], ifct[N + 5];
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
signed main() {
    int n;
    cin >> n;
    fct[0] = 1;
    for (int i = 1; i <= n; i ++)
        fct[i] = fct[i - 1] * i % mod;
    ifct[n] = fp(fct[n], mod - 2, mod);
    return 0;
}