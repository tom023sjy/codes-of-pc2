#include <bits/stdc++.h>
#define re register
using namespace std;
const int N = 1e7 + 10;
int n;
char s[N],ans[N];
inline int read(){
    int r = 0,w = 1;
    char c = getchar();
    while (c < '0' || c > '9'){
        if (c == '-') w = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9'){
        r = (r << 3) + (r << 1) + (c ^ 48);
        c = getchar();
    }
    return r * w;
}
inline void solve(){
    n = read();
    scanf("%s",s + 1);
    int a = -1,b = -1,c = n + 1;
    for (re int i = 1;i <= n;i++){
        if (s[i] == '1'){ a = i; break; }
    }
    if (!~a) return puts("0"),void();
    for (re int i = a;i <= n;i++){
        if (s[i] == '0'){ b = i; break; }
    }
    if (!~b){
        for (re int i = a;i < n;i++) putchar('1');
        if (a > 1) putchar('1');
        else putchar('0');
        return puts(""),void();
    }
    for (re int i = b;i <= n;i++){
        if (s[i] == '1'){ c = i; break; }
    } int len = min(b - a,c - b);
    for (re int i = n - a + 1,j = n,k = n - len;i;i--,j--,k--){
        int A = (j < a) ? 0 : (s[j] - '0'),B = (k < b - len) ? 0 : (s[k] - '0');
        ans[i] = (A ^ B) + '0';
        cerr << i << " " << j << " " << k << endl;
    }
    for (re int i = 1;i <= n - a + 1;i++) putchar(ans[i]);
    puts("");
}

int main(){
    int T = read();
    while (T--) solve();
    return 0;
}
