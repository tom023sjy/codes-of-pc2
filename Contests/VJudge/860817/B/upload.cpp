#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;
const int N = 1e5;
int f[N + 5], d[N + 5], e[N + 5];
vector<pii> a[N + 5], b[N + 5];
priority_queue<int, vector<int>, greater<int>> q[N + 5];
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= 11; i ++)
        q[1].push(0);
    for (int i = 2; i <= n; i ++) {
        cin >> f[i] >> d[i] >> e[i];
        q[i] = q[f[i]];
        q[i].push(d[i]);
        q[i].pop();
        e[i] += e[f[i]];
    }
    for (int i = 1; i <= n; i ++)
        for (int j = 10; j >= 0; j --) {
            int t = q[i].top();
            q[i].pop();
            a[j].push_back({t, e[i]});
        }
    for (int i = 0; i <= 10; i ++) {
        sort(a[i].begin(), a[i].end());
        b[i].push_back(a[i][0]);
        for (int j = 1; j < a[i].size(); j ++)
            if (a[i][j].second > b[i].back().second)
                b[i].push_back(a[i][j]);
    }
    int T;
    cin >> T;
    while (T --) {
        int s, c;
        cin >> s >> c;
        int k = upper_bound(b[c].begin(), b[c].end(), pii{s, 9e18}) - b[c].begin() - 1;
        cout << b[c][k].second << endl;
    }
    return 0;
}
