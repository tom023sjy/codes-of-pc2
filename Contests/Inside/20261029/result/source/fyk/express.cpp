#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll inf = 1e15;
const int maxn = 1e6 + 10;
int n;
ll a[maxn], len, id[maxn];
struct node {
	ll val, id;
}P[maxn];
struct Tree {
	ll dat[maxn * 4];
	int L[maxn * 4], R[maxn * 4];
	ll tag[maxn * 4];
	void update(int p) {
		dat[p] = min(dat[p*2], dat[p*2+1]);
	}
	void spread(int p) {
		if (tag[p]) {
			tag[p*2] += tag[p]; tag[p*2+1] += tag[p];
			dat[p*2] += tag[p]; dat[p*2+1] += tag[p]; tag[p] = 0;
		}
	}
	void build(int p, int l, int r, int f) {
		L[p] = l; R[p] = r;
		if (l == r) {
			if (l == 1) dat[p] = 0;
			else dat[p] = inf; return;
		}
		int mid = (l + r) >> 1;;
		build(p*2, l, mid, f); build(p*2+1, mid+1, r, f);
		update(p); 
	}
	ll query(int p, int ql, int qr) {
		if (ql <= L[p] && R[p] <= qr) return dat[p];
		spread(p);
		int mid = (L[p] + R[p]) >> 1; ll x = inf;
		if (ql <= mid) {
			x = min(x, query(p*2, ql, qr));
		}
		if (qr > mid) {
			x = min(x, query(p*2+1, ql, qr));
		}
		update(p);
		return x; 
	}
	void add_all(int p, int l, int r, ll val) {
		if (l <= L[p] && R[p] <= r) {
			tag[p] += val; dat[p] += val; return;
		}
		spread(p);
		int mid = (L[p] + R[p]) >> 1;
		if (l <= mid) {
			add_all(p*2, l, r, val);
		}
		if (r > mid) {
			add_all(p*2+1, l, r, val);
		}
		update(p);
	}
	void change(int p, int pos, ll val) {
		if (L[p] == R[p] && L[p] == pos) {
			dat[p] = val; return;
		}
		spread(p);
		int mid = (L[p] + R[p]) >> 1;
		if (pos <= mid) {
			change(p*2, pos, val);
		}else {
			change(p*2+1, pos, val);
		}
		update(p);
 	}
}ori, add, cut;
bool cmp(node x, node y) {
	return x.val < y.val;
}
int main() {
	freopen("express.in", "r", stdin);
	freopen("express.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]); P[i].val = a[i]; P[i].id = i;
	}
	P[n+1].val = 0; P[n+1].id = 0;
	sort(P + 1, P + n + 2, cmp);
	for (int i = 1; i <= n+1; i++) id[P[i].id] = i;
	ll x;
	ori.build(1, 1, n+1, 0); cut.build(1, 1, n+1, -1); add.build(1, 1, n+1, 1);
	for (int i = 1; i <= n; i++) {
		x = min(cut.query(1, 1, id[i]) + a[i], add.query(1, id[i], n+1) - a[i]);
		ori.add_all(1, 1, n+1, abs(a[i] - a[i-1])); 
		cut.add_all(1, 1, n+1, abs(a[i] - a[i-1]));
		add.add_all(1, 1, n+1, abs(a[i] - a[i-1]));
		ori.change(1, id[i-1], x);
		cut.change(1, id[i-1], x - a[i-1]);
		add.change(1, id[i-1], x + a[i-1]);
	}
	printf("%lld", ori.query(1, 1, n));
	return 0;
}
