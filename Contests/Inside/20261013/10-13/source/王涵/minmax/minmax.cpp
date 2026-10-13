#include <cstdio>
#include <vector>
#include <map>

const int MX = 100010;

int a[MX], b[MX];

namespace solve
{
bool solve(int n, int m)
{
	std::map <int, std::vector <int> > pos;
	for (int i = n; i; i--)
		pos[a[i]].push_back(i);
	for (int i = 1, cur = 0; i <= m; i++)
	{
		auto& v = pos[b[i]];
		for (; not v.empty() and v.back() <= cur; v.pop_back());
		if (v.empty()) return false;
		cur = v.back();
	}
	return true;
}
}

int main()
{
	freopen("minmax.in", "r", stdin);
	freopen("minmax.out", "w", stdout);
	int t, n, m;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; scanf("%d", a + i++));
		for (int i = 1; i <= m; scanf("%d", b + i++));
		printf("%s\n", solve::solve(n, m) ? "Yes" : "No");
	}
}
