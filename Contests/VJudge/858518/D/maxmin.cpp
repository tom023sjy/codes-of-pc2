#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int a[N + 5], b[N + 5];
signed main() {
    freopen("maxmin.in", "r", stdin);
    freopen("maxmin.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        cin >> b[i];
    bool flg = 1;
    for (int i = 1; i <= n; i ++)
        if (a[i] != b[i])
            flg = 0;
    if (flg) {
        cout << n << " ";
        for (int i = 1; i < n; i ++)
            cout << "0 ";
        return 0;
    }
    cout << "Error!";
    return 0;
}