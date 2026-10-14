#include <bits/stdc++.h>
#define int long long
#define putc(c) putchar(c)
const int N = 1e7;
char s[N + 5];
char s1[N + 5], s2[N + 5];
int min(int a, int b) {
	return (a < b)?a:b;
}
void solve(int n) {
	memset(s1, 0, sizeof s1);
	memset(s2, 0, sizeof s2);
	int a = -1;
	for (int i = 1; i <= n; i ++)
		if (s[i] == '1') {
			a = i;
			break;
		}
	int b = -1;
	for (int i = a; i <= n; i ++)
		if (s[i] == '0') {
			b = i;
			break;
		}
	if (a == -1) return puts("0"), void();
	if (b == -1) {
		for (int i = a; i < n; i ++)
			putc('1');
		if (a > 1) putc('1');
		else putc('0');
		return puts(""), void();
	}
	int c = n + 1;
	for (int i = b; i <= n; i ++)
		if (s[i] == '1') {
			c = i;
			break;
		}
	int x = min(b - a, c - b);
	int curr = 0;
	for (int i = a; i <= n; i ++) // n - a + 1
		s1[i - a + 1] = s[i];
	curr = b - a;
	for (int i = b - x; i <= n - x; i ++) // n - b + 1
		s2[++ curr] = s[i];
	for (int i = 1; i <= b - a; i ++)
		s2[i] = '0';
	for (int i = 1; i <= n - a + 1; i ++)
		if (s1[i] == s2[i])
			s1[i] = '0';
		else s1[i] = '1';
	int p = -1;
	for (int i = 1; i <= n - a + 1; i ++)
		if (s1[i] == '1') {
			p = i;
			break;
		}
	if (p == -1) return puts("0"), void();
	puts(s1 + p);
}
signed main() {
	int T;
	scanf("%lld", &T);
	while (T --) {
		int n;
		scanf("%lld%s", &n, s + 1);
		solve(n);
	}
	return 0;
}