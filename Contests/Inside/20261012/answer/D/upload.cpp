#include <bits/stdc++.h>
using namespace std;
#define int long long
int lowbit(int x) {
	return x & -x;
}
signed main() {
	/*
	b = (int)log2(lowbit((i >> k) + 1))
	((1 << b + 1) - 1) << k
	*/
	vector<int> p;
	for (int i = 0; i <= 30; i ++)
		p.push_back(1 << i);
	int T;
	cin >> T;
	while (T --) {
		int n, k, ans = 0;
		cin >> n >> k;
		for (int i = 0; i <= n; i ++) {
			int b = lower_bound(p.begin(), p.end(), lowbit((i >> k) + 1)) - p.begin();
			ans += ((1 << b + 1) - 1) << k;
		}
		cout << ans << endl;
	}
	return 0;
}
