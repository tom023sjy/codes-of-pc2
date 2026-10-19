#include <cstdio>
#include <cstring>
typedef long long intt;

const int MX = 5010, P = 1e9 + 7;

char s[MX];

namespace solve
{
inline void add(int& x, int y) { (x += y) >= P and (x -= P); }
inline void add(int& x, intt y) { x = (x + y) % P; }

namespace pc
{
int fac[MX];

void init(int n)
{
	fac[0] = 1;
	for (int i = 1; i <= n; fac[i] = (intt)fac[i - 1] * i % P, i++);
}
}

namespace DP
{
int f[MX][MX][2], g[MX][MX][2], ans[MX];

inline int A2(int n) { return (intt)n * (n - 1) % P; }

void DPf(int n)
{
	f[0][0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++)
			if (s[i] == 'U')
				add(f[i][j + 1][0], f[i - 1][j][0]),
				add(f[i][j + 1][1], f[i - 1][j][1]),
				add(f[i][j][0], (intt)j * f[i - 1][j][0]),
				add(f[i][j][1], (intt)(j + 1) * f[i - 1][j][1]),
				add(f[i][j][1], f[i - 1][j][0]);
			else if (j)
				add(f[i][j - 1][0], (intt)A2(j) * f[i - 1][j][0]),
				add(f[i][j - 1][1], (intt)A2(j) * f[i - 1][j][1]),
				add(f[i][j - 1][1], (intt)j * f[i - 1][j][1]),
				add(f[i][j][0], (intt)j * f[i - 1][j][0]),
				add(f[i][j][1], (intt)j * f[i - 1][j][1]),
				add(f[i][j - 1][1], (intt)j * f[i - 1][j][0]);
}

void DPg(int n)
{
	g[n + 1][0][0] = 1;
	for (int i = n; i; i--)
		for (int j = 0; j <= n - i; j++)
			if (s[i] == 'D')
				add(g[i][j + 1][0], g[i + 1][j][0]),
				add(g[i][j + 1][1], g[i + 1][j][1]),
				add(g[i][j][0], (intt)j * g[i + 1][j][0]),
				add(g[i][j][1], (intt)(j + 1) * g[i + 1][j][1]),
				add(g[i][j][1], g[i + 1][j][0]);
			else if (j)
				add(g[i][j - 1][0], (intt)A2(j) * g[i + 1][j][0]),
				add(g[i][j - 1][1], (intt)A2(j) * g[i + 1][j][1]),
				add(g[i][j - 1][1], (intt)j * g[i + 1][j][1]),
				add(g[i][j][0], (intt)j * g[i + 1][j][0]),
				add(g[i][j][1], (intt)j * g[i + 1][j][1]),
				add(g[i][j - 1][1], (intt)j * g[i + 1][j][0]);
}

void DP(int n)
{
	if (n == 1) return ans[1] = 1, void();
	DPf(n);
	DPg(n);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i and j <= n - i; j++)
			add(ans[i], ((intt)f[i - 1][j][0] * g[i + 1][j][1] + (intt)f[i - 1][j][1] * g[i + 1][j][0]) % P * pc::fac[j] % P * pc::fac[j]),
			add(ans[i], ((intt)f[i - 1][j + 1][0] * g[i + 1][j][1] + (intt)f[i - 1][j][1] * g[i + 1][j + 1][0]) % P * pc::fac[j + 1] % P * pc::fac[j]);
}
}

using DP::ans;

void solve(int n)
{
	pc::init(n);
	DP::DP(n);
}
}

int main()
{
	freopen("mountain.in", "r", stdin);
	freopen("mountain.out", "w", stdout);
	int n;
	scanf("%*d%s", s + 1);
	solve::solve(n = strlen(s + 1));
	for (int i = 1; i <= n; printf("%d ", solve::ans[i++]));
}