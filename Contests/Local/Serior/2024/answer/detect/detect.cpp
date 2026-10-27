#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 1e5;
int a[N + 5], d[N + 5], v[N + 5], p[N + 5];
void solve() {
	int n, m, s, l;
	cin >> n >> m >> s >> l;
	vector<pii> dict;
	for (int i = 1; i <= n; i ++)
		cin >> d[i] >> v[i] >> a[i];
	for (int i = 1; i <= m; i ++)
		cin >> p[i];
	for (int i = 1; i <= n; i ++) {
		int ql, qr;
		if (a[i] > 0) {
			if (v[i] > l) ql = d[i], qr = s;
			else ql = d[i] + (l * l - v[i] * v[i]) / (2 * a[i]) + 1,
				 qr = s;
		}
		else if (a[i] < 0) {
			if (v[i] > l)
				ql = d[i],
				qr = d[i] + (v[i] * v[i] - l * l - 1) / (-2 * a[i]);
			else continue;
		}
		else {
			if (v[i] > l) ql = d[i], qr = s;
			else continue;
		}
		int st, ed;
		st = lower_bound(p + 1, p + m + 1, ql) - p;
		ed = upper_bound(p + 1, p + m + 1, qr) - p - 1;
		if (st <= ed) 
			dict.emplace_back(st, ed);
	}
	sort(dict.begin(), dict.end(), [](pii x, pii y) {
		return x.second < y.second;
	});
	int lst = 0, ans = 0;
	for (auto kv : dict)
		if (lst < kv.first)
			ans ++, lst = kv.second;
	cout << dict.size() << " " << m - ans << endl;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T --)
    	solve();
    return 0;
}
