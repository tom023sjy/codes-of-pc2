#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3;
int a[N + 5], n, m, d;
inline string solve(int x, int y) {
	a[x] += y;
	int sum = 0, maxn = 0;
	for (int i = 1; i <= n; i ++)
		if (a[i] > 0) sum += a[i];
		else maxn = max(maxn, sum);
	maxn = max(maxn, sum);
	if (maxn > d * m) return "NO";
	return "YES";
}
signed main() {
    freopen("hire.in", "r", stdin);
	freopen("hire.out", "w", stdout);
	int T;
	cin >> n >> T >> m >> d;
	fill(a, a + n + 1, -m);
	while (T --) {
		int x, y;
		cin >> x >> y;
		cout << solve(x, y) << endl;
	}
	return 0;
}

