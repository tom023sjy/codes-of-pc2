#include <bits/stdc++.h>
using namespace std;
#define int long long

// Config.ini
#define readf "traversing.in"
#define writf "traversing.out"

const int N = 5000;
struct Node {
    int l, r, id, val;
    Node() {
        l = r = id = 0;
        val = -1;
    }
} a[N + 5];
vector<int> dfs(int id) {
    vector<int> lft, rgt, ret;
    if (a[id].l)
        lft = dfs(a[id].l);
    if (a[id].r)
        rgt = dfs(a[id].r);
    if (a[id].val == -1) {
        ret.push_back(a[id].id);
        for (int v : lft)
            ret.push_back(v);
        for (int v : rgt)
            ret.push_back(v);
    }
    else if (a[id].val == 0) {
        for (int v : lft)
            ret.push_back(v);
        ret.push_back(a[id].id);
        for (int v : rgt)
            ret.push_back(v);
    }
    else  {
        for (int v : lft)
            ret.push_back(v);
        for (int v : rgt)
            ret.push_back(v);
        ret.push_back(a[id].id);
    }
    return ret;
}
signed main() {
    freopen(readf, "r", stdin);
    freopen(writf, "w", stdout);
    int n, T;
    cin >> n >> T;
    if (n * T > 1e9 || n * n > 1e9)
        return puts("Oops! Big data!"), -1;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].l >> a[i].r, a[i].id = i;
    while (T --) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            for (int i = l; i <= r; i ++)
                a[i].val = x;
        }
        else {
            int id;
            cin >> id;
            auto seq = dfs(1);
            for (int i = 0; i < seq.size(); i ++)
                if (seq[i] == id) {
                    cout << i + 1 << endl;
                    break;
                }
        }
    }
    return 0;
}