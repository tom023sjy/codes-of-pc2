#include<bits/stdc++.h>
using namespace std;
int n, m, t;
int a[1010][1010];
void change(int x, int y) {
	int l = 1, r = m, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (a[x][mid] <= y) {
			ans = mid; l = mid + 1;
		}else {
			r = mid - 1;
		}
	}
	a[x][ans] = y;
}
int find(int x, int y, int k) {
	// x y k min
	int lx = 1, rx = m, ly = 1, ry = m;
	while(lx <= rx && ly <= ry) {
		int midx = (lx + rx) >> 1;
		int midy = (ly + ry) >> 1;
		if (a[x][midx] <= a[y][midy]) {
			if (midx + midy <= k) lx = midx + 1;
			else ry = midy - 1;
		}else {
			if (midx + midy <= k) ly = midy + 1;
			else rx = midx - 1;
		}
	}
	if (lx > rx) {
		if (lx == 1) return a[y][k];
		return max(a[x][lx-1], a[y][k-lx+1]);
	}else {
		if (ly == 1) return a[x][k];
		return max(a[y][ly-1], a[x][k-ly+1]);
	}
}
int main() {
	freopen("familiar.in", "r", stdin);
	freopen("familiar.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= t; i++) {
		int op, x, y; 
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1) {
			int k; scanf("%d", &k);
			printf("%d\n", find(x, y, 2 * m - k + 1));
		}else {
			change(x, y);
		}
	}
	return 0;
}
