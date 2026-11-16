#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug
const int mod = 10007;
int fp(int a, int b, int p) {
	int ret = 1;
	for (; b; b >>= 1, a = a * a % p)
		if (b & 1)
			ret = ret * a % p;
	return ret;
}
int getc(int n, int m, int p) {
	if (n < m) return 0;
	if (m > n - m) m = n - m;
	int s1 = 1, s2 = 1;
	for (int i = 0; i < m; i ++)
		s1 = s1 * (n - i) % p, s2 = s2 * (i + 1) % p;
	return s1 % p * fp(s2, p - 2, p) % p;
}
int lucas(int n, int m, int p) {
	if (m == 0) return 1;
	return getc(n % p, m % p, p) * lucas(n / p, m / p, p) % p;
}
const int N = 1e6;
int a[N + 5];
signed main() {
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
	#ifdef debug
	for (int i = 1; i <= n; i ++) 
		cerr << a[i] << " " << lucas(n - 1, i - 1, mod) << endl;
	#endif
	return 0;
}
