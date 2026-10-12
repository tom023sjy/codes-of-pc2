#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 1e6;
pii pos[N + 5];
vector<int> g[N + 5];
int siz[N + 5];
bool vis[N + 5];
void dfs(int id) {
	vis[id] = 1;
	siz[id] = 1;
	for (int nxt : g[id]) {
		dfs(nxt);
		siz[id] += siz[nxt];
	}
}
signed main() {
	int n;
	cin >> n;
	map<pair<int, int>, int> mp;
	for (int i = 1; i <= n; i ++)
		cin >> pos[i].first >> pos[i].second;
	stable_sort(pos + 1, pos + n + 1);
	for (int i = 1; i <= n; i ++)
		mp[pos[i]] = i;
	for (int i = 1; i <= n; i ++) {
		int x = pos[i].first, y = pos[i].second;
		if (mp.count({x + 1, y + 1}))
			g[i].push_back(mp[{x + 1, y + 1}]);
		if (mp.count({x + 1, y}))
			g[i].push_back(mp[{x + 1, y}]);
		if (mp.count({x + 1, y - 1}))
			g[i].push_back(mp[{x + 1, y - 1}]);
	}
	for (int i = 1; i <= n; i ++)
		if (!vis[i])
			dfs(i);
	int cnt = 0;
	for (int i = 1; i <= n; i ++)
		if (siz[i] == 1)
			cnt ++;
	cout << cnt;
	return 0;
}
