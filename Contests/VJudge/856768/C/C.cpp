#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int solve(int p, int q) {
    if (p == q) return 0;
    if (q % p) return -1;
    int cnt = 0;
	while (p != q) {
        if (__gcd(p, q / p) == 1) return -1;
        p = p * __gcd(p, q / p);
        cnt ++;
    }
    return cnt;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T --) {
		int p, q;
		cin >> p >> q;
		cout << solve(p, q) << endl;
	}
	return 0;
}