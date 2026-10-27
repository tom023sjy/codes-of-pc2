#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
int n, s[N + 5];
inline int lowbit(int x) {
    return x & -x;
}
void update(int p, int d) {
    for (; p <= n; p += lowbit(p)) 
        s[p] += d;
}
int query(int p) {
    int ans = 0;
    for (; p; p -= lowbit(p)) 
        ans += s[p];
    return ans;
}
signed main() {
    int q, prv;
    cin >> n >> q >> prv;
    update(1, prv);
    for (int i = 2; i <= n; i ++) {
        int x;
        cin >> x;
        update(i, x - prv);
        prv = x;
    }
    while (q --) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            update(l, x);
            update(r + 1, -x);
        }
        else {
            int p;
            cin >> p;
            cout << query(p) << endl;
        }
    }
    return 0;
}