#include <bits/stdc++.h>
using namespace std;

#define int long long
const int Mod = 1e9 + 7;
const int N = 5005;
int n, m, a[N], b[N], mx;

signed main () {
	freopen ("three.in", "r", stdin);
	freopen ("three.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		b[a[i]] ++;
		mx = max (mx, b[a[i]]); 
	}
	
	if (mx <= 2) {
		for (int i = 1; i <= m; i ++) {
			if (b[i] < 0) {
				cout << 0;
				return 0;
			}
			if (b[i] > 0) {
				b[i + 1] -= b[i];
				b[i + 2] -= b[i];
			}
		}
		cout << "1";
		return 0;
	}
	
	if (m <= 3) {
		int ans = 0;
		for (int i = 0; i <= min (b[1], min (b[2], b[3])); i ++) {
			if ((b[1] - i) % 3 == 0 && (b[2] - i) % 3 == 0 && (b[3] - i) % 3 == 0)
				ans ++;
			ans %= Mod;
		}
		cout << ans;
		return 0;
	}
	
	if (m <= 4) {
		int ans = 0;
		for (int i = 0; i <= min (b[1], min (b[2], b[3])); i ++) {
			for (int j = 0; j <= min ((b[2] - i), min ((b[3] - i), b[4])); j ++) {
				if ((b[1] - i) % 3 == 0 && (b[2] - i - j) % 3 == 0 && (b[3] - i - j) % 3 == 0 && (b[4] - j) % 3 == 0) ans ++;
				ans %= Mod;
			}
		}
		cout << ans;
		return 0;
	}
	
	int ans = 1;
	for (int i = 1; i <= m; i ++) {
		if (i % 4 == 0) {
			int sum = 0;
			for (int j = 0; j <= min (b[i - 3], min (b[i - 2], b[i - 1])); j ++) {
				if ((b[i - 3] - j) % 3 == 0 && (b[i - 2] - j) % 3 == 0 && (b[i - 1] - j) % 3 == 0)
					sum ++;
			}
			ans *= sum;
			ans %= Mod;
		}
	}
	cout << ans;
	return 0;
}
