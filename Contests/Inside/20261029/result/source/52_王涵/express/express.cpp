#include <cstdio>
#include <algorithm>
#include <cstring>
using std::min;
#define minx(A, B) (A = min(A, B))
using std::abs;
#define INF 1e18
typedef long long intt;

const int MX = 1000010;

int k[MX];

namespace solve
{
namespace disc
{
int num[MX];

int disc(int n)
{
	memcpy(num + 1, k + 1, sizeof(int) * n);
	std::sort(num + 1, num + n + 1);
	int q = std::unique(num + 1, num + n + 1) - num - 1;
	for (int i = 1; i <= n; k[i] = std::lower_bound(num + 1, num + q + 1, k[i]) - num, i++);
	return q;
}
}

namespace sgt
{
intt mn[MX << 2], mnpx[MX << 2], mnnx[MX << 2], mark[MX << 2];
int n;

void push_up(int p)
{
	mn[p] = min(mn[p << 1], mn[p << 1 | 1]);
	mnpx[p] = min(mnpx[p << 1], mnpx[p << 1 | 1]);
	mnnx[p] = min(mnnx[p << 1], mnnx[p << 1 | 1]);
}

void build(int p = 1, int cl = 0, int cr = n)
{
	if (cl == cr)
		mn[p] = mnpx[p] = mnnx[p] = (bool)cl * INF;
	else
	{
		int mid = (cl + cr) >> 1;
		build(p << 1, cl, mid);
		build(p << 1 | 1, mid + 1, cr);
		push_up(p);
	}
}

void push_tag(int p, intt x)
{
	mn[p] += x;
	mnpx[p] += x;
	mnnx[p] += x;
	mark[p] += x;
}

void push_down(int p)
{
	if (mark[p])
		push_tag(p << 1, mark[p]),
		push_tag(p << 1 | 1, mark[p]),
		mark[p] = 0;
}

void add(int x) { push_tag(1, x); }

void update(int x, intt v, int p = 1, int cl = 0, int cr = n)
{
	if (cl == cr)
		minx(mn[p], v),
		minx(mnpx[p], v + disc::num[cl]),
		minx(mnnx[p], v - disc::num[cl]);
	else
	{
		push_down(p);
		int mid = (cl + cr) >> 1;
		if (x <= mid)
			update(x, v, p << 1, cl, mid);
		else
			update(x, v, p << 1 | 1, mid + 1, cr);
		push_up(p);
	}
}

template <typename F>
intt query(const F& f, int l, int r, int p = 1, int cl = 0, int cr = n)
{
	if (l <= cl and cr <= r)
		return f(mn[p], mnpx[p], mnnx[p]);
	else
	{
		push_down(p);
		int mid = (cl + cr) >> 1;
		intt ret = INF;
		if (l <= mid)
			minx(ret, query(f, l, r, p << 1, cl, mid));
		if (mid < r)
			minx(ret, query(f, l, r, p << 1 | 1, mid + 1, cr));
		return ret;
	}
}
}

namespace DP
{
intt DP(int n)
{
	for (int i = 1; i <= n; i++)
	{
		intt t = min(sgt::query([](intt, intt p, intt) -> intt { return p; }, k[i], sgt::n) - disc::num[k[i]], disc::num[k[i]] + sgt::query([](intt, intt, intt n) -> intt { return n; }, 0, k[i]));
		sgt::add(abs(disc::num[k[i]] - disc::num[k[i - 1]]));
		sgt::update(k[i - 1], t);
	}
	return sgt::query([](intt m, intt, intt) -> intt { return m; }, 0, sgt::n);
}
}

intt solve(int n)
{
	sgt::n = disc::disc(n);
	sgt::build();
	return DP::DP(n);
}
}

int main()
{
	freopen("express.in", "r", stdin);
	freopen("express.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; scanf("%d", k + i++));
	printf("%lld", solve::solve(n));
}