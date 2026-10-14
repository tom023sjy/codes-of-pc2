#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
int a[N + 5], b[N + 5];
signed main() {
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
    cout << n << " ";
    for (int i = 1; i < n; i ++)
        cout << "0 ";
    return 0;
}