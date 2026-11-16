#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6, mod = 1e9 + 7;
int c[N + 5];
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
int getc(int n, int m, int p) {
    if (n < m) return 0;
    if (m > n - m) m = n - m;
    int m1 = 1, m2 = 1;
    for (int i = 0; i < m; i ++)
        m1 *= (n - i), m1 %= p,
        m2 *= (i + 1), m2 %= p;
    return m1 * fp(m2, p - 2, p) % p;
}
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
        cin >> c[i], n -= c[i];
    // 答案：C(n - 1, m - 1)
    cout << getc(n - 1, m - 1, mod);
    return 0;
}
