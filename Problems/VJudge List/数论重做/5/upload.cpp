#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
int ans[N + 5];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    for (int i = 4; i <= N; i ++)
        ans[i] = ans[i - 1] + ((i - 1) / 2) * ((i - 2) / 2);
	while (1) {
        int n;
        cin >> n;
        if (n < 3) return ans[n];
        cout << ans[n] << endl;
    }
    return 0;
}