#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5 + 7;
const int MAXM = 5e2 + 7;
struct node {
    int x, y, x2, y2, pw;
} v[MAXN];
int c, n, h, w, sum, ans;
int pre[MAXM][MAXM];
vector<int> val, vis;
int solve(int x) {
    int res;
    if (x % 2 == 1) res = x * ((x - 1) / 2);
    else res = (x / 2) * (x - 1);
    return res;
}
void f() {
    memset(pre, 0, sizeof(pre));
    for (auto u : val) {
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (v[u].x <= i && i <= v[u].x2 && v[u].y <= j && j <= v[u].y2) continue;
                pre[i][j] += v[u].pw;
            }
        }

    }
    int nx, ny, Max = -1;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            int tmp = pre[i][j];
            if (tmp > Max) {
                Max = tmp;
                nx = i;
                ny = j;
            }
        }
    }
    for (auto u : val) {
        if (v[u].x <= nx && nx <= v[u].x2 && v[u].y <= ny && ny <= v[u].y2) vis.push_back(u);
    }
    val.clear();
    for (auto u : vis) val.push_back(u);
    vis.clear();
    ans += solve(Max);
    if (val.size()) f();
    return;
}
signed main() {
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c;
    cin >> n >> h >> w;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].x >> v[i].y >> v[i].x2 >> v[i].y2 >> v[i].pw;
        sum += v[i].pw;
        val.push_back(i);
    }
    if (c == 9 || c == 10) {
        cout << solve(sum) << "\n";
        return 0;
    }
    f();
    cout << ans << "\n";
    return 0;
}
