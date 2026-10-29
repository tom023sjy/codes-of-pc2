#include <bits/stdc++.h>
using namespace std;
const int N = 2005, H = 55;
int n, a[N];
bitset<N * H> f, g;
int main() {
  freopen("cup.in", "r", stdin);
  freopen("cup.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n), f[0] = 1;
  for (int j = 1; j < n; j++) {
    for (int k = j + 1; k < n; k++) g |= (f << (a[k] - a[j]));
    f |= g;
  }
  for (int i = 0; i <= 25000; i++) if (f[i]) printf("%d ", i);
  puts("");
  return 0;
}
