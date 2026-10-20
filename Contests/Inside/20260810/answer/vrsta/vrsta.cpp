#include <bits/stdc++.h>
using namespace std;
#define int long long
// 输入
const int Q = 2e5;
struct Query {
    int v, w, c;
} q[Q + 5];

// BIT 相关
int t[Q + 5];
inline int lowbit(int x) {
    return x & -x;
}
inline void update(int p, int d) {
    for (; p <= Q; p += lowbit(p))
        t[p] += d;
}
inline int query(int p) {
    int sum = 0;
    for (; p; p -= lowbit(p))
        sum += t[p];
    return sum;
}

// 快速查找
inline int find(int x) {
    int l = 1, r = Q, ans;
    while (l <= r) {
        int mid = l + r >> 1;
        if (query(mid) <= x)
            ans = mid, r = mid + 1;
        else l = mid - 1;
    }
    return ans;
}

signed main() {
    freopen("vrsta.in", "r", stdin);
    freopen("vrsta.out", "w", stdout);
    map<int, int> mp;
    int T;
    cin >> T;
    vector<int> tmp; // 离散
    for (int t = 1; t <= T; t ++) {
        cin >> q[t].v >> q[t].c;
        tmp.push_back(q[t].v);
    }
    stable_sort(tmp.begin(), tmp.end());
    int cnt = 0;
    for (int val : tmp)
        mp[++ cnt] = val;
    for (int t = 1; t <= T; t ++)
        q[t].w = mp[q[t].v];
    int pcnt = 0;
    for (int t = 1; t <= T; t ++) {
        pcnt += q[t].c;
        update(q[t].w, q[t].c);
        cout << mp[find(pcnt << 1)] << endl;
    }
    return 0;
}