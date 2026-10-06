#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5, mod = 1e9 + 7;
int hh[N + 5], ht[N + 5], ps[N + 5];
char c[N + 5];
bool check(int l, int r, int len) {
    return ((hh[l + len - 1] - hh[l - 1] * ps[len]) % mod + mod) % mod == ((ht[r - len + 1] - ht[r + 1] * ps[len]) % mod + mod) % mod;
}
int find(int ll, int rr, int len) {
    int l = 1, r = len, ans = 1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(ll, rr, mid))
            ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ans;
}
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> c[i];
    ps[0] = 1;
    for (int i = 1; i <= n; i ++) 
        hh[i] = (hh[i - 1] * 128 + c[i]) % mod, ps[i] = ps[i - 1] * 128 % mod;
    for (int i = n; i >= 1; i --) 
        ht[i] = (ht[i + 1] * 128 + c[i]) % mod;
    int l = 1, r = n;
    vector<char> ans;
    for (int i = 1; i < n; i ++)
        if (c[l] < c[r])
            ans.push_back(c[l]), l ++;
        else if (c[l] > c[r])
            ans.push_back(c[r]), r --;
        else {
            int len = find(l, r, r - l + 1);
            if (c[l + len] < c[r - len])
                ans.push_back(c[l]), l ++;
            else ans.push_back(c[r]), r --;
        }
    ans.push_back(c[l]);
    int cnt = 0;
    for (char c : ans) {
        cnt ++;
        cout << c;
        if (cnt % 80 == 0)
            cout << endl;
    }
    return 0;
}
