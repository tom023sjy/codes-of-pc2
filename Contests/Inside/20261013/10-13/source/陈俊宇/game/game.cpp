#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 5005, NN = 1000005, P = 1000000007;
int n;
vector<int> g[NN];
int f[N][N], cc[N], deg[NN];

ll fpow(ll x, ll y){
	ll res = 1;
	for (; y; y>>=1,x = x*x %P){
		if (y & 1)
			res = res * x %P;
	}
	return res;
}

int dfs(int u, int sour){
	int cnt = 0;
	for (int v : g[u]){
		if (v == sour) continue;
		cnt = max(cnt, dfs(v,u));
	}
	cnt++;
	cc[u] = cnt;
	f[u][0] = f[u][1] = 1;
	for (int d = 2; d <= cnt; d++){
		ll r1 = 1, r2 = 1;
		for (int v : g[u]){
			if (v == sour) continue;
			r1 = r1 * f[v][min(d-1,cc[v])] % P;
			r2 = r2 * f[v][min(d-2,cc[v])] % P;
		}
		f[u][d] = ((ll)f[u][d] + r1 - r2 + P) %P;
	}
	for (int d = 1; d <= cnt; d++){
		f[u][d] = (f[u][d] + f[u][d-1]) %P;
	}
	return cnt;
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++){
		int u,v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		deg[u]++; deg[v]++;
	}
	int c1 = 0, c2 = 0;
	for (int i = 1; i <= n; i++){
		if (deg[i] == 1) c1++;
		if (deg[i] == 2) c2++;
	}
	if (c1 == 2 && c2 == n-2){
		cout << "1";
		return 0;
	}
	int cnt = dfs(1,0);
	ll ans = 1;
	for (int d = 2; d <= cnt; d++){
		//if (f[1][d] == 0) break;
		ll r1 = 1, r2 = 0, r3 = 1;
		for (int v : g[1]){
			r1 = r1 * f[v][min(d-2,cc[v])] % P;
		}
		for (int v : g[1]){
			r2 = (r2 + r1 * ((ll)f[v][min(d-1,cc[v])]-f[v][min(d-2,cc[v])]) %P * fpow(f[v][min(d-2,cc[v])],P-2) %P) %P;
		}
		ans = (ans - r2 + f[1][d] - f[1][d-1] + 2ll*P) %P;
	}
	cout << ans;
	return 0;
}
