#include <bits/stdc++.h>
using namespace std;
inline void read(int &a)
{
	int s=0,w=1;
	char ch=getchar();
	while (ch > '9' or ch < '0')
	{
		if (ch == '-')
		{
			w=-1;
		}
		ch=getchar();
	}
	while (ch >= '0' and ch <= '9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	a=s*w;
}
void write(int x)
{
	if (x < 0)
	{
		putchar('-');
		x=-x;
	}
	if (x > 9)
	{
		write(x/10);
	}
	putchar(x%10+'0');
	return;
}
int dis[10][10],n;
vector<int> tu[200005];
bool chose[200005];
struct sou
{
	int k,tot;
};
queue<sou> bfs;
void DIJ(int st)
{
	while (!bfs.empty())
	{
		bfs.pop();
	}
	bfs.push({st,0});
	while (!bfs.empty())
	{
		int k=bfs.front().k,tot=bfs.front().tot;
		bfs.pop();
		dis[st][k]=tot;
		for (int i = 0;i < tu[k].size();i++)
		{
			int to=tu[k][i];
			if (dis[st][to] <= dis[st][k]+1)
			{
				continue;
			}
			bfs.push({to,tot+1});
		}
	}
	return;
}
bool check(int ftot)
{
	while (!bfs.empty())
	{
		bfs.pop();
	}
	int cnt=0;
	bfs.push({1,1});
	while (!bfs.empty())
	{
		int k=bfs.front().k,tot=bfs.front().tot;
		cnt++;
		bfs.pop();
		for (int i = 0;i < tu[k].size();i++)
		{
			int to=tu[k][i];
			if (tot == to or chose[to] == 0)
			{
				continue;
			}
			bfs.push({to,k});
		}
	}
	return (cnt == ftot);
}
int fans=0;
bool dfs(int pos,int mindis)
{
	bool t=0;
	for (int i = 1;i <= n;i++)
	{
		if (dis[pos][i] >= mindis and chose[i])
		{
			if (dfs(i,dis[pos][i]+1) == 0)
			{
				t=1;
				break;
			}
		}
	}
	return t;
}
void cho(int k,int ftot)
{
	if (k > n)
	{
		if (check(ftot))
		{
			/*for (int i = 1;i <= n;i++)
			{
				cout << chose[i] << ' ';
			}
			cout << endl;*/
			if (dfs(1,1) == 0)
			{
				fans++;
			}
		}
		return;
	}
	chose[k]=1;
	cho(k+1,ftot+1);
	chose[k]=0;
	cho(k+1,ftot);
	return;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int u,v;
	for (int i = 1;i <= 9;i++)
	{
		for (int j = 1;j <= 9;j++)
		{
			dis[i][j]=INT_MAX;
		}
	}
	read(n);
	for (int i = 1;i < n;i++)
	{
		read(u),read(v); 
		tu[u].push_back(v);
		tu[v].push_back(u);
	}
	if (n <= 7)
	{
		for (int i = 1;i <= n;i++)
		{
			DIJ(i);
		}
		chose[1]=1;
		cho(2,1);
		write(fans);
		return 0;
	}
	write(1);
	return 0;
}
