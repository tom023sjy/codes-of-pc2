#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10000;
string s[N + 5];
struct Hash {
    int a, b, c;
};
bool operator == (Hash x, Hash y) {
    return x.a == y.a && x.b == y.b && x.c == y.c;
}
Hash hs(string s) {
    int rs1 = 0, rs2 = 0, rs3 = 0;
    const int mod1 = 65537, mod2 = 998244353, mod3 = 1e9 + 7;
    for (char c : s) {
        rs1 = rs1 * 128 + c;
        rs2 = rs2 * 128 + c; 
        rs3 = rs3 * 128 + c;
        rs1 %= mod1;
        rs2 %= mod2;
        rs3 %= mod3;
    }
    return {rs1, rs2, rs3};
}
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> s[i];
    sort(s + 1, s + n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
        if (hs(s[i - 1]) == hs(s[i]))
            continue;
        else cnt ++;
    cout << cnt;
    return 0;
}
