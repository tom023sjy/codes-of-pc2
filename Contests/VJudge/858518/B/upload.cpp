#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
vector<int> g[N + 5];

signed main() {
    // 求根节点是多少子图的直径中点
    int n;
    cin >> n;
    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    return 0;
}