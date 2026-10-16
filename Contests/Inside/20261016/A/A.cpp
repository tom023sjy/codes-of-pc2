#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100;
int a[N + 5];
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int x = a[n] - a[1];
    if (x % 2 == 0) {
        int wants = x / 2;
        cout << wants;
        return 0;
    }
    int wants = x / 2 + 1;
    cout << wants;
    return 0;
}