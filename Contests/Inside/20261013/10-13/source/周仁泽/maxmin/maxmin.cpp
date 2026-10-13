#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN =5e5 + 7;
const int MAXM = 3e2 + 7;
const int MAXK = 5e3 +7;
const int INF = 0x3f3f3f3f;
int n;
int a[MAXN], b[MAXN], ans[MAXM];
int idx[MAXK], mmin[MAXK][MAXK], mmax[MAXK][MAXK], e[MAXK][MAXK];
int dp[MAXM][MAXM][MAXM];
bool type1 = 1;
void solve() {
	for (int i = 0; i < MAXK; i++) {
		for (int j = 0; j < MAXK; j++) {
			mmin[i][j] = INF;
			mmax[i][j] = -1;
		}
	} 
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			mmin[i][j] = mmin[i][j - 1];
			mmax[i][j] = mmax[i][j - 1]; 
			if (b[j] > b[i]) {
				mmin[i][j] = min(a[j], mmin[i][j]);
				e[i][j] = 1;
			} else {
				mmax[i][j] = max(a[j], mmax[i][j]);
				e[i][j] = -1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int end;
		int pw = a[i], Min = INF, Max = -1;
		for (int j = i + 1; j <= n ; j++) {
			if (a[j] > pw) Min = min(Min, a[j]);
			else Max = max(Max, a[j]);
			if (j == n) {
				if (a[j] > pw) end = 1;
				else end = -1;
			} 
		}
		for (int j = 1; j <= i; j++) {
			int gmin = mmin[j][i];
			int gmax = mmax[j][i];
			int E = e[j][i], nxt;
			if (E == 1) {
				nxt = min(a[i], gmin);
			} else nxt = max(a[i], gmax);
			if (nxt != a[i]) continue;
			int z;
			if (end == 1) z = min(b[j], Min);
			else z = max(b[j], Max);
			ans[abs(z - a[i])]++;
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << "\n";
	return;
}
void solve2() {
	dp[1][a[1]][b[1]] = 1;
	for (int i = 1; i < n; i++) {
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= n; y++) {
				int i1 = min(x, a[i + 1]);
				int j1 = min(y, b[i + 1]);
				int i2 = max(x, a[i + 1]);
				int j2 = max(y, b[i + 1]);
				if (dp[i][x][y]) {
					dp[i + 1][i1][j1] = 1;
					dp[i + 1][i2][j2] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			ans[abs(i - j)] += dp[n][i][j];
	}
	for (int i = 0; i < n; i++) cout << ans[i] << " ";
	return;
}
signed main() {
	freopen("maxmin.in", "r", stdin);
	freopen("maxmin.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		if (a[i] != b[i]) type1 = 0;
	}
	if (type1) {
		cout << n << " ";
		for (int i = 2; i <= n; i++) cout << 0 << " ";
	} else if (n <= 300) solve2();
	else solve();
	return 0;
}
