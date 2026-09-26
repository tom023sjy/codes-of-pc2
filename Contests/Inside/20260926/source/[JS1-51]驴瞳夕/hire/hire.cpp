#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 5;
int n, m, k, d, p[N];

signed main () {
	freopen ("hire.in", "r", stdin);
	freopen ("hire.out", "w", stdout);

	cin >> n >> m >> k >> d;
	while (m --) {
		int x, y;
		cin >> x >> y;
		p[x] += y;
		int sum = k * d;
		bool f = 0;
		for (int i = 1; i <= n - d; i ++) {
			sum = min (sum, k * d);
			sum += k;
			sum -= p[i];
			if (sum < 0) {
				f = 1;
				break;
			}
		}
		if (f) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}
