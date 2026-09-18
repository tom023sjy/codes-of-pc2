#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
struct Node {
    int sums, ends;
    vector<int> sons;
    Node() {
        sums = ends = 0;
        sons.resize(2, 0);
    }
} tree[N + 5]; 
string strs[N + 5];
signed main() {
    int n, q;
    cin >> n >> q;
    int curr = 0;
    for (int i = 1; i <= n; i ++) {
        int pl;
        cin >> pl;
        int idx = 0;
        while (pl --) {
            char c;
            cin >> c;
            if (tree[idx].sons[c - '0'] == 0) {
                curr ++;
                tree[idx].sons[c - '0'] = curr;
            }
            idx = tree[idx].sons[c - '0'];
            tree[idx].sums ++;
        }
        tree[idx].ends ++;
    }
    while (q --) {
        int pl; cin >> pl;
        int idx = 0, sum = 0;
        bool full = 1;
        while (pl --) {
            char c; // If not whole, expire tokens. :D
            cin >> c;
            if (tree[idx].sons[c - '0'] == 0 && full) {
                // Oops!
                // No one matched ~~~
                cout << sum;
                full = 0;
            }
            if (full) {
                idx = tree[idx].sons[c - '0'];
                sum += tree[idx].ends;
            }
        }
        if (full)
            cout << sum + tree[idx].sums - tree[idx].ends;
        cout << endl;
    }
    return 0;
}
