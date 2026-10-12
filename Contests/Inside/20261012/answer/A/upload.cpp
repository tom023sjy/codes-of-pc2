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
		int minn = 9e18;
		for (int i = 0; i <= min(a, b); i ++)
			if (!(a - i & 1))
				minn = min(minn, i * y + (a - i) / 2 * x);
		for (int i = 0; i <= min(a, b); i ++)
			if (!(b - i & 1))
				minn = min(minn, i * y + (b - i) / 2 * x);
		cout << minn << endl;
	}
	return 0;
}
 