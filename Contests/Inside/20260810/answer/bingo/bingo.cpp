#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 50, M = 90;
string str[N + 5];
int num[N + 5][6][6];
bool vis[N + 5][6][6];
signed main() {
    freopen("bingo.in", "r", stdin);
    freopen("bingo.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> str[i];
        for (int j = 1; j <= 5; j ++)
            for (int k = 1; k <= 5; k ++)
                cin >> num[i][j][k];
    }
    int T;
    cin >> T;
    while (T --) {
        int x;
        cin >> x;
        for (int i = 1; i <= n; i ++) {
            // 找到 x 并标记
            for (int j = 1; j <= 5; j ++)
                for (int k = 1; k <= 5; k ++)
                    if (num[i][j][k] == x)
                        vis[i][j][k] = 1;
        }
    }
    vector<string> names;
    for (int i = 1; i <= n; i ++) {
        bool can = 0;
        // 行
        for (int j = 1; j <= 5; j ++) {
            bool res = 1;
            for (int k = 1; k <= 5; k ++)
                if (!vis[i][j][k])
                    res = 0;
            if (res) {
                names.push_back(str[i]);
                can = 1;
                break;
            }
        }
        if (can) continue;
        // 列
        for (int k = 1; k <= 5; k ++) {
            bool res = 1;
            for (int j = 1; j <= 5; j ++)
                if (!vis[i][j][k])
                    res = 0;
            if (res) {
                names.push_back(str[i]);
                can = 1;
                break;
            }
        }
        if (can) continue;
        // 左to右 对角线
        bool res = 1;
        for (int j = 1; j <= 5; j ++)
            if (!vis[i][j][j])
                res = 0;
        if (res) {
            names.push_back(str[i]);
            continue;
        }
        // 右to左 对角线
        res = 1;
        for (int j = 1; j <= 5; j ++)
            if (!vis[i][j][6 - j])
                res = 0;
        if (res) {
            names.push_back(str[i]);
            continue;
        }
    }
    cout << names.size() << endl;
    for (string each : names)
        cout << each << endl;
    return 0;
}