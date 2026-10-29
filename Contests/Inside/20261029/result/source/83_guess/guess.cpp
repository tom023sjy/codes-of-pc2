#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, m;
int gcd(int x, int y) {
	if (!y) return x;
	return gcd(y, x % y);
}
bool check(int x, int y) {
	for (int i = 1; i <= x; i++) {
	    int g = gcd(i, x);
	    if (g == 1) y -= i;
	    if (y < 0) return 0;
	}
	if (y == 0) return 1;
	else return 0;
}
signed main() {
	freopen("guess.in", "r", stdin);
	freopen("guess.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> m;
		for (int i = 401; i; i--) {
			if (check(i, m)) {
				cout << i << "\n";
				break;
			}
		}
	}
	return 0;
}
