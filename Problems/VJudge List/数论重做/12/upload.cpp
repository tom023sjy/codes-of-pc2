#include <bits/stdc++.h>
using namespace std;
#define int long long
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
int lucas(int n, int m, int p) {
    if (m == 0) return 1;
    return lucas(n / p, m / p, p) * getc(n % p, m % p, p) % p;
}
signed main() {
    int T;
    cin >> T;
    while (T --) {
        int n, m, p;
        cin >> n >> m >> p;
        cout << lucas(m + n, n, p) << endl;
    }
    return 0;
}
