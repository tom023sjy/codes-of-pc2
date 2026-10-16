#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    mt19937 rnd(time(0));
    int T = 10000;
    cout << T << endl;
    while (T --) {
        int k = rnd() % 10 + 1, l = rnd() % 10 + 1 + k;
        int r = rnd() % 10 + 1 + l, x = rnd() % 100 + 1;
        cout << l << " " << r << " " << k << " " << x;
        cout << endl;
    }
    return 0;
}