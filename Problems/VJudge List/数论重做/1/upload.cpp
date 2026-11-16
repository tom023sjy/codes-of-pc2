#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e5 + 3;
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
signed main() {
	int m, n;
    cin >> m >> n;
    cout << ((fp(m, n, mod) - m * fp(m - 1, n - 1, mod)) % mod + mod) % mod;
    return 0;
}
