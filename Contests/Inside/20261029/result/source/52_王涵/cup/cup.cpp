#include <cstdio>
#include <bitset>
#include <algorithm>
#include <numeric>

const int MX = 2010, MXH = 55;

int h[MX];

namespace solve
{
typedef std::bitset <MX * MXH> st;

namespace DP
{
st f[MXH];
bool vis[MXH];

st DP(int n)
{
	std::sort(h + 1, h + n + 1);
	for (int i = 1; i < n; vis[h[i++]] = true);
	vis[0] = true;
	f[0].set(0);
	st cur;
	for (int i = 1; cur.reset(), i < n; i++)
		for (int j = h[i - 1]; j <= h[n - 1]; j++)
			vis[j] and (f[j] = (cur |= f[j]) << j, true);
	return f[h[n - 1]] << h[n];
}
}

st ans;

void solve(int n)
{
	ans = DP::DP(n) >> std::accumulate(h + 1, h + n + 1, 0);
}
}

int main()
{
	freopen("cup.in", "r", stdin);
	freopen("cup.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; scanf("%d", h + i++));
	solve::solve(n);
	for (int i = solve::ans._Find_first(); i < MX * MXH; i = solve::ans._Find_next(i))
		printf("%d ", i);
}