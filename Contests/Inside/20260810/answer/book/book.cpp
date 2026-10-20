#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N + 5];
int n, m, p, q;
inline int f(int j) {
    int tme = q * j, sum = 0;
    for (int i = j; i >= 1; i --) 
        if (tme + p - q <= m)
            tme += p - q, sum += a[i];
    return sum;
}
signed main() {
    freopen("book.in", "r", stdin);
    freopen("book.out", "w", stdout);
    cin >> n >> m >> p >> q;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    
    return 0;
}