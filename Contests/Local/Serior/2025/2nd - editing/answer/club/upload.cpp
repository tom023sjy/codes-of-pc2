#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int a[N + 5][5], n, grp[N + 5], cnt[4];
void solve() {
    memset(cnt, 0, sizeof cnt);
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i][1] >> a[i][2] >> a[i][3];
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        // 我想去哪去哪，管你那些
        int maxn = max(a[i][1], max(a[i][2], a[i][3]));
        if (a[i][1] == maxn) 
            grp[i] = 1, cnt[1] ++, sum += a[i][1];
        else if (a[i][2] == maxn) 
            grp[i] = 2, cnt[2] ++, sum += a[i][2];
        else 
            grp[i] = 3, cnt[3] ++, sum += a[i][3];
    }
    int mxsize = max(cnt[1], max(cnt[2], cnt[3]));
    if (mxsize <= n / 2)  {
       cout << sum << endl;
        return ;
    }
    // 哎大了，那就铲score
    vector<int> tmp;
    for (int i = 1; i <= n; i ++)
        if (grp[i] == 1 && cnt[1] > n / 2)
            tmp.push_back(a[i][1] - max(a[i][2], a[i][3]));
        else if (grp[i] == 2 && cnt[2] > n / 2)
            tmp.push_back(a[i][2] - max(a[i][1], a[i][3]));
        else if (grp[i] == 3 && cnt[3] > n / 2)
            tmp.push_back(a[i][3] - max(a[i][2], a[i][1]));
    sort(tmp.begin(), tmp.end());
    int idx = 0;
    while (cnt[1] > n / 2)
        sum -= tmp[idx ++], cnt[1] --;
    while (cnt[2] > n / 2)
        sum -= tmp[idx ++], cnt[2] --;
    while (cnt[3] > n / 2)
        sum -= tmp[idx ++], cnt[3] --;
   cout << sum << endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	int T;
    cin >> T;
    while (T --) 
        solve();
    return 0;
}
