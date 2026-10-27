char s[N + 5], t[N + 5];
int nxt[N + 5];
signed main() {
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
    return 0;
}