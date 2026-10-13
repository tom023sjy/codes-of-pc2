#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5 + 7;
int t, n, m, pos;
int a[MAXN], b[MAXN];
bool flag, ok;  
signed main() {
	freopen("minmax.in", "r", stdin);
	freopen("minmax.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		pos = 0, ok = 1;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= m; i++) cin >> b[i];
		if (m > n) {
			cout << "No" << "\n";
			continue;
		}
		for (int i = 1; i <= m; i++) {
			flag = 0;
			while (pos <= n) {
				pos++;
				if (a[pos] == b[i]) {
					flag = 1;
					break;
				}
			}
			if (!flag) {
				ok = 0;
				break;
			}
		}
		if (ok) cout << "Yes" << "\n";
		else cout << "No" << "\n";
	}
	return 0;
}
