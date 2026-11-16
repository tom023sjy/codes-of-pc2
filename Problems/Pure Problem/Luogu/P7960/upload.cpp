#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define int long long

const int N = 1e7;
bool vis[N + 10];
int a[N + 5], curr;

signed main() {
    int T;
    cin >> T;
    // Preview
    memset(vis, 1, sizeof vis);
    for (int i = 1; i <= N + 5; i ++) {
        if (!vis[i]) continue;
        if (!(i % 7)) {
            vis[i] = 0;
            continue;
        }
        if (to_string(i).find('7') != -1) {
            for (int j = i; j <= N; j += i)
                vis[j] = 0;
        }
    }
    for (int i = 1; i <= N + 5; i ++)
        if (vis[i])
            a[++ curr] = i;
    while (T --) {
        int x;
        cin >> x;
        if (!vis[x]) {
            puts("-1");
            continue;
        }
        int p = *upper_bound(a + 1, a + curr + 1, x);
        cout << p << endl;
    }
    return 0;
}
