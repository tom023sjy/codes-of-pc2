#include <bits/stdc++.h>
using namespace std;
#define int32 signed
// #define int long long
#define int64 int
const int N = 3e6;
struct Node {
    int sums;
    vector<int32> sons;
    Node() {
        sums = 0;
        sons.resize(62, 0);
    }
} tree[N + 5]; 
string strs[N + 5];
void clean(int idx) {
    tree[idx].sums = 0;
    for (int nxt : tree[idx].sons)
        if (nxt)
            clean(nxt);
    fill(tree[idx].sons.begin(), tree[idx].sons.end(), 0);
}
int32 main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int mmp[128] = {};
    int p = 0;
    for (char c = '0'; c <= '9'; c ++)
        mmp[c] = p ++;
    for (char c = 'A'; c <= 'Z'; c ++)
        mmp[c] = p ++;
    for (char c = 'a'; c <= 'z'; c ++)
        mmp[c] = p ++;
    int T;
    cin >> T;
    while (T --) {
        int n, q;
        cin >> n >> q;
        int curr = 0;
        for (int i = 1; i <= n; i ++) {
            cin >> strs[i];
            int idx = 0;
            for (char c : strs[i]) {
                if (tree[idx].sons[mmp[c]] == 0) {
                	curr ++;
                    tree[idx].sons[mmp[c]] = curr;
				}
                idx = tree[idx].sons[mmp[c]];
                tree[idx].sums ++;
            }
        }
        while (q --) {
            string s;
            cin >> s;
            int idx = 0;
            for (char c : s) {
                idx = tree[idx].sons[mmp[c]];
                if (!idx)
                    break;
            }
            if (idx)
                cout << tree[idx].sums;
            else cout << 0;
            cout << '\n';
        }
        clean(0);
    }
    return 0;
}
