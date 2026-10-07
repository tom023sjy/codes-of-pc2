#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
char s[N * 2 + 5];
int pos[N * 2 + 5], lft[N * 2 + 5], rgt[N * 2 + 5];
signed main() {
    string str;
    cin >> str;
    int curr = 0;
    s[0] = 15;
    s[++ curr] = 31;
    for (char c : str)
        s[++ curr] = c, s[++ curr] = 31;
    s[curr + 1] = 127;
    int maxr = 0, tmid = 0;
    for (int i = 1; i <= curr; i ++) {
        if (i <= maxr) 
            pos[i] = min(pos[tmid * 2 - i], maxr - i + 1);
        while (s[i - pos[i]] == s[i + pos[i]]) 
            pos[i] ++;
        if (pos[i] + i > maxr)
            maxr = pos[i] + i - 1, tmid = i;
        rgt[i + pos[i] - 1] = max(rgt[i + pos[i] - 1], pos[i] - 1);
        lft[i - pos[i] + 1] = max(lft[i - pos[i] + 1], pos[i] - 1);
    }
    for (int i = 1; i <= curr; i += 2)
        lft[i] = max(lft[i], lft[i - 2] - 2);
    for (int i = curr; i >= 1; i -= 2)
        rgt[i] = max(rgt[i], rgt[i + 2] - 2);
    int ans = 0;
    for (int i = 1; i <= curr; i += 2)
        if (lft[i] && rgt[i])
            ans = max(ans, lft[i] + rgt[i]);
    cout << ans;
    return 0;
}
