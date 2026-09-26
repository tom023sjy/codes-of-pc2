#include <bits/stdc++.h>
using namespace std;

#define int long long
const int Mod = 998244353;
const int N = 205;
int n, ans = 1, p[N * N];

int qp (int x, int t) {
	int res = 1;
	while (t) {
		if (t & 1) res = res * x % Mod;
		t >>= 1;
		x = x * x % Mod;
	}
	return res;
}

signed main () {
	freopen ("set.in", "r", stdin);
	freopen ("set.out", "w", stdout);
	
	cin >> n;
	p[1] ++;
	for (int i = 2; i <= n; i ++) {
		ans *= i;
		ans %= Mod;
		for (int j = 1; j <= (i - 1) * i / 2; j ++) {
			ans *= qp (i + j, p[j]);
			ans %= Mod;
		}
		for (int j = (i - 1) * i / 2; j > 0; j --) {
			p[j + i] += p[j];
			p[i + j] %= (Mod - 1);
		}
		p[i] ++;
	}
	cout << ans;
	return 0;
}
