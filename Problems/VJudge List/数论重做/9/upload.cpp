#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2002;
int c[N + 5][N + 5], s[N + 5][N + 5];
signed main() {
	int T, mod;
    cin >> T >> mod;
    c[0][0] = 1;
    for (int i = 1; i <= N; i ++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j ++)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1],
            c[i][j] %= mod,
            s[i][j] = 
                - s[i - 1][j - 1] + s[i - 1][j] 
                + s[i][j - 1]     + !c[i][j];
        s[i][i + 1] = s[i][i]; 
    }
    while (T --) {
        int n, m;
        cin >> n >> m;
        cout << s[n][min(n, m)] << endl;
    }
    return 0;
}
