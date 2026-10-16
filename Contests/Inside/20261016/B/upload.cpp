#include <bits/stdc++.h>
using namespace std;
#define int long long
/*
1  0  2  1  5  0  7  1
4  k  7 k-1 0  k  3 k-1
0  1  3  0  4  1  7  0
7 k-1 4  k  3 k-1 0  k
*/
// #define pf
// #define tb
const int tab[4][8] = {
    1,  0, 2,  1, 5,  0, 7,  1,
    0,  1, 3,  0, 4,  1, 7,  0,
    4, -1, 7, -2, 0, -1, 3, -2,
    7, -2, 4, -1, 3, -2, 0, -1,
};
int solve(int l, int r, int k, int p) {
    if (r <= 1e4) {
        int s = 0;
        for (int i = k; i < l; i ++)
            s ^= i;
        for (int i = l; i <= r; i ++) {
            #ifdef tb
            cout << s << ", ";
            #endif
            s ^= i;
            #ifdef pf
            if (s == p)
                return i;
            #endif
        }
        #ifdef pf
        return -1;
        #endif
    }
    int idx = k % 4;
    int lp = (l + 7) / 8, rp = (r + 7) / 8;
    if (lp < rp) {
        // 跨表
        for (int i = 0; i < 8; i ++) {
            int ths = tab[idx][i];
            if (ths == -1) // k
                ths = k;
            else if (ths == -2) // k-1
                ths = k - 1;
            int lft = ths, rgt = ths;
            if (i % 2 == 0) // 一般值
                lft = ths + 8 * (lp - 1), rgt = ths + 8 * (rp - 1);
            if (!(lft <= p && p <= rgt)) continue;
            if (i % 2) {
                if (p != ths) continue;
                return (i + l) % 8 + l;
            }
            // d = 8
            if (lft % 8 != p % 8)
                continue;
            int grp = (p - lft) / 8 + 1; // 第grp组
            int ret = (i + l) % 8 + l - 1 + (grp - 1) * 8;
            return ret;     
        }
        return -1;
    }
    // 否则在同一表内
    for (int i = 0; i < 8; i ++) {
        int ths = tab[idx][i];
        if (ths == -1) // k
            ths = k;
        else if (ths == -2) // k-1
            ths = k - 1;
        int lft = ths;
        if (i % 2 == 0) // 一般值
            lft = ths + 8 * (lp - 1);
        if (lft != p) continue;
        if (i % 2) {
            if (p != ths) continue;
            return i + l;
        }
        // d = 8
        if (lft % 8 != p % 8)
            continue;
        int plc = (p - lft) / 8 + 1;
        return plc;
    }
    return -1;
}
signed main() {
    int T;
    cin >> T;
    while (T --) {
        int l, r, k, x;
        cin >> l >> r >> k >> x;
        cout << solve(l, r, k, x) << endl;
    }
    return 0;
}