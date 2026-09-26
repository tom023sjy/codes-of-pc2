#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, m, ans, dp[100010], v[100010];
bool flag[100010];
vector<ll> E[100010];

void dfs(ll x) {
	dp[x] = v[0];
	for (ll i = 0; i < E[x].size(); i++) {
		ll y = E[x][i];
		dfs(y);
		if (i == 0 && flag[x]) continue;
		dp[x] = max(dp[x], dp[x] + dp[y]);
	}
	ans = max(ans, dp[x]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	freopen("block.in", "r", stdin);
	freopen("block.out", "w", stdout);

	cin >> n >> m;
	
	for (ll i = 1; i <= n; i++) cin >> v[i];
	
	for (ll i = 1; i <= n; i++) {
		ll x; cin >> x;
		while (x--) {
			ll y; cin >> y;
			E[i].push_back(y);
		}
	}
	
	while (m--) {
		ll u, v;
		cin >> u >> v;
		flag[v] = true;
	}
	
	dfs(1);

	cout << ans;

	return 0;
}

/*
7
2
5 6 2 6 8 2 1
2 2 3
1 4
2 5 6
0
1 7
0
0
2 1
7 5
*/

