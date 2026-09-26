#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3;
int a[N + 5], t[N + 5], n, m, d;
int lowbit(int x) {
	return x & -x;
}
void update(int p, int d) {
	for (; p <= N; p += lowbit(p))
		t[p] += d;
}
int query(int p) {
	int sum = 0;
	for (; p; p -= lowbit(p))
		sum += t[p];
	return sum;
}
inline string solve(int x, int y) {
	a[x] += y;
	for (int l = 0; l < n; l ++) {
		int lhs = 0;
		for (int r = l; r <= n; r ++) {
			lhs += a[r];
			if (lhs > (r - l + 1 + d) * m)
				return "NO";
		}
	}
	return "YES";
}
signed main() {
    freopen("hire.in", "r", stdin);
	freopen("hire.out", "w", stdout);
	int T;
	cin >> n >> T >> m >> d;
	while (T --) {
		int x, y;
		cin >> x >> y;
		cout << solve(x, y) << endl;
	}
	return 0;
}

