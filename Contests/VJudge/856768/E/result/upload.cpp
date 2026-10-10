#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> depart(int x) { // sqrt N
	vector<int> resa, resb;
	for (int i = 1; i * i <= x; i ++) {
		if (x % i) continue;
		resa.push_back(i);
		if (i * i != x) resb.push_back(x / i);
	}
	reverse(resb.begin(), resb.end());
	vector<int> ret;
	for (int val : resa)
		ret.push_back(val);
	for (int val : resb)
		ret.push_back(val);
	return ret;
}
int fnd(vector<int> a, int x) {
	int l = 0, r = a.size() - 1, ans = 0;
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
			int p = vl[fnd(vl, m)];
			for (int i = 1; i <= p; i ++)
				cout << i << " ";
			/*
			1   2     ... p
			p*2 p+1   ... p*2-1
			p*3 p*2+1     p*3-1
			*/
			for (int i = 2; i * p <= n; i ++) {
				cout << i * p << " ";
				for (int j = i * p - p + 1; j < i * p; j ++)
				 	cout << j << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
