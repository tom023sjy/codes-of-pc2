#include <cstdio>
#include <algorithm>
using std::min;
using std::max;
using std::abs;

const int MX = 310;

int a[MX], b[MX];

namespace solve
{
bool f[MX][MX][MX];
int ans[MX];

void solve(int n)
{
	f[1][a[1]][b[1]] = true;
	for (int i = 2; i <= n; i++)
		for (int x = 1; x <= n; x++)
			for (int y = 1; y <= n; y++)
				f[i][max(x, a[i])][max(y, b[i])] |= f[i - 1][x][y],
				f[i][min(x, a[i])][min(y, b[i])] |= f[i - 1][x][y];
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= n; y++)
			ans[abs(x - y)] += f[n][x][y];
}
}

int main()
{
	freopen("maxmin.in", "r", stdin);
	freopen("maxmin.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; scanf("%d", a + i++));
	for (int i = 1; i <= n; scanf("%d", b + i++));
	solve::solve(n);
	for (int i = 0; i < n; printf("%d ", solve::ans[i++]));
}
