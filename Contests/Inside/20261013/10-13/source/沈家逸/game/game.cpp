#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5, mod = 1e9 + 7;
vector<int> g[N + 5];
map<int, int> dfs(int id, int ft) {
    map<int, int> ret;
    ret[1] ++;
    for (int nxt : g[id]) if (nxt != ft) {
        auto inf = dfs(nxt, id);
        for (auto kv : inf)
            ret[kv.first + 1] += kv.second;
    }
    return ret;
}
signed main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (g[1].size() == 1 || n == 1) {
        // 干脆让1断子绝孙
        // 注意到成链的有40pts
        // 还有猝不及防的n=1，要是测试点**，n=1会漏判
        return puts("1"), 0;
    }
    // 大概率会假
    vector<map<int, int>> t;
    for (int i : g[1])
        t.push_back(dfs(i, 1));
    // 于是乎，找到所有的{first, second}里面first相同的，second处理一下
    map<int, vector<int>> v;
    for (auto vl : t) 
        for (auto kv : vl)
            v[kv.first].push_back((1 + kv.second) * kv.second / 2);
    int ans = 1;
    for (auto kv : v) {
        int mul = 1;
        for (int vl : kv.second)
            mul *= (vl + 1), mul %= mod;
        for (int vl : kv.second)
            mul += mod - vl, mul %= mod;
        mul += mod - 1;
        mul %= mod;
        ans += mul;
        ans %= mod;
    }
    cout << ans;
    return 0;
}









/*
当他是一条链
等于说Mr.Panda会给你吃(n/2+n%2)然后给Mr.Sheep剩下的
∴ Mr.Sheep永远走不动
除了Mr.Sheep踊跃而出选择只保留Node[1]，这样Mr.Panda完全走不了
当然走不了就Mr.Sheep赢咯

看样例
首先，我所构造出来的图：
 1        1             1
         / \           / \
 1       2 4           2 4
/ \      | |          / / \
2 4      3 5          3 5 6
然后，这些图的共性：
1. 他们每个children的高度一样
2. 1下面至少两个儿子（否则puts 1）
然后，这一组：
5
1 2
1 3
1 4
2 5
如图：
 1     1       1        1 
      / \     / \     / | \
      2 3     2 4     2 3 4
然后，得到了一个结论2的补充：
不光是2childs，可以是更多的child，就是合起来要算
感性理解，我没法证明......
*/