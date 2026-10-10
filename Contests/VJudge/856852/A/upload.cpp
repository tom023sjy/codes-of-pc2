#include <bits/stdc++.h>
using namespace std;
#define int long long
priority_queue<int> a[2];
signed main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		int x;
		cin >> x;
		a[x & 1].push(x);
	}
	// Choose them all in a[0] or all in a[1]
	int ans = 0;
	// Choose in a[0]
	if (a[0].size() >= k) {
		int sum = 0;
		for (int i = 1; i <= k; i ++, a[0].pop()) sum += a[0].top();
		ans = max(ans, sum);
	}
	// Choose in a[1]
	if (a[1].size() >= k) {
		int sum = 0;
		for (int i = 1; i <= k; i ++, a[1].pop()) sum += a[1].top();
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}
