#include <bits/stdc++.h>
using namespace std;
int n, q, cnt;
int way[100010], sorted[100010], lc[100010], rc[100010];

void input(int &n)
{
	cin >> n;
}

void output(int n, char c)
{
	cout << n << c;
}

void output(char c)
{
	cout << c;
}

inline void dfs(int root) 
{
	switch(way[root])
	{
		case -1:
			sorted[root] = ++cnt;
			if (lc[root])
			{
				dfs(lc[root]);
			}
			if (rc[root])
			{
				dfs(rc[root]);
			}
			break;
		case 0:
			if (lc[root])
			{
				dfs(lc[root]);
			}
			sorted[root] = ++cnt;
			if (rc[root])
			{
				dfs(rc[root]);
			}
			break;
		case 1:
			if (lc[root])
			{
				dfs(lc[root]);
			}
			if (rc[root])
			{
				dfs(rc[root]);
			}
			sorted[root] = ++cnt;
			break;
	}
}

inline void bl()//是暴力吗？不是，是遍历。
{
	cnt = 0;
	memset(sorted, 0, sizeof sorted);
	dfs(1);
}

int main()
{
	freopen("traversing.in", "r", stdin);
	freopen("traversing.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0ll), cout.tie(0ll);
	srand((unsigned) time (NULL));
	input(n), input(q);
	for (int i = 1; i <= n; i++)
	{
		input(lc[i]), input(rc[i]);
	}
	memset(way, -1, sizeof way);
	bl();
	for (int i = 1; i <= q; i++)
	{
		int op;
		input(op);
		if (op == 1)
		{
			int l, r, x;
			input(l), input(r), input(x);
			for (int i = l; i <= r; i++)
			{
				way[i] = x;
			}
			bl();
		}
		else
		{
			int k;
			input(k);
			output(sorted[k], '\n');
		}
	}
	return 0;
}
