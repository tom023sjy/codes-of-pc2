#include <bits/stdc++.h>
using namespace std;
#define int long long
int solve(int n, int k) {
	int ret = 0;
	for (int t = 0; t <= 30; t ++) {
		int p = ((1ll << t) - 1) << k;
		if (p > n) break;
		for (int j = 30; j >= 0; j --) {
			if (j >= k && j <= k + t) continue;
			if (p + (1ll << j) <= n)
				p += 1ll << j;
		}
		int a = p >> (t + k + 1), b = p & ((1ll << k) - 1);
		int r1 = a << k, r2 = b + 1;
		// cerr << r1 << " " << r2 << "\n";
		ret += (r1 + r2) * ((1ll << t + 1) - 1 << k);
	}
	return ret;
}
signed main() {
	int T;
	cin >> T;
	while (T --) {
		int n, k;
		cin >> n >> k;
		cout << solve(n, k) << endl;
	}
	return 0;
}