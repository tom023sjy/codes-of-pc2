#include <bits/stdc++.h>
using namespace std;
#define int long long

// Config.ini
#define readf "triangle.in"
#define writf "triangle.out"
// #define debug

const int N = 10;
int n;
bool a[N + 5][N + 5], b[N + 5][N + 5], c[N + 5][N + 5];

void TurnLeft() {
    memset(c, 0, sizeof c);
    vector<pair<int, int>> poses;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= i; j ++)
            poses.push_back({n + 1 - j, i - j + 1});
    int curr = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= i; j ++)
            c[poses[curr].first][poses[curr].second] = a[i][j], curr ++;
    memcpy(a, c, sizeof c);
}
void Mirror() {
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j * 2 <= i; j ++)
            swap(a[i][j], a[i][i - j + 1]);
}
int Diff() {
    int ret = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= i; j ++)
            ret += a[i][j] != b[i][j];
    return ret;
}
signed main() {
    freopen(readf, "r", stdin);
    freopen(writf, "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= i; j ++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= i; j ++)
            cin >> b[i][j];
    int ans = Diff();
    #ifdef debug
    cerr << Diff() << endl;
    ofstream fs;
    fs.open("debug\\st1.csv");
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= i; j ++)
            fs << a[i][j] << ",";
        fs << endl;
    }
    fs.close();
    #endif
    Mirror();
    ans = min(ans, Diff());
    #ifdef debug
    cerr << Diff() << endl;
    fs.open("debug\\st2.csv");
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= i; j ++)
            fs << a[i][j] << ",";
        fs << endl;
    }
    fs.close();
    #endif
    Mirror();
    TurnLeft();
    ans = min(ans, Diff());
    #ifdef debug
    cerr << Diff() << endl;
    fs.open("debug\\st3.csv");
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= i; j ++)
            fs << a[i][j] << ",";
        fs << endl;
    }
    fs.close();
    #endif
    Mirror();
    ans = min(ans, Diff());
    #ifdef debug
    cerr << Diff() << endl;
    fs.open("debug\\st4.csv");
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= i; j ++)
            fs << a[i][j] << ",";
        fs << endl;
    }
    fs.close();
    #endif
    Mirror();
    TurnLeft();
    ans = min(ans, Diff());
    #ifdef debug
    cerr << Diff() << endl;
    fs.open("debug\\st5.csv");
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= i; j ++)
            fs << a[i][j] << ",";
        fs << endl;
    }
    fs.close();
    #endif
    Mirror();
    ans = min(ans, Diff());
    #ifdef debug
    cerr << Diff() << endl;
    fs.open("debug\\st6.csv");
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= i; j ++)
            fs << a[i][j] << ",";
        fs << endl;
    }
    fs.close();
    #endif
    cout << ans;
    return 0;
}