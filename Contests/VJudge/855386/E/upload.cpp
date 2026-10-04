#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N + 5], b[N + 5];
signed main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    memcpy(b, a, sizeof a);
    sort(b + 1, b + n + 1);
    int l = 1, r = n;
    while (b[l] == a[l]) l ++;
    while (b[r] == a[r]) r --;
    if (r - l + 1 > k)
        puts("No");
    else puts("Yes");
    return 0;
}
