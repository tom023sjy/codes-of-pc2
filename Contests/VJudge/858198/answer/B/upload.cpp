#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 1e6;
vector<int> g[N + 5];
signed main() {
	int n;
	cin >> n;
	map<pii, bool> mp;
	for (int i = 1; i <= n; i ++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		mp[{u, v}] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= N; i ++) {
		if (g[i].empty()) continue;
		sort(g[i].begin(), g[i].end(), greater<int>());
		for (int j : g[i])
			if (mp[{i - 1, j + 1}]) mp[{i - 1, j + 1}] = 0;
			else if (mp[{i - 1, j}]) mp[{i - 1, j}] = 0;
			else if (mp[{i - 1, j - 1}]) mp[{i - 1, j - 1}] = 0;
			else ans ++;	
	}
	cout << ans;
	return 0;
}
 