#include <bits/stdc++.h>
using namespace std;

int n, a[15][15], b[15][15], t[15][15];

void R(int x[15][15]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			t[i][j] = x[n + 1 - j][i + 1 - j];
		}
	}
	return ;
}

void F(int x[15][15]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			t[i][j] = x[i][i + 1 - j];
		}
	}
	return ;
}

int C(int x[15][15]) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cnt += (b[i][j] != x[i][j]);
		}
	}
	return cnt;
}

int main() {
	freopen("triangle.in", "r", stdin);
	freopen("triangle.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> b[i][j];
		}
	}
	int ans = C(a);
	R(a);
	ans = min(ans, C(t));
	R(t);
	ans = min(ans, C(t));
	R(a); F(t);
	ans = min(ans, C(t));
	R(a); R(t); F(t);
	ans = min(ans, C(t));
	F(a);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			a[i][j] = t[i][j];
		}
	}
	ans = min(ans, C(a));
	R(a);
	ans = min(ans, C(t));
	R(t);
	ans = min(ans, C(t));
	R(a); F(t);
	ans = min(ans, C(t));
	R(a); R(t); F(t);
	ans = min(ans, C(t));
	cout << ans;
	return 0;
}
/*     1
1     0 2
2    0 0 3
3   0 0 0 4
4  0 0 0 0 5
5 0 0 0 0 0
i = 4
j = 1 2 3 4
yi= 5 4 3 2
yj= 4 3 2 1
*/
