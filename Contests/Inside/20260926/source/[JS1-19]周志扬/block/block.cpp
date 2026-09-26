#include <bits/stdc++.h>
using namespace std;

struct Edge { int x, y; };

const int N = 100005;
int n, m, cur, ans;
int f[N], Val[N], Sum[N];
Edge F[N], G[N];

int Find(int x) { return f[x] == x ? x : f[x] = Find(f[x]); }

void Merge(int x, int y) {
	int tx = Find(x), ty = Find(y);
	if(tx == ty) return;
	f[ty] = tx;
}

bool Check(int i) {
	for(int j = 1; j <= m; j++) if(F[j].x == G[i].x && F[j].y == G[i].y) return false;
	return true;
}

int main() {
	freopen("block.in", "r", stdin);
	freopen("block.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &Val[i]);
	for(int i = 1; i <= n; i++) {
		f[i] = i;
		int k;  scanf("%d", &k);
		for(int j = 1; j <= k; j++) { int x;  scanf("%d", &x);  G[++cur] = {i, x}; }
	}
	for(int i = 1; i <= m; i++) { int x, y;  scanf("%d %d", &x, &y);  F[i] = {x, y}; }
	
	for(int i = 1; i <= cur; i++) if(Check(i)) Merge(G[i].x, G[i].y);

	for(int i = 1; i <= n; i++) { Sum[f[i]] += Val[i];  ans = max(ans, Sum[f[i]]); }
	printf("%d", ans);
	return 0;
}
