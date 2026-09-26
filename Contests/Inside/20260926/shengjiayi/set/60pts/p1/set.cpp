#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;

int ans, n;

void dfs(int id, int sum) {
	if (id > n) {
		if (sum) ans *= sum;
		ans %= mod;
		return ;
	}
	dfs(id + 1, sum);
	dfs(id + 1, sum + id);
}
signed main() {
    freopen("set.in", "r", stdin);
	freopen("set.out", "w", stdout);
	cin >> n;
	ans = 1;
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}

