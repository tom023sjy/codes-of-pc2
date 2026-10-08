#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int T;
	cin >> T;
	while (T --) {
		int n, k, d;
		cin >> n >> k >> d;
		if (d & 1) {
			int ans = 0;
			// l, r取奇数
			int cnt = (n + 1) / 2;
			ans += cnt * (cnt + 1) / 2;
			// l, r取偶数
			cnt = n / 2;
			ans += cnt * (cnt + 1) / 2;
			cout << ans;
		}
		else cout << n * (n + 1) / 2; // 此时l-r任取 
		puts("");
	}
	return 0;
}
