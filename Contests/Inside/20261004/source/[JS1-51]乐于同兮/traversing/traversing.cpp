#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, q, dep[N], f[N][25], sz[N];
struct Node {
	int ls, rs, val;
} a[N << 2];
int tag[N << 2];

void pd (int p) {
	if (tag[p] != 9178) {
		tag[p << 1] = tag[p << 1 | 1] = tag[p];
		tag[p] = 9178;
	}
}

void pu (int p) {
	if (tag[p << 1] == tag[p << 1 | 1]) tag[p] = tag[p << 1];
	else tag[p] = 9178;
}

void build (int p, int l, int r) {
	if (l == r) {
		tag[p] = -1;
		return;
	}
	int mid = (l + r) >> 1;
	build (p << 1, l, mid);
	build (p << 1 | 1, mid + 1, r);
	pu (p);
}

void upd (int p, int L, int R, int l, int r, int k) {
	if (r < L || R < l) return;
	if (tag[p] == k) return;
	if (l <= L && R <= r) {
		tag[p] = k;
		return;
	}
	pd (p);
	int mid = (L + R) >> 1;
	if (l <= mid) upd (p << 1, L, mid, l, r, k);
	if (r > mid) upd (p << 1 | 1, mid + 1, R, l, r, k);
	pu (p);
}

int qry (int p, int l, int r, int x) {
	if (tag[p] != 9178) return tag[p];
	if (l == r) return tag[p];
	int mid = (l + r) >> 1;
	if (x <= mid) return qry (p << 1, l, mid, x);
	else return qry (p << 1 | 1, mid + 1, r, x);
}

void dfs (int x, int fa) {
	sz[x] = 1;
	dep[x] = dep[fa] + 1;
	f[x][0] = fa;
	for (int i = 1; i <= 19; i ++)
		f[x][i] = f[f[x][i - 1]][i - 1];
	if (a[x].ls) {dfs (a[x].ls, x); sz[x] += sz[a[x].ls];}
	if (a[x].rs) {dfs (a[x].rs, x); sz[x] += sz[a[x].rs];}
}

int LCA (int x, int y) {
	if (x == 0 || y == 0) return -1;
	if (dep[x] < dep[y]) swap (x, y);
	if (dep[x] != dep[y]) 
		for (int i = 19; i >= 0; i --)
			if (dep[f[x][i]] >= dep[y]) x = f[x][i];
	if (x == y) return x;
	for (int i = 19; i >= 0; i --) {
		int xx = f[x][i];
		int yy = f[y][i];
		if (xx == yy) continue;
		x = xx;
		y = yy; 
	}
	return f[x][0];
}

int zrx (int p, int x) {
	int val = qry (1, 1, n, p);
	if (p == x) {
		if (val == -1) return 1;
		if (val == 0) return sz[a[p].ls] + 1;
		if (val == 1) return sz[p];
	}
	if (a[p].ls && LCA (x, a[p].ls) == a[p].ls) {
		if (val == -1) return 1 + zrx (a[p].ls, x);
		if (val == 0) return zrx (a[p].ls, x);
		if (val == 1) return zrx (a[p].ls, x);
	}
	if (a[p].rs && LCA (x, a[p].rs) == a[p].rs) {
		if (val == -1) return 1 + sz[a[p].ls] + zrx (a[p].rs, x);
		if (val == 0) return sz[a[p].ls] + 1 + zrx (a[p].rs, x);
		if (val == 1) return sz[a[p].ls] + zrx (a[p].rs, x);
	}
}

int main () {
	freopen ("traversing.in", "r", stdin);
	freopen ("traversing.out", "w", stdout);

	scanf ("%d%d", &n, &q);
	for (int i = 1; i <= n; i ++) {
		scanf ("%d%d", &a[i].ls, &a[i].rs);
	}
	build (1, 1, n);
	dfs (1, 0);
	
	while (q --) {
		int op;
		scanf ("%d", &op);
		if (op == 1) {
			int l, r, x;
			scanf ("%d%d%d", &l, &r, &x);
			upd (1, 1, n, l, r, x);
		}
		if (op == 2) {
			int x;
			scanf ("%d", &x);
			printf ("%d\n", zrx (1, x));
		}
	}
	return 0;
}
