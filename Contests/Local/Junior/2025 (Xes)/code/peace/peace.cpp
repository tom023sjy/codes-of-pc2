#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int a[N + 5], sum[N + 5], maxns[N + 5], minns[N + 5];
int ans[N + 5];

int main() {
    freopen("peace.in", "r", stdin);
    freopen("peace.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n; i ++)
        maxns[i] = max(maxns[i - 1], a[i]);
    memset(minns, 0x3f, sizeof minns);
    for (int i = 1; i <= n; i ++)
        minns[i] = min(minns[i - 1], a[i]);
    for (int i = 3; i <= n; i ++)
        ans[i] = (sum[i] - maxns[i] - minns[i]) / (i - 2);
    int maxn = -1e9, mxid;
    for (int i = 3; i <= n; i ++)
        if (ans[i] >= maxn)
            maxn = ans[i], mxid = i;
    cout << mxid;
    return 0;
}
