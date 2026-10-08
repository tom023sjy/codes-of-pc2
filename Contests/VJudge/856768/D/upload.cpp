#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 1e5;
vector<int> a[N + 5];
vector<pii> g[N + 5];
const int dx[] = {1, 0, 0, -1}, dy[] = {0, 1, -1, 0};
int dis[N + 5], sum[N + 5];
pii itop[N + 5];
void dijkstra(int id) {
	priority_queue<pii, vector<pii>, greater<pii>> q;
	memset(dis, 0x3f, sizeof dis);
	q.push({0, id});
	dis[id] = 0;
	while (!q.empty()) {
		int idx = q.top().second;
		q.pop();
		for (pii nxt : g[idx])
			if (dis[nxt.first] > nxt.second + dis[idx]) {
				dis[nxt.first] = nxt.second + dis[idx];
				q.push({dis[nxt.first], nxt.first});
			}
	}
}
signed main() {
	int n, m, T;
	cin >> n >> m >> T;
	for (int i = 1; i <= n; i ++)
		a[i].resize(m + 5, 0);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j < m; j ++)
			if (a[i][j] + a[i][j + 1] < 0)
				return puts("No"), 0;
	for (int i = 1; i < n; i ++)
		for (int j = 1; j <= m; j ++)
			if (a[i + 1][j] + a[i][j] < 0)
				return puts("No"), 0;
	map<pii, int> ptoi;
	int curr = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) 
			ptoi[{i, j}] = ++ curr, itop[curr] = {i, j};
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) 
			for (int k = 0; k < 4; k ++) {
				int nx = i + dx[k], ny = j + dy[k];
				if (!(1 <= nx && nx <= n && 1 <= ny && ny <= m))
					continue;
				g[ptoi[{i, j}]].push_back({ptoi[{nx, ny}], a[i][j] + a[nx][ny]});
				g[ptoi[{nx, ny}]].push_back({ptoi[{i, j}], a[i][j] + a[nx][ny]});
			}
	memset(sum, -0x3f, sizeof sum);
	while (T --) {
		int x, y;
		cin >> x >> y;
		dijkstra(ptoi[{x, y}]);
		for (int i = 1; i <= n * m; i ++)
			sum[i] = max(sum[i], (dis[i] + a[x][y] + a[itop[i].first][itop[i].second]) / 2);
	}
	int minn = 9e18;
	for (int i = 1; i <= n * m; i ++)
		minn = min(minn, sum[i]);
	cout << minn;
	return 0;
}