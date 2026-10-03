#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N + 5], s[N + 5], ls[N + 5], curr, ln[N + 5];
vector<int> g[N + 5];
pair<int, int> pos[N + 5];
void dfs(int id, int ft) {
    ls[++ curr] = id;
    ln[curr] = 1;
    pos[id].first = curr;
    for (int nxt : g[id])
        if (nxt != ft)
            dfs(nxt, id);
    ls[++ curr] = -id;
    ln[curr] = -1;
    pos[id].second = curr;
} 
class SegTree {
    private:
        int dat[(N << 2) + 5];
        int tag[(N << 2) + 5];
        void pushdown(int id, int l, int r) {
            if (!tag[id]) return ;
            int mid = l + r >> 1, lft = id << 1, rgt = id << 1 | 1;
            dat[lft] += tag[id] * (s[mid] - s[l - 1]);
            tag[lft] += tag[id];
            dat[rgt] += tag[id] * (s[r] - s[mid]);
            tag[rgt] += tag[id];
            tag[id] = 0;
        }
        void pushup(int id) {
            int lft = id << 1, rgt = id << 1 | 1;
            dat[id] = dat[lft] + dat[rgt];
        }
    public:
        void build(int id, int l, int r) {
            if (l == r) {
                dat[id] = a[abs(ls[l])] * ln[l];
                return ;
            }
            int mid = l + r >> 1, lft = id << 1, rgt = id << 1 | 1;
            build(lft, l, mid);
            build(rgt, mid + 1, r);
            pushup(id);
        }
        void updateOne(int id, int l, int r, int p, int d) {
            if (l == r) {
                dat[id] += d;
                return ;
            }
            pushdown(id, l, r);
            int mid = l + r >> 1, lft = id << 1, rgt = id << 1 | 1;
            if (p <= mid)
                updateOne(lft, l, mid, p, d);
            else updateOne(rgt, mid + 1, r, p, d);
            pushup(id);
        }
        void updateBlock(int id, int l, int r, int ql, int qr, int qd) {
            if (ql <= l && r <= qr) {
                tag[id] += qd;
                dat[id] += qd * (s[r] - s[l - 1]);
                return ;
            }
            pushdown(id, l, r);
            int mid = l + r >> 1, lft = id << 1, rgt = id << 1 | 1;
            if (ql <= mid)
                updateBlock(lft, l, mid, ql, qr, qd);
            if (mid + 1 <= qr)
                updateBlock(rgt, mid + 1, r, ql, qr, qd);
            pushup(id);
        }
        int query(int id, int l, int r, int ql, int qr) {
            if (ql <= l && r <= qr)
                return dat[id];
            pushdown(id, l, r);
            int ans = 0;
            int mid = l + r >> 1, lft = id << 1, rgt = id << 1 | 1;
            if (ql <= mid)
                ans += query(lft, l, mid, ql, qr);
            if (mid + 1 <= qr)
                ans += query(rgt, mid + 1, r, ql, qr);
            return ans;
        }
} segt;
signed main() {
    int n, T;
    cin >> n >> T;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n * 2; i ++)
        s[i] = s[i - 1] + ln[i];
    segt.build(1, 1, 2 * n);
    while (T --) {
        int opt, u, v;
        cin >> opt >> u;
        if (opt == 1) {
            cin >> v;
            segt.updateOne(1, 1, 2 * n, pos[u].first, +v);
            segt.updateOne(1, 1, 2 * n, pos[u].second, -v);
        }
        else if (opt == 2) {
            cin >> v;
            segt.updateBlock(1, 1, 2 * n, pos[u].first, pos[u].second, v);
        }
        else cout << segt.query(1, 1, 2 * n, 1, pos[u].first) << endl;
    }
    return 0;
}
