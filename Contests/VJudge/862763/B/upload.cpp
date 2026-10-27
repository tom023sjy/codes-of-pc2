#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int N = 2e5;
struct GasT {
    int p, t, x, qid;
} a[N + 5];
bool cmp(GasT x, GasT y) {
    if (x.p != y.p) return x.p < y.p;
    return x.x > y.x;
}
double dp[2][35][25], ans[N + 5];
int k2[35], k3[25];
signed main() {
    int n, T;
    cin >> n >> T;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].p >> a[i].t >> a[i].x, a[i].qid = -i;
    int curr = n;
    for (int t = 1; t <= T; t ++) {
        int x;
        cin >> x;
        curr ++;
        a[curr].p = x, a[curr].t = 0, a[curr].x = 1, a[curr].qid = t;
    }
    sort(a + 1, a + curr + 1, cmp);
    k2[0] = k3[0] = 1;
    for (int i = 1; i <= 30; i ++)
        k2[i] = k2[i - 1] << 1;
    for (int i = 1; i <= 20; i ++)
        k3[i] = k3[i - 1] * 3;
    for (int i = 0; i < 2; i ++)
        for (int j = 0; j < 35; j ++)
            for (int k = 0; k < 25; k ++)
                dp[i][j][k] = 9e18l;
    for (int i = 0; i < N + 5; i ++)
        ans[i] = -1;
    dp[0][0][0] = 0;
    for (int i = 1; i <= curr; i ++) {
        for (int j = 0; j <= 30; j ++)
            for (int k = 0; k <= 20; k ++) {
                if (k2[j] * k3[k] > 1e9) break;
                // dp[i][j][k] 1~i 2^j*3^k（指加完油以后）
                dp[i & 1][j][k] = dp[i - 1 & 1][j][k] + (a[i].p - a[i - 1].p) * 1.0l / (k2[j] * k3[k]);
                if (a[i].x == 2 && j)
                    dp[i & 1][j][k] = min(dp[i & 1][j][k], dp[i - 1 & 1][j - 1][k] + (a[i].p - a[i - 1].p) * 1.0l / (k2[j - 1] * k3[k]) + a[i].t);
                if (a[i].x == 3 && k)
                    dp[i & 1][j][k] = min(dp[i & 1][j][k], dp[i - 1 & 1][j][k - 1] + (a[i].p - a[i - 1].p) * 1.0l / (k2[j] * k3[k - 1]) + a[i].t);
                if (a[i].x == 4 && j > 1)
                    dp[i & 1][j][k] = min(dp[i & 1][j][k], dp[i - 1 & 1][j - 2][k] + (a[i].p - a[i - 1].p) * 1.0l / (k2[j - 2] * k3[k]) + a[i].t);
            }
        if (a[i].qid > 0) {
            ans[a[i].qid] = 9e18l;
            for (int j = 0; j <= 30; j ++)
                for (int k = 0; k <= 20; k ++)
                    ans[a[i].qid] = min(ans[a[i].qid], dp[i & 1][j][k]);
        }
    }
    for (int t = 1; t <= T; t ++)
        printf("%.9llf\n", ans[t]);
    return 0;
}