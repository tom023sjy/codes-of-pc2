#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, q, dfn[100010], tp[100010], timer, sz[100010];

class Pair {
public: ll l, r;
};

Pair son[100010];

void dfs0(ll x) {
	if (tp[x] == -1) dfn[x] = ++timer;
	if (son[x].l) dfs0(son[x].l);
	if (tp[x] == 0) dfn[x] = ++timer;
	if (son[x].r) dfs0(son[x].r);
	if (tp[x] == 1) dfn[x] = ++timer;
}

void dfs(ll x, ll f) {
	sz[x] = sz[f] + 1;
	dfn[x] = ++timer;
	if (son[x].l) dfs(son[x].l, x);
	if (son[x].r) dfs(son[x].r, x);
}

#define MAXN 100010

class SegmentTree {
	ll sum[MAXN << 2] = {}, add[MAXN << 2] = {};
	
	static ll L(ll p) { 
		return p << 1;
	}
	static ll R(ll p) {
		return p << 1 | 1;
	}
	
	void change(ll p, ll len, ll v) {
		sum[p] += v * len;
		add[p] += v;
	}
	
	void push_down(ll p, ll l, ll r) {
		if (add[p] == 0) return;
		ll mid = (l + r) >> 1;
		change(L(p), mid - l + 1, add[p]), change(R(p), r - mid, add[p]);
		add[p] = 0;
	}
	
	void push_up(ll p) {
		sum[p] = sum[L(p)] + sum[R(p)];
	}
	
public: 
	void build(ll p, ll l, ll r) {
		if (l == r) {
			sum[p] = l;
			return;
		}
		ll mid = (l + r) >> 1;
		build(L(p), l, mid), build(R(p), mid + 1, r);
		push_up(p);
	}
	
	void modify(ll p, ll l, ll r, ll ql, ll qr, ll v) {
		if (ql <= l && r <= qr) {
			change(p, r - l + 1, v);
			return;
		}
		push_down(p, l, r);
		ll mid = (l + r) >> 1;
		if (ql <= mid) modify(L(p), l, mid, ql, qr, v);
		if (qr > mid) modify(R(p), mid + 1, r, ql, qr, v);
		push_up(p);
	}
	
	ll query(ll p, ll l, ll r, ll pos) {
		if (l == r) return sum[p];
		push_down(p, l, r);
		ll mid = (l + r) >> 1;
		if (pos <= mid) return query(L(p), l, mid, pos);
		return query(R(p), mid + 1, r, pos);
	}
};

SegmentTree st = {};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	freopen("traversing.in", "r", stdin);
	freopen("traversing.out", "w", stdout);

	cin >> n >> q;
	
	for (ll i = 1; i <= n; i++) cin >> son[i].l >> son[i].r, tp[i] = -1;
	
	if (q <= 5000) {
		while (q--) {
			ll op, l, r, x; cin >> op;
			if (op == 1) {
				cin >> l >> r >> x;
				for (ll i = l; i <= r; i++) tp[i] = x;
			} else {
				cin >> x;
				timer = 0;
				dfs0(1);
				cout << dfn[x] << '\n';
			}
		}
	} else {
		dfs(1, 0);
		st.build(1, 1, n);
		while (q--) {
			ll op, l, r, x; cin >> op;
			if (op == 1) {
				cin >> l >> r >> x;
				for (ll i = l; i <= r; i++) {
					ll old = tp[i];
					if (old == -1 && x == 1) {
						st.modify(1, 1, n, dfn[i], dfn[i], sz[i]);
						st.modify(1, 1, n, dfn[i] + 1, dfn[i] + sz[i] - 1, -1);
					} 
					if (old == -1 && x == 0) {
						ll ls = son[i].l;
						if (ls != 0) st.modify(1, 1, n, dfn[i], dfn[i], sz[ls]), st.modify(1, 1, n, dfn[ls], dfn[ls] + sz[ls] - 1, -1);
					}
					if (old == 0 && x == -1) {
						ll ls = son[i].l;
						if (ls != 0) st.modify(1, 1, n, dfn[i], dfn[i], -sz[ls]), st.modify(1, 1, n, dfn[ls], dfn[ls] + sz[ls] - 1, 1);
					}
					if (old == 0 && x == 1) {
						ll rs = son[i].r;
						if (rs != 0) st.modify(1, 1, n, dfn[i], dfn[i], sz[rs]), st.modify(1, 1, n, dfn[rs], dfn[rs] + sz[rs] - 1, -1);
					}
					if (old == 1 && x == -1) {
						st.modify(1, 1, n, dfn[i], dfn[i], -sz[i]);
						st.modify(1, 1, n, dfn[i] + 1, dfn[i] + sz[i] - 1, 1);
					}
					if (old == 1 && x == 0) {
						ll rs = son[i].r;
						if (rs != 0) st.modify(1, 1, n, dfn[i], dfn[i], -sz[rs]), st.modify(1, 1, n, dfn[rs], dfn[rs] + sz[rs] - 1, 1);
					}
				}
			} else {
				cin >> x;
				cout << st.query(1, 1, n, dfn[x]) << '\n';
			}
			for (ll i = 1; i <= n; i++) cout << st.query(1, 1, n, dfn[i]) << ' ';
			cout << '\n';
		}
	}

	return 0;
}


