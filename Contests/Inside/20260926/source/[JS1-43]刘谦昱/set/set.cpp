#include <iostream>
#define int long long
#define FOR(i, st, ed) for (int i = st; i <= ed; i++)
#define ROF(i, st, ed) for (int i = st; i >= ed; i--)
using namespace std;

const int N = 2e2 + 5;
const int MOD = 998244353;
int n, sum, ans = 1;
unsigned __int128 p[N * (N + 1) / 2] = {1};

inline int qpow(int a, int b, int mod = MOD) {
	int res = 1;
	a %= mod;
	while (b) {
		if (b & 1) res = (res * a) % mod;
		a = (a * a) % mod, b >>= 1;
	}
	return res;
}

inline void print() {
	//FOR(i, 1, sum) cout << p[sum] << '\n';
	return ;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("set.in", "r", stdin);
	freopen("set.out", "w", stdout);
	cin >> n;
	FOR(i, 1, n) {
		ROF(j, sum, 0) p[i + j] += p[j];
		sum += i;
	}
	FOR(i, 1, sum) ans = ans * qpow(i, p[i]) % MOD;
	cout << ans;
	return 0;
}
