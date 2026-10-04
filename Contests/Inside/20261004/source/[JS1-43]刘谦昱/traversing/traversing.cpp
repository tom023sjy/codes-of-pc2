#include <iostream>
#define int long long
#define F(i, st, ed) for (int i = st; i <= ed; i++)
using namespace std;

const int N = 1e5 + 5;

int n, q, tot, root;
int ls[N], rs[N];
int a[N],b[N];
bool rt[N];

inline void update(int u) {
	if (u == 0) return ;
	if (a[u] == -1) b[u] = ++tot, update(ls[u]), update(rs[u]);
	if (a[u] == 0) update(ls[u]), b[u] = ++tot, update(rs[u]);
	if (a[u] == 1) update(ls[u]), update(rs[u]), b[u] = ++tot;
	return ;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("traversing.in", "r", stdin);
	freopen("traversing.out", "w", stdout);
	cin >> n >> q;
	F(i, 1, n) cin >> ls[i] >> rs[i], a[i] = -1;
	F(i, 1, n) rt[ls[i]] = rt[rs[i]] = 1;
	F(i, 1, n) if (!rt[i]) root = i;
	while (q--) {
		int op, l, r, id, x;
		cin >> op;
		if (op == 1) {
			cin >> l >> r >> x;
			F(i, l, r) a[i] = x;
		} else {
			tot = 0;
			update(root);
			cin >> id;
			cout << b[id] << '\n';
		}
	}
	return 0;
}
