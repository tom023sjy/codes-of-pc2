#include <bits/stdc++.h>
using namespace std;
const int N = 1005, inf = 1e9;
int n, m, q, a[N][N];
int query(int *x, int *y, int k) {
  int l0 = 1, r0 = m, l1 = 1, r1 = m;
  while (k > 1 && l0 < r0 && l1 < r1) {
    int mid0 = (l0 + r0) >> 1;
    int mid1 = (l1 + r1) >> 1;
    int len0 = mid0 - l0 + 1;
    int len1 = mid1 - l1 + 1;
    if (x[mid0] <= y[mid1]) {
      if (len0 + len1 < k) l0 = mid0 + 1, k -= len0;
      else r1 = mid1;
    } else {
      if (len0 + len1 < k) l1 = mid1 + 1, k -= len1;
      else r0 = mid0;
    }
  }
  if (l0 > r0) return y[l1 + k - 1];
  if (l1 > r1) return x[l0 + k - 1];
  if (l0 == r0) {
    if (k == (r1 - l1 + 1) + 1) return max(x[l0], y[l1 + k - 2]);
    int a[3] = {x[l0], y[l1 + k - 2], y[l1 + k - 1]};
    sort(a, a + 3); return a[1];
  }
  if (l1 == r1) {
    if (k == (r0 - l0 + 1) + 1) return max(y[l1], x[l0 + k - 2]);
    int a[3] = {y[l1], x[l0 + k - 2], x[l0 + k - 1]};
    sort(a, a + 3); return a[1];
  }
  return min(x[l0], y[l1]);
}
int main() {
  freopen("familiar.in", "r", stdin);
  freopen("familiar.out", "w", stdout);
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    a[i][m + 1] = inf;
  }
  while (q--) {
    int op, x, y, k;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d%d", &x, &y, &k);
      printf("%d\n", query(a[x], a[y], 2 * m - k + 1));
    } else {
      scanf("%d%d", &x, &y);
      a[x][upper_bound(a[x] + 1, a[x] + m + 1, y) - a[x] - 1] = y;
    }
  }
  return 0;
}