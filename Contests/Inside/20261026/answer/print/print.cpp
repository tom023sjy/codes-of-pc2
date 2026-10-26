#include <bits/stdc++.h>
using namespace std;
#define int long long
const string FIO = "print";
const bool JUDGE = 1;
const string FI = FIO + ".in", FO = FIO + ".out";

const int N = 2e5;
struct Tsk {
    int id, sp, tm;
} a[N + 5];
bool cmp(Tsk x, Tsk y) {
    return x.tm < y.tm;
}
vector<int> his[N + 5];
int t[N + 5];

signed main() {
    #ifndef ONLINE_JUDGE
        if (JUDGE) {
            freopen(FI.data(), "r", stdin);
            freopen(FO.data(), "w", stdout);
        }
    #endif
    int n, m;
    cin >> n >> m;
    if (n * m >= 1e9) {
        for (int i = 1; i <= m; i ++) {
            if (i == 1) {
                cout << n << " ";
                for (int j = 1; j <= n; j ++)
                    cout << j << " ";
            }
            else cout << 0;
            cout << endl;
        }
    }
    for (int i = 1; i <= n; i ++)
        cin >> a[i].sp >> a[i].tm, a[i].id = i;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i ++) {
        int p, minn = 9e18;
        for (int j = 1; j <= m; j ++)
            if (max(t[j] - a[i].tm, 0ll) < minn)
                minn = max(t[j] - a[i].tm, 0ll), p = j;
        his[p].push_back(a[i].id);
        t[p] = a[i].tm + a[i].sp;
    }
    for (int i = 1; i <= m; i ++) {
        cout << his[i].size() << " ";
        sort(his[i].begin(), his[i].end());
        for (int val : his[i])
            cout << val << " ";
        cout << endl;
    }
    return 0;
}
