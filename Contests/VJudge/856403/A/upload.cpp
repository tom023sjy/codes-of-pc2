#include <bits/stdc++.h>
#define int long long
const int N = 1e6;
char s[N + 5], t[N + 5];
int nxt[N + 5];
signed main() {
    scanf("%s%s", s + 1, t + 1);
    int n = strlen(s + 1), m = strlen(t + 1);
    int len = 0;
    for (int i = 2; i <= m; i ++) {
        while (t[i] != t[len + 1] && len) len = nxt[len];
        if (t[i] == t[len + 1]) len ++;
        nxt[i] = len;
    }
    len = 0;
    for (int i = 1; i <= n; i ++) {
        while (s[i] != t[len + 1] && len) len = nxt[len];
        if (s[i] == t[len + 1]) len ++;
        if (len == m) {
            printf("%lld\n", i - len + 1);
            len = nxt[len];
        }
    }
    for (int i = 1; i <= m; i ++)
        printf("%lld ", nxt[i]);
    return 0;
}
