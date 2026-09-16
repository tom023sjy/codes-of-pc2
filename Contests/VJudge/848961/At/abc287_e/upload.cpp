#include <bits/stdc++.h>
using namespace std;
#define int32 signed
#define int long long
#define int64 int
const int N = 3e6;
struct Node {
    int sums;
    vector<int32> sons, cnt;
    Node() {
        sums = 0;
        sons.resize(26, 0);
        cnt.resize(26, 0);
    }
} tree[N + 5]; 
string strs[N + 5];
int32 main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int mmp[128] = {};
    for (char c = 'a'; c <= 'z'; c ++)
        mmp[c] = c - 'a';
    int n;
    cin >> n;
    int curr = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> strs[i];
        int idx = 0;
        for (char c : strs[i]) {
            tree[idx].cnt[mmp[c]] ++;
            if (tree[idx].sons[mmp[c]] == 0) {
                curr ++;
                tree[idx].sons[mmp[c]] = curr;
            }
            idx = tree[idx].sons[mmp[c]];
            tree[idx].sums ++;
        }
    }
    for (int i = 1; i <= n; i ++) {
        int idx = 0, h = 0;
        for (char c : strs[i]) {
            if (tree[idx].cnt[c - 'a'] <= 1)
                break;
            idx = tree[idx].sons[c - 'a'];
            h ++;
        }
        cout << h << endl;
    }
    return 0;
}