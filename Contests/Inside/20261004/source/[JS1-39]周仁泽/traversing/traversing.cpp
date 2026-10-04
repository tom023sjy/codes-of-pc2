// traversing Auther T_cat
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5 + 7;
const int MAXM = 5e3 + 1;
struct node{
	int t, l, r, x, id;
	bool operator < (const node &T)const {
		if (t == 1 && T.t == 1) {
			return l < T.l;
		}
		else return t < T.t;
	}
}w[MAXN];
int n, q, a, b, cnt, pos, m, p;
int d[MAXN], s[MAXN];
int id[MAXN], idx[MAXN];
int print[MAXN];
bool type_2 = 1, flag;
vector<int> val[MAXN];
void init(int x) {
	p++;
	id[p] = x;
	idx[x] = p;
	if (d[x] == -1) {
		pos++;
		s[x] = pos;
		for (auto u : val[x]) {
			if (u == 0) continue;
			init(u);
		}
	} else if (d[x] == 0) {
		if (val[x][0] != 0) init(val[x][0]);
		pos++;
		s[x] = pos;
		if (val[x][2] != 0) init(val[x][1]);
	} else if(d[x] == 1) {
		for (auto u : val[x]) {
			if (u == 0) continue;
			init(u);
		}
		pos++;
		s[x] = pos;
	}
	return;
}
void solve1() {
	pos = 0;
	init(1);
	for (int i = 1; i <= q; i++) {
		if (w[i].t == 1) {
			for (int j = w[i].l; j <= w[i].r; j++) d[j] = w[i].x;
			pos = 0;
			init(1);
		} else if (w[i].t == 2) cout << s[w[i].x] << endl;
	}
	return;
}
void solve2() {
	sort(w + 1, w + q + 1);
	for (int i = 1; i <= q; i++) {
		if (w[i].t == 2) {
			m = i - 1;
			break;
		}
	}
	for (int i = 1; i < m; i++) {
		for (int j = w[i].l; j < w[i + 1].l; j++) d[j] = w[i].x;
	}
	for (int i = w[m].l; i <= w[m].r; i++) d[i] = w[m].x;
	pos = 0;
	init(1);
	for (int i = m + 1; i <= q; i++) {
		if (w[i].t == 1) continue;
		print[w[i].id] = s[w[i].x];
	}
	for (int i = 1; i <= q; i++) {
		if (print[i] == 0) continue;
		cout << print[i] << endl;
	}
	return;
}
signed main() {
	freopen("traversing.in", "r", stdin);
	freopen("traversing.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		val[i].push_back(a);
		val[i].push_back(b);
		d[i] = -1;
	}
	for (int i = 1; i <= q; i++) {
		cin >> w[i].t;
		if (w[i].t == 1) {
			cnt++;
			cin >> w[i].l >> w[i].r >> w[i].x;
			if (flag) type_2 = 0;
		}
		else {
			cin >> w[i].x;
			flag = 1;
		}
		w[i].id = i;
	}
	if ((n <= MAXM && q <= MAXM) || cnt <= 10) solve1();
	else if (type_2) solve2();
	return 0;
}
