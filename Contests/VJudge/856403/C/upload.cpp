#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1.1e7;
char s[N * 2 + 5];
int pos[N * 2 + 5];
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
    }
    cout << (*max_element(pos + 1, pos + curr + 1)) - 1;
    return 0;
}
