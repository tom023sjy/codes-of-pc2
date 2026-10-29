#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const ll inf = 1e18;
int n, m, a[N], b[N];
vector<int> d;
ll s[N], f[N];
struct Bit {
  ll tr[N];
  void modify(int x, ll y) {
    for (; x <= m; x += x & -x) tr[x] = min(tr[x], y);
  }
  ll query(int x) {
    ll res = inf;
    for (; x; x -= x & -x) res = min(res, tr[x]);
    return res;
  }
} A, B;
void insert(int i) {
  A.modify(b[i - 1], f[i] - s[i] - a[i - 1]);
  B.modify(m - b[i - 1] + 1, f[i] - s[i] + a[i - 1]);
}
int main() {
  freopen("express.in", "r", stdin);
  freopen("express.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    s[i] = s[i - 1] + abs(a[i] - a[i - 1]);
    d.emplace_back(a[i]);
  }
  d.emplace_back(0);
  sort(d.begin(), d.end());
  d.resize(m = unique(d.begin(), d.end()) - d.begin());
  for (int i = 0; i <= n; i++) {
    b[i] = lower_bound(d.begin(), d.end(), a[i]) - d.begin() + 1;
  }
  for (int i = 1; i <= m; i++) {
    A.tr[i] = B.tr[i] = inf;
  }
  f[1] = a[1], insert(1);
  ll ans = s[n];
  for (int i = 2; i <= n; i++) {
    f[i] = A.query(b[i]) + a[i] + s[i - 1];
    f[i] = min(f[i], B.query(m - b[i] + 1) - a[i] + s[i - 1]);
    insert(i);
    ans = min(ans, f[i] + s[n] - s[i]);
  }
  printf("%lld\n", ans);
  return 0;
}