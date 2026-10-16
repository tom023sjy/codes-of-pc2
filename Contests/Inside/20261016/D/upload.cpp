#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5000;
int a[N + 5], l[N + 5], r[N + 5];
signed main() {
    int n, m, val;
    cin >> n >> m >> val;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= m; i ++)
        cin >> l[i] >> r[i];
    int cnt = 0;
    for (int k = 1; k <= val; k ++) {
        bool valid = 1;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++) 
                if (l[j] <= (a[i] + k) && (a[i] + k) <= r[j])
                    valid = 0;
        cnt += valid;
    }
    cout << cnt;
    return 0;
}