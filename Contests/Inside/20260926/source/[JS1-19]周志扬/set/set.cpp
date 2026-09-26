#include <bits/stdc++.h>
#define int long long
using namespace std;

const int Mod = 998244353;

signed main() {
	freopen("set.in", "r", stdin);
	freopen("set.out", "w", stdout);
	
	int n, ans = 1;  scanf("%lld", &n);
	for(int S = 1; S < (1 << n); S++) {
		int sum = 0;
		for(int i = 0; i < n; i++) if(S & (1 << i)) sum += i + 1;
		ans = ans * sum % Mod;
	}
	printf("%lld", ans);
	return 0;
}
