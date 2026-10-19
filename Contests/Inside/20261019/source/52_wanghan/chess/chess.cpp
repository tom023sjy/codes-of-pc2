#include <cstdio>
#include <algorithm>
#include <numeric>
using std::max;
#define maxx(A, B) (A =  max(A, B))
typedef long long intt;

const int MX = 100010, MXR = 5010;

int lx[MX], ly[MX], rx[MX], ry[MX], c[MX];

namespace solve
{
inline intt C2(int n) { return (intt)n * (n - 1) >> 1; }

inline bool pass(int i, int x, int y) { return x < lx[i] or x > rx[i] or y < ly[i] or y > ry[i]; }

int h, w;

struct node
{
	int cll, clr, crl, crr, cllrr, clrrl;

	node() = default;
	node(int i):
		cll(c[i] * not pass(i, h, w)),
		clr(c[i] * not pass(i, h, 1)),
		crl(c[i] * not pass(i, 1, w)),
		crr(c[i] * not pass(i, 1, 1)),
		cllrr(c[i] * (pass(i, 1, 1) and pass(i, h, w))),
		clrrl(c[i] * (pass(i, 1, w) and pass(i, h, 1))) {}
	node(int cll, int clr, int crl, int crr, int cllrr, int clrrl): cll(cll), clr(clr), crl(crl), crr(crr), cllrr(cllrr), clrrl(clrrl) {}

	node operator+ (const node& oth) const { return { cll + oth.cll, clr + oth.clr, crl + oth.crl, crr + oth.crr, cllrr + oth.cllrr, clrrl + oth.clrrl }; }
	void operator+= (const node& oth) { *this = *this + oth; }
	node operator- (const node& oth) const { return { cll - oth.cll, clr - oth.clr, crl - oth.crl, crr - oth.crr, cllrr - oth.cllrr, clrrl - oth.clrrl }; }
	void operator-= (const node& oth) { *this = *this - oth; }

	intt query(int sc) const { return max(max(C2(cll + cllrr) + C2(crr), C2(cll) + C2(crr + cllrr)), max(C2(clr + clrrl) + C2(crl), C2(clr) + C2(crl + clrrl))) + C2(sc - cll - crr - cllrr); }
};

intt solve(int n, int h, int w)
{
	solve::h = h;
	solve::w = w;
	static node diff[MXR][MXR];
	for (int i = 1; i <= n; i++)
		diff[lx[i]][ly[i]] += node(i),
		diff[lx[i]][ry[i] + 1] -= node(i),
		diff[rx[i] + 1][ly[i]] -= node(i),
		diff[rx[i] + 1][ry[i] + 1] += node(i);
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			diff[i][j] += diff[i][j - 1];
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			diff[i][j] += diff[i - 1][j];
	node sum{};
	int sc = std::accumulate(c + 1, c + n + 1, 0);
	for (int i = 1; i <= n; sum += node(i++));
	intt ret = sum.query(sc);
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			maxx(ret, diff[i][j].query(sc));
	return ret;
}
}

int main()
{
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int n, h, w;
	scanf("%*d%d%d%d", &n, &h, &w);
	for (int i = 1; i <= n; scanf("%d%d%d%d%d", lx + i, ly + i, rx + i, ry + i, c + i), i++);
	printf("%lld", solve::solve(n, h, w));
}