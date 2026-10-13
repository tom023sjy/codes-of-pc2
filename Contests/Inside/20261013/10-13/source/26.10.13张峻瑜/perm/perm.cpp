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
struct fantu
{
	int to,type;
};
bool cmp(fantu a,fantu b)
{
	return a.to < b.to;
}
vector<int> tu[500005];
vector<fantu> ft[500005];
vector<int> xuan[500005];
int fa[500005];
void sou(int k,int f)
{
	fa[k]=f;
	for (int i = 0;i < tu[k].size();i++)
	{
		if (tu[k][i] == f)
		{
			continue;
		}
		sou(tu[k][i],k);
	}
	return;
}
void dfs(int k,int dep,int todep,int st)
{
	if (dep < todep and k != st)
	{
		ft[k].push_back({st,1});
	}
	if (dep == todep and k != st)
	{
		ft[st].push_back({k,0});
		xuan[k].push_back(st);
		return;
	}
	for (int i = 0;i < tu[k].size();i++)
	{
		int to=tu[k][i];
		if (to == fa[k])
		{
			continue;
		}
		dfs(to,dep+1,todep,st);
	}
	return;
}
bool pan[500005];
int pos=1;
int ans[500005],d[500005];
bool chosepan[500005];
void solve(int k)
{
	//cout << k << endl;
	if (pan[k])
	{
		return;
	}
	for (int i = 0;i < ft[k].size();i++)
	{
		if ((ft[k][i].type == 0 and chosepan[k] == 0) or (ft[k][i].type == 0 and ft[k][i].to < k))
		{
			for (int z = 0;z < xuan[ft[k][i].to].size();z++)
			{
				chosepan[xuan[ft[k][i].to][z]]=1;
			}
			//chosepan[k]=1;
			solve(ft[k][i].to);
		}
		else if (ft[k][i].type == 1)
		{
			solve(ft[k][i].to);
		}
	}
	pan[k]=1;
	ans[pos]=k;
	pos++;
	return;
}
int main()
{
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	int n,u,v;
	read(n);
	for (int i = 1;i <= n;i++)
	{
		read(d[i]);
		if (d[i] == 0)
		{
			write(-1);
			return 0;
		}
	}
	for (int i = 1;i < n;i++)
	{
		read(u),read(v);
		tu[u].push_back(v);
		tu[v].push_back(u);
	}
	sou(1,1);
	for (int i = 1;i <= n;i++)
	{
		if (d[i] == -1)
		{
			dfs(i,0,INT_MAX,i);
		}
		else
		{
			dfs(i,0,d[i],i);
		}
	}
	for (int i = 1;i <= n;i++)
	{
		sort(ft[i].begin(),ft[i].end(),cmp);
		/*cout << i << ":";
		for (int j = 0;j < ft[i].size();j++)
		{
			if (ft[i][j].type == 0)
			{
				cout << ft[i][j].to << "* ";
			}
			else
			{
				cout << ft[i][j].to << " ";
			}
			
		}
		cout << endl;*/
	}
	for (int i = 1;i <= n;i++)
	{
		if (pan[i] == 0)
		{
			solve(i);
		}
		
	}
	/*for (int i = 1;i <= js;i++)
	{
		int minn=INT_MAX,hao=0;
		for (int j = 1;j <= js;j++)
		{
			if (ans[fd[j].l] < minn and fd[j].chose==0)
			{
				minn=ans[fd[j].l];
				hao=j;
			}
		}
		fd[hao].chose=1;
		for (int j = fd[hao].l;j <= fd[hao].r;j++)
		{
			write(ans[j]);
			putchar(' ');
		}
	}*/
	for (int i = 1;i <= n;i++)
	{
		write(ans[i]);
		putchar(' ');
	}
	return 0;
}
