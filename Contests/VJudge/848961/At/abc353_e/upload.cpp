#include <bits/stdc++.h>
using namespace std;
#define int32 signed
#define int long long
const int N = 3e6;
struct Node {
    int sums;
    vector<int32> sons;
    Node() {
        sums = 0;
        sons.resize(26, 0);
    }
} tree[N + 5]; 
string strs[N + 5];
int32 main() {
    int n;
    cin >> n;
    int curr = 0, ans = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> strs[i];
        int idx = 0;
        for (char c : strs[i]) {
            if (tree[idx].sons[c - 'a'] == 0) {
                curr ++;
                tree[idx].sons[c - 'a'] = curr;
            }
            idx = tree[idx].sons[c - 'a'];
            ans += tree[idx].sums ++;
        }
    }
    cout << ans;
    return 0;
}
