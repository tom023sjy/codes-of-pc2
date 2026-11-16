#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int a[N + 5], b[N + 5];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) b[i] = i;
    for (int i = 1; i <= n; i ++) cout << i << ",";
    cout << endl;
    while (m --) {
        for (int i = 1, j = 0; i <= n / 2; i ++)
            a[++ j] = b[n / 2 + i], a[++ j] = b[i];
        memcpy(b, a, sizeof a);
        for (int i = 1; i <= n; i ++) cout << b[i] << ",";
        cout << endl;
    } 
}
