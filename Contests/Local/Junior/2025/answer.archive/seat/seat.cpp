#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
const int N = 10;
pii a[N + 5];
bool cmp(pii x, pii y) {
    return x.first > y.first;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i ++)
        cin >> a[i].first, a[i].second = i;
    sort(a + 1, a + n * m + 1, cmp);
    int pos = 0;
    while (a[pos].second != 1)
		pos ++;
    // 分组
    int col = (pos + n - 1) / n, lne = pos % (n * 2);
    if (lne == 0) lne = n * 2;
    if (lne > n) lne = (n * 2 + 1) - lne;
    cout << col << " " << lne << endl;
    // cout << pos;
    return 0;
}