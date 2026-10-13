#include <cstdio>
#include <vector>
#include <algorithm>
using std::max;
#define maxx(A, B) (A = max(A, B))
typedef long long intt;

const int MX = 200010, P = 1e9 + 7;

std::vector <int> T[MX];

namespace solve
{
inline int md(int x) { return x >= P ? x - P : x; }
inline void add(int& x, int y) { (x += y) >= P and (x -= P); }

namespace inv
{
const int B = 1010, B2 = B * B, MXB2 = B2 + 10;
struct frac
{
	int a, b;
} pre[MXB2], nxt[MXB2];

int _inv[MXB2];

void init()
{
	for (int i = 1; i <= B; i++)
		for (int j = 0; j <= i; j++)
			if (not (pre[j * B2 / i].b))
				pre[j * B2 / i] = nxt[j * B2 / i] = { j, i };
	for (int i = 0; i <= B2; i++)
		pre[i] = pre[i - not pre[i].b];
	for (int i = B2; ~i; i--)
		nxt[i] = nxt[i + not nxt[i].b];
	_inv[1] = 1;
	for (int i = 2; i <= B2; _inv[i] = (intt)(P - P / i) * _inv[P % i] % P, i++);
}

int inv(int x)
{
	int i = (intt)x * B2 / P;
	const auto& f = abs((intt)x * pre[i].b - (intt)pre[i].a * P) <= B2 ? pre[i] : nxt[i];
	int t = (intt)x * f.b - (intt)f.a * P;
	return (intt)(t > 0 ? _inv[t] : P - _inv[-t]) * f.b % P;
}
}

namespace DP
{
namespace D
{
int fa[MX], dep[MX], mxd[MX], ls[MX], pos[MX];

void DFS(int u)
{
	mxd[u] = dep[u];
	for (int v : T[u])
		if (v != fa[u])
			fa[v] = u,
			dep[v] = dep[u] + 1,
			DFS(v),
			maxx(mxd[u], mxd[v]),
			ls[u] = mxd[v] > mxd[ls[u]] ? v : ls[u];
}

void DFS1(int u)
{
	static int tot;
	pos[u] = ++tot;
	if (ls[u])
		DFS1(ls[u]);
	for (int v : T[u])
		if (v != fa[u] and v != ls[u])
			DFS1(v);
}
}

using D::fa;
using D::dep;
using D::mxd;
int f[MX], m[MX], a[MX];
std::vector <int> res[MX];

void init(int n) { std::fill(m + 1, m + n + 1, 1); }

inline int at(int u, int i) { return dep[u] + i <= mxd[u] ? D::pos[u] + i : 0; }

inline void addsuf(int u, int i, int x) { add(f[at(u, i)], x); add(a[at(u, i)], x); }
inline void mulsuf(int u, int i, int x) { f[at(u, i)] = (intt)f[at(u, i)] * x % P; m[at(u, i)] = (intt)m[at(u, i)] * x % P; a[at(u, i)] = (intt)a[at(u, i)] * x % P; }
inline void addu(int u, int i, int x) { add(f[at(u, i)], x); }
inline void mulu(int u, int i, int x) { f[at(u, i)] = (intt)f[at(u, i)] * x % P; }
inline void push_down(int u, int i) { if (m[at(u, i)] != 1 or a[at(u, i)]) mulsuf(u, i + 1, m[at(u, i)]), addsuf(u, i + 1, a[at(u, i)]), m[at(u, i)] = 1, a[at(u, i)] = 0; }

void merge(int u, int v)
{
	int len = mxd[v] - dep[v];
	push_down(u, 0);
	for (int i = 0, cur = 0, pre = 0; i <= len; i++)
		push_down(u, i + 1),
		push_down(v, i),
		mulu(u, i + 1, f[at(v, i)]);
	mulsuf(u, len + 2, f[at(v, len)]);
}

std::vector <int> get(int u)
{
	int len = mxd[u] - dep[u];
	std::vector <int> v(len + 1);
	for (int i = 0; i <= len; i++)
		push_down(u, i),
		v[i] = f[at(u, i)];
	return v;
}

void DFS(int u)
{
	if (D::ls[u])
		DFS(D::ls[u]);
	addu(u, 0, 1);
	for (int v : T[u])
		if (v != fa[u] and v != D::ls[u])
			DFS(v),
			merge(u, v);
	if (u != 1)
		addsuf(u, 0, 1);
	if (fa[u] == 1 or u == 1)
		res[u] = get(u);
}

void DP(int n)
{
	D::DFS(1);
	D::DFS1(1);
	init(n);
	DFS(1);
}
}

int solve(int n)
{
	inv::init();
	DP::DP(n);
	auto pd = DP::res[1];
	for (int i = pd.size() - 1; i; add(pd[i], P - pd[i - 1]), i--);
	std::vector <std::vector <int> > f;
	for (int v : T[1])
		f.push_back(DP::res[v]),
		f.back().insert(f.back().begin(), 1);
	std::sort(f.begin(), f.end(), [](const auto& a, const auto& b) -> bool { return a.size() < b.size(); });
	for (int d = 0, cur = 1, c0 = 0, i = 0; d < pd.size(); d++)
	{
		const auto mul = [&](int x) -> void { x ? cur = (intt)cur * x % P : c0++; };
		const auto div = [&](int x) -> void { x ? cur = (intt)cur * inv::inv(x) % P : c0--; };
		const auto query = [&]() -> int { return c0 ? 0 : cur; };

		for (; i < f.size() and f[i].size() <= d; i++);
		for (int j = i; j < f.size(); j++)
			d and (div(f[j][d - 1]), true), mul(f[j][d]);
		for (int j = i; j < f.size(); j++)
			if (f[j].size() > d + 1)
				div(f[j][d]),
				mul(md(f[j][d + 1] + P - f[j][d])),
				add(pd[d + 1], P - query()),
				div(md(f[j][d + 1] + P - f[j][d])),
				mul(f[j][d]);
	}
	int ret = 0;
	for (int i = 0; i < pd.size(); i++)
		add(ret, pd[i]);
	return ret;
}
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++)
		scanf("%d%d", &u, &v),
		T[u].push_back(v),
		T[v].push_back(u);
	printf("%d", solve::solve(n));
}
