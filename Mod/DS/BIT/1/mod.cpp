#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
int a[N + 5], n, s[N + 5];
inline int lowbit(int x) {
    return x & -x;
}
void update(int p, int d) {
    for (; p <= n; p += lowbit(p)) 
        s[p] += d;
}
int query(int p) {
    int ans = 0;
    for (; p; p -= lowbit(p)) 
        ans += s[p];
    return ans;
}