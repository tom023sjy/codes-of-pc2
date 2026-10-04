#include <bits/stdc++.h>
using namespace std;
int a[15][15], b[15][15], c[15][15], n, f[15][15];
bool vis[15][15];
struct S
{
	int x, y;
} e[305];
struct sb
{
	S a, b, c;
} d[300];
void f1()
{
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			c[i][j] = a[i][j];
		}
	}
	int cur = 0;
	queue <S> q;
	q.push({1, 1});
	q.push({n, 1});
	q.push({n, n});
	vis[1][1] = 1;
	vis[n][1] = 1;
	vis[n][n] = 1;
	d[++cur] = {{1, 1}, {n, 1}, {n, n}};
	while(!q.empty())
	{
		int X1 = q.front().x, Y1 = q.front().y;
		q.pop();
		int X2 = q.front().x, Y2 = q.front().y;
		q.pop();
		int X3 = q.front().x, Y3 = q.front().y;
		q.pop();
		if(vis[X1 + 1][Y1] == 0 && vis[X2][Y2 + 1] == 0 && vis[X3 - 1][Y3 - 1] == 0)
		{
			vis[X1 + 1][Y1] = 1;
			vis[X2][Y2 + 1] = 1;
			vis[X3 - 1][Y3 - 1] = 1;
			q.push({X1 + 1, Y1});
			q.push({X2, Y2 + 1});
			q.push({X3 - 1, Y3 - 1});
			d[++cur] = {{X1 + 1, Y1}, {X2, Y2 + 1}, {X3 - 1, Y3 - 1}};
		}
		if(vis[X1 + 1][Y1 + 1] == 0 && vis[X2 - 1][Y2] == 0 && vis[X3][Y3 - 1] == 0)
		{
			vis[X1 + 1][Y1 + 1] = 1;
			vis[X2 - 1][Y2] = 1;
			vis[X3][Y3 - 1] = 1;
			q.push({X1 + 1, Y1 + 1});
			q.push({X2 - 1, Y2});
			q.push({X3, Y3 - 1});
			d[++cur] = {{X1 + 1, Y1 + 1}, {X2 - 1, Y2}, {X3, Y3 - 1}};
		}
	}
	for(int i = 1; i <= cur; i++)
	{
		int X1 = d[i].a.x, Y1 = d[i].a.y;
		int X2 = d[i].b.x, Y2 = d[i].b.y;
		int X3 = d[i].c.x, Y3 = d[i].c.y;
		a[X1][Y1] = c[X2][Y2];
		a[X2][Y2] = c[X3][Y3];
		a[X3][Y3] = c[X1][Y1];
	}
}
void f2()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			c[i][j] = a[i][j];
		}
	}
	int cur = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			if(i + j > n + 1) continue;
			int p  = n - i, q = 1 - j;
			a[i][j] = c[n + q][1 + p];
			a[n + q][1 + p] = c[i][j];
		}
	}
}
int check()
{
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			cnt += (a[i][j] != b[i][j]);
		}
	}
	return cnt;
}
int main()
{
	freopen("triangle.in", "r", stdin);
	freopen("triangle.out", "w", stdout);
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			cin>>b[i][j];
		}
	}
	int minn = 1e9;
	for(int i = 1; i <= 3; i++)
	{
		f1();
		minn = min(minn, check());
		f2();
		minn = min(minn, check());
		f2();
	}
	cout<<minn;
	return 0;
}
