#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5 + 7;
int n, a, b;
bool type = 1;
signed main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		if (a != i || b != i + 1) type = 0;
	}
	if (type) {
		cout << 1 << "\n";
		return 0;
	}
	return 0;
} 
