#include <cstdio>
#include <algorithm>
using std::min;
using std::max;

const int MX = 1010;

int a[MX][MX];

namespace solve
{
int m;

void init(int m) { solve::m = m; }

void modi(int x, int y)
{
	int i = std::upper_bound(a[x] + 1, a[x] + m + 1, y) - a[x];
	if (i > 1) a[x][i - 1] = y;
}

int lower(int i, int j, int k)
{
	int l = max(k - m, 0), r = min(m, k), mid;
	while (l < r)
	{
		mid = (l + r) >> 1;
		if (a[j][k - mid] >= a[i][mid + 1])
			l = mid + 1;
		else r = mid;
	}
	return max(a[i][l], a[j][k - l]);
}

int query(int i, int j, int k)
{
	return lower(i, j, (m << 1 | 1) - k);
}
}

int main()
{
	freopen("familiar.in", "r", stdin);
	freopen("familiar.out", "w", stdout);
	int n, m, t;
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; scanf("%d", a[i] + j++));
	solve::init(m);
	for (int o, x, y, k; t--; )
		if (scanf("%d", &o), o == 1)
			scanf("%d%d%d", &x, &y, &k),
			printf("%d\n", solve::query(x, y, k));
		else scanf("%d%d", &x, &y),
			solve::modi(x, y);
}