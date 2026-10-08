#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> depart(int x) { // sqrt N
	vector<int> ret;
	for (int i = 2; i * i <= x; i ++) {
		ret.push_back(i);
		while (x % i == 0) 
			x /= i;
	}
	if (x > 1) ret.push_back(x);
	return ret;
}
int find(vector<int> a, int x) {
	int l = 0, r = a.size() - 1, ans = -1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (a[mid] <= x)
			ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}
signed main() {
	int T;
	cin >> T;
	while (T --) {
		int n, m;
		cin >> n >> m;
		if (2 * m > n) {
			for (int i = 1; i < m; i ++)
				cout << i << " ";
			cout << n << " ";
			for (int i = m; i < n; i ++)
				cout << i << " ";
		}
		else {
			auto vl = depart(n);
			int p = find(vl, m);
			for (int i = 1; i <= p; i ++)
				cout << i << " ";
			for (int i = p * 2; i < n; i += p) {
				cout << i << " ";
				for (int j = i - p + 1; j < min(i, n - 1); j ++)
					cout << j << " ";
			}
			for (int i = n - p + 1; i < n; i ++)
				cout << i << " ";
		}
	}
	return 0;
}
