#include <iostream>
#include <cstring>
#define int long long
#define F(i, st, ed) for (int i = st; i <= ed; i++)
using namespace std;

const int N = 5e2 + 5;
const int M = 2e6 + 5;
int n, ans, a[N];
bool fl[M];
char op;

inline void check(int x) {
	fl[x] = 1, ans++;
	F(i, 1, n) if (a[i] == 1) {
		if (i > 2) {
			if (a[i - 1] == 1 && a[i - 2] == 0) {
				a[i] = 0, a[i - 2] = 1;
				int y = x;
				y -= (1 << (i - 1));
				y += (1 << (i - 3));
				if (!fl[y]) check(y);
				a[i] = 1, a[i - 2] = 0;
			}
		}
		if (i < n - 1) {
			if (a[i + 1] == 1 && a[i + 2] == 0) {
				a[i] = 0, a[i + 2] = 1;
				int y = x;
				y -= (1 << (i - 1));
				y += (1 << (i + 1));
				if (!fl[y]) check(y);
				a[i] = 1, a[i + 2] = 0;
			}
		}
	}
	return;
}

inline void dfs(int x) {
	if (x > n) {
		int stt = 0, p = 1;
		F(i, 1, n) stt += (a[i] * p), p <<= 1;
		memset(fl, 0, sizeof fl), check(stt);
		return ;
	}
	if (a[x] == -1) {
		a[x] = 0, dfs(x + 1);
		a[x] = 1, dfs(x + 1);
		a[x] = -1;
	} else dfs(x + 1);
	return ;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("jump.in", "r", stdin);
	freopen("jump.out", "w", stdout);
	cin >> n;
	F(i, 1, n) {
		cin >> op;
		if (op == '?') a[i] = -1;
		else a[i] = op - '0';
	}
	dfs(1), cout << ans;
	return 0;
}
