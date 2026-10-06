#include <bits/stdc++.h>
using namespace std;
#define int long long

// Config.ini
#define readf "three.in"
#define writf "three.out"

const int N = 5000;
int a[N + 5], b[4];

signed main() {
    freopen(readf, "r", stdin);
    freopen(writf, "w", stdout);
    int n, m;
    cin >> n >> m;
    if (m > 3)
        return puts("This program only support Subtask 1!!"), -1;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        b[a[i]] ++;
    if (b[1] % 3 == b[2] % 3 && b[2] % 3 == b[3] % 3)
        puts("1");
    else puts("0");
    return 0;
}