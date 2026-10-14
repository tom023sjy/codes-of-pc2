#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int T;
	cin >> T;
	while (T --) {
		int n, k;
		cin >> n >> k;
		int ans = -n - 1;
		for (int i = 0; i <= n; i ++) {
			int b = __builtin_ctz((i >> k) + 1);
			ans += (1 << b + 1);
		}
		ans <<= k;
		cout << ans << endl;
	}
	return 0;
}