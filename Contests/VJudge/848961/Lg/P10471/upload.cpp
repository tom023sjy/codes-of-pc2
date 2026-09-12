#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e6;
struct Node {
    int sums;
    vector<int> sons;
    Node() {
        sums = 0;
        sons.resize(2, 0);
    }
} tree[N + 5]; 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, ans = 0;
    cin >> n;
    int curr = 0;
    for (int i = 1; i <= n; i ++) {
        int num;
        cin >> num;
        string res;
        int tmp = num;
        for (int c = 0; c < 31; tmp >>= 1, c ++) 
            res = char((tmp & 1) + '0') + res;
        int idx = 0;
        for (char c : res) {
            if (tree[idx].sons[c - '0'] == 0) {
                curr ++;
                tree[idx].sons[c - '0'] = curr;
            }
            idx = tree[idx].sons[c - '0'];
            tree[idx].sums ++;
        }
        string pth;
        idx = 0;
        for (char c : res) {
            char add = char(((c - '0') ^ 1) + '0');
            int nxt = tree[idx].sons[(c - '0') ^ 1];
            if (nxt == 0)
                nxt = tree[idx].sons[c - '0'], 
                add = char((c - '0') + '0');
            pth += add;
            idx = nxt;
        }
        int another = 0;
        for (char c : pth)
            another = another << 1 | (c - '0');
        ans = max(ans, (num ^ another));
    }
    cout << ans;
    return 0;
}
