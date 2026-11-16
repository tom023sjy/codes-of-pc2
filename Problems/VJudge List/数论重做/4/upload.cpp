#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5, mod = 1e9 + 7;
int a[N + 5], mp[N + 5];
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], mp[a[i]] ++;
    // 判断无解
    if (n & 1) {
        for (int i = 2; i < n; i += 2)
            if (mp[i] != 2) 
                return puts("0"), 0;
        if (mp[0] != 1)
            return puts("0"), 0;
    }
    else 
        for (int i = 1; i < n; i += 2)
            if (mp[i] != 2) 
                return puts("0"), 0;
    cout << fp(2, n / 2, mod);
    return 0;
}
