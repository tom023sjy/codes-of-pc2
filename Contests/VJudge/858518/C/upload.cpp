#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
vector<int> g[N + 5];
int dd[N + 5];
vector<int> child[N + 5];
void dfs(int id, int ft) {
    child[id].push_back(id);
    for (int nxt : g[id]) {
        if (nxt == ft) continue;
        dfs(nxt, id);
        for (int vl : child[nxt])
            child[id].push_back(vl);
    }
}
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> dd[i];
    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v); 
        g[v].push_back(u);
    }
    dfs(1, 0);
    vector<int> p, ans, d;
    for (int i = 1; i <= n; i ++)
        p.push_back(i);
    do {
        d.resize(n + 1, 0);
        map<int, int> plc;
        for (int i = 0; i < p.size(); i ++) {
            int td = 9e18;
            for (int son : child[p[i]])
                if (plc.count(son))
                    td = min(td, i - plc[son]);
            if (td == 9e18)
                td = -1;
            d[p[i]] = td;
            plc[p[i]] = i;
        }
        bool flg = 1;
        for (int i = 1; i <= n; i ++)
            if (d[i] != dd[i])
                flg = 0;
        if (flg) {
            if (!ans.empty()) {
                bool flg = 0;
                for (int i = 0; i < ans.size(); i ++)
                    if (ans[i] != p[i]) {
                        if (ans[i] > p[i]) flg = 1;
                        break;
                    }
                if (flg)
                    ans = p;
            }
            else ans = p;
        }
    } while (next_permutation(p.begin(), p.end()));
    if (ans.empty())
        return puts("-1"), 0;
    for (int v : ans)
        cout << v << " ";
    return 0;
}
