#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3000;
int dp[N + 5][N + 5];
signed main() {
	int T;
	cin >> T;
	while (T --) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		memset(dp, 0x3f, sizeof dp);
		dp[0][0] = 0;
		for (int i = 0; i <= a; i ++)
			for (int j = 0; j <= b; j ++) {
				if (!i && !j) continue;
				if (i && j) 
					dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + x);
				if (i > 1)
					dp[i][j] = min(dp[i][j], dp[i - 2][j] + x);
				if (j > 1)
					dp[i][j] = min(dp[i][j], dp[i][j - 2] + x);
			}
		int minn = 9e18;
		for (int i = 0; i <= b; i ++)
			minn = min(minn, dp[a][i]);
		for (int i = 0; i <= a; i ++)
			minn = min(minn, dp[i][b]);
		cout << minn << endl;
	}
	return 0;
}
 