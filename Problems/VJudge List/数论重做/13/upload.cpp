#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug
const int mod = 10007, N = 1e6;
int a[N + 5], mul[mod + 5], inv[mod + 5];
int fp(int a, int b, int p) {
	int ret = 1;
	for (; b; b >>= 1, a = a * a % p)
		if (b & 1)
			ret = ret * a % p;
	return ret;
}
void init(int n) {
    mul[0] = 1;
    for (int i = 1; i <= n; i ++)
        mul[i] = mul[i - 1] % mod * (i % mod) % mod;
    inv[n] = fp(mul[n], mod - 2, mod);
    for (int i = n - 1; i >= 0; i --)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
int getc(int n, int m, int p) {
	if (n < m) return 0;
	// if (m > n - m) m = n - m;
	// int s1 = 1, s2 = 1;
	// for (int i = 0; i < m; i ++)
	// 	s1 = s1 * (n - i) % p, s2 = s2 * (i + 1) % p;
	// return s1 % p * fp(s2, p - 2, p) % p;
    return mul[n] * inv[m] % mod * inv[n - m] % mod;
}
int lucas(int n, int m, int p) {
	if (m == 0) return 1;
	return getc(n % p, m % p, p) * lucas(n / p, m / p, p) % p;
}
signed main() {
	init(mod - 1);
	int n;
	cin >> n;
	int res = 0;
	// a[i] * lucas(n - 1, i - 1, 1e4 + 7)
	for (int i = 1, curr = 0; i * 2 <= n; i ++)
		a[i] = ++ curr, a[n - i + 1] = ++ curr;
	if (n % 2)
		a[n / 2 + 1] = n;
	for (int i = 1; i <= n; i ++) 
		res += a[i] % mod * lucas(n - 1, i - 1, mod) % mod, res %= mod;
	cout << res;
	return 0;
}