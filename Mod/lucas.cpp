#include <bits/stdc++.h>
using namespace std;
#define int long long
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
signed main() {
    
    return 0;
}

