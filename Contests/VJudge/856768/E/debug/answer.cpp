#include <bits/stdc++.h>
#define pb emplace_back
#define fst first
#define scd second
#define mkp make_pair
#define mems(a, x) memset((a), (x), sizeof(a))
using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
typedef long double ldb;
typedef pair<ll, ll> pii;
void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	if (m * 2 > n) {
		for (int i = 1; i <= n; ++i) {
			int x = i;
			if (i == m) {
				x = n;
			} else if (i > m) {
				--x;
			}
			printf("%d%c", x, " \n"[i == n]);
		}
	} else {
		while (n % m) {
			--m;
		}
		for (int i = 1; i <= n; ++i) {
			int t = i;
			if (i > m && (i - 1) % m == 0) {
				t += m - 1;
			} else if (i > m) {
				--t;
			}
			printf("%d%c", t, " \n"[i == n]);
		}
	}
}
int main() {
	int T = 1;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
