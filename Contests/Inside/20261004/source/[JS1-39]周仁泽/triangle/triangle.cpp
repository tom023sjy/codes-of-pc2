// triangle Auther T_cat
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e1 + 7;
const int INF = 0x3f3f3f3f;
int n, ans = INF, pos, cnt;
int a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN], f[MAXN][MAXN];
void solve() {
	int tmp = 0;
	for (int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			if (c[i][j] != b[i][j]) tmp++;
		}
	}
	ans = min(ans, tmp);
	return;
}
void f1() {
	pos = 1, cnt = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = n, j = k; j >= 1; i--, j--) {
			cnt++;
			if (cnt > pos) {
				pos++;
				cnt = 1;
			}
			f[pos][cnt] = c[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) c[i][j] = f[i][j];
	}
	return;
}
void f2() {
	pos = 1, cnt = 0;
	for (int k = n; k >= 1; k--) {
		for (int i = k; i <= n; i++) {
			cnt++;
			if (cnt > pos) {
				pos++;
				cnt = 1;
			}
			f[pos][cnt] = c[i][k];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) c[i][j] = f[i][j];
	}
	return;
}
void d() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			f[i][j] = c[i][i - j + 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) c[i][j] = f[i][j];
	}
	return;
}
void q() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1 ;j <= i; j++) c[i][j] = a[i][j];
	}
	return;
}
signed main() {
	freopen("triangle.in", "r", stdin);
	freopen("triangle.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
			c[i][j] = a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) cin >> b[i][j];
	}
	solve(), d(), solve(), q();
	f1(), solve(), d(), solve(), q();
	f2(), solve(), d(), solve(), q();
	cout << ans << "\n";
	return 0;
}
