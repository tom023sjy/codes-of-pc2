#include <iostream>
#include <cstring>
#define int long long
#define F(i, st, ed) for (int i = st; i <= ed; i++)
using namespace std;

const int N = 5e5 + 5;
int n, m, k, d;
int a[N], b[N], has[N];

inline void print() {
	cout << '\n';
	F(i, 1, n - d) cout << b[i] << ' ' << has[i] << '\n';
	cout << '\n';
	return ;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k >> d;
	freopen("hire.in", "r", stdin);
	freopen("hire.out", "w", stdout);
	while (m--) {
		memset(has, 0, sizeof has);
		int x, y, pos = 1;
		cin >> x >> y, a[x] += y;
		F(i, 1, n - d) b[i] = a[i];
		F(i, 1, n - d) {
			while (b[i] && pos <= i + d) {
				if (b[i] >= k - has[pos]) {
					b[i] -= k - has[pos];
					has[pos] = k;
					pos++;
				} else has[pos] += b[i], b[i] = 0;
			}
			//print();
		}
		int fl = 1;
		F(i, 1, n - d) {
			if (!b[i]) continue ;
			fl = 0;
			break ;
		}
		cout << (fl ? "YES\n" : "NO\n");
	}
	return 0;
}
