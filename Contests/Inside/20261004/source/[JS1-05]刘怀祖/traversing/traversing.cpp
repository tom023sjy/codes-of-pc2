#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q,ch[N][2],p[N],id[N],cnt;
void dfs(int x)
{
	if(!x)return;
	if(p[x]==-1)id[x]=++cnt;
	dfs(ch[x][0]);
	if(!p[x])id[x]=++cnt;
	dfs(ch[x][1]);
	if(p[x]==1)id[x]=++cnt;
}
int main()
{
	freopen("traversing.in","r",stdin);
	freopen("traversing.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&ch[i][0],&ch[i][1]);
		p[i]=-1;
	}
	int op,l,r,x;
	bool mdf=1;
	while(q--)
	{
		scanf("%d%d",&op,&l);
		if(op==1)
		{
			scanf("%d%d",&r,&x);
			for(int i=l;i<=r;i++)p[i]=x;
			mdf=1;
		}
		else
		{
			if(mdf)
			{
				cnt=0;
				dfs(1);
				mdf=0;
			}
			printf("%d\n",id[l]);
		}
	}
	return 0;
}
