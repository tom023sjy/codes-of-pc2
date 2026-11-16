#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, ans, usg[20];
void dfs(int id, int emp) {
    if (id > n) {
        ans += !emp;
        return ;
    }
    if (emp > n - id + 1) return ;
    for (int i = 1; i <= m; i ++) {
        usg[i] ++;
        if (usg[i] == 1) emp --;
        dfs(id + 1, emp);
        usg[i] --;
        if (usg[i] == 0) emp ++;
    }
}
signed main() {
	cin >> n >> m;
    dfs(1, m);
    cout << ans;
    return 0;
}
