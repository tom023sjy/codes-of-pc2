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
    int n, m;
    cin >> n >> m;
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
