#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int n, a[N][N], b[N][N], c[N][N], ans = 0, sum;

int main () {
	freopen ("triangle.in", "r", stdin);
	freopen ("triangle.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= i; j ++) cin >> a[i][j];
		
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= i; j ++) {
			cin >> b[i][j];
			if (b[i][j] != a[i][j]) ans ++;
		}
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= i; j ++)
			if (a[n - j + 1][n - j + 1 - (n - i)] != b[i][j]) 
				sum ++;
	}
	ans = min (ans, sum);
	sum = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= i; j ++)
			if (a[n - i + j][n - i + 1] != b[i][j])
				sum ++;
	ans = min (ans, sum);
	sum = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= i / 2; j ++)
			swap (a[i][j], a[i][i - j + 1]);
			
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= i; j ++) {
			if (b[i][j] != a[i][j]) sum ++;
		}
	ans = min (ans, sum);
	sum = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= i; j ++)
			if (a[n - j + 1][n - j + 1 - (n - i)] != b[i][j]) 
				sum ++;
	}
	ans = min (ans, sum);
	sum = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= i; j ++)
			if (a[n - i + j][n - i + 1] != b[i][j])
				sum ++;
	ans = min (ans, sum);
	cout << ans;
	
	return 0;
}
