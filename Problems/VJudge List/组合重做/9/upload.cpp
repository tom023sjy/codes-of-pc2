#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
int a[N + 5], c[N + 5];
void setup(int x) {
    for (int i = 1; i * i <= x; i ++) 
        if (x % i == 0) {
            c[i] ++, c[x / i] ++;
            if (i * i == x) c[i] --;
        }
}
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], setup(a[i]);
    /*
我们想到，k个数的公约数含义就是这k个数均含有某个因数，如果我们把所有数的因数全部求出来，发现有k个数均含有某个因数，那么这个数必然是这k个数的公约数。其中找出最大的就是它们的最大公约数。
    */
    int t = *max_element(a + 1, a + n + 1);
    for (int k = 1; k <= n; k ++) {
        while (c[t] < k) t --;
        cout << t << endl;
    }
    return 0;
}
