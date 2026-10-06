#include<bits/stdc++.h>
using namespace std;
#define ls p<<1
#define rs p<<1|1
int n,q,d[100010],id,s[100010][3],t[400040],a[100010],sm;
int o[100010],ll[100010],rr[100010],x[100010];
int e[100010][3];
void pd(int p)
{
	if(t[p])
	{
		t[ls]=t[p];
		t[rs]=t[p];
		t[p]=0;
	}
}
void bd(int p,int pl,int pr)
{
	if(pl==pr)
	{
		t[p]=1;
		return ;
	}
	int mid=(pl+pr)>>1;
	bd(ls,pl,mid),bd(rs,mid+1,pr);
}
void ud(int p,int pl,int pr,int l,int r,int d)
{
	if(l<=pl&&r>=pr)
	{
		t[p]=d;
		return ;
	}
	pd(p);
	int mid=(pl+pr)>>1;
	if(l<=mid) ud(ls,pl,mid,l,r,d);
	if(r>mid) ud(rs,mid+1,pr,l,r,d);
}
int que(int p,int pl,int pr,int d)
{
	if(pl==pr) return t[p]-2;
	pd(p);
	int mid=(pl+pr)>>1;
	if(d<=mid) return que(ls,pl,mid,d);
	else return que(rs,mid+1,pr,d);
}
void dfs(int u)
{
	d[u]=++id;
	if(e[u][1]) dfs(e[u][1]);
	s[u][1]=id-d[u];
	if(e[u][2]) dfs(e[u][2]);
	s[u][2]=id-s[u][1];
}
int dfs1(int u,int sn)
{
	if(u==1)
	{
		if(a[1]==-1)
		{
			if(sn==-1) return 1;
			else if(sn==e[u][1]) return 2;
			else return s[1][1]+2;
		}
		if(a[1]==0)
		{
			if(sn==-1) return s[1][1]+1;
			else if(sn==e[u][1]) return 1;
			else return s[1][1]+2;
		}
		if(a[1]==1)
		{
			if(sn==-1) return s[1][1]+s[1][2]+1;
			else if(sn==e[u][1]) return 1;
			else return s[1][1]+1;
		}
	}
	else
	{
		if(a[u]==-1)
		{
			if(sn==-1) return 1+dfs1(e[u][0],u)-1;
			else if(sn==e[u][1]) return 2+dfs1(e[u][0],u)-1;
			else return s[u][1]+2+dfs1(e[u][0],u)-1;
		}
		if(a[u]==0)
		{
			if(sn==-1) return s[u][1]+1+dfs1(e[u][0],u)-1;
			else if(sn==e[u][1]) return 1+dfs1(e[u][0],u)-1;
			else return s[u][1]+2+dfs1(e[u][0],u)-1;
		}
		if(a[u]==1)
		{
			if(sn==-1) return s[u][1]+s[u][2]+1+dfs1(e[u][0],u)-1;
			else if(sn==e[u][1]) return 1+dfs1(e[u][0],u)-1;
			else return s[u][1]+1+dfs1(e[u][0],u)-1;
		}
	}
}
int dfs2(int u)
{
	if(que(1,1,n,u)==-1)
	{
		d[u]=++id;
	}
	if(e[u][1]) dfs2(e[u][1]);
	if(que(1,1,n,u)==0)
	{
		d[u]=++id;
	}
	if(e[u][2]) dfs2(e[u][2]);
	if(que(1,1,n,u)==1)
	{
		d[u]=++id;
	}
}
int dfs3(int u,int sn)
{
	if(u==1)
	{
		if(que(1,1,n,u)==-1)
		{
			if(sn==-1) return 1;
			else if(sn==e[u][1]) return 2;
			else return s[1][1]+2;
		}
		if(que(1,1,n,u)==0)
		{
			if(sn==-1) return s[1][1]+1;
			else if(sn==e[u][1]) return 1;
			else return s[1][1]+2;
		}
		if(que(1,1,n,u)==1)
		{
			if(sn==-1) return s[1][1]+s[1][2]+1;
			else if(sn==e[u][1]) return 1;
			else return s[1][1]+1;
		}
	}
	else
	{
		if(que(1,1,n,u)==-1)
		{
			if(sn==-1) return 1+dfs3(e[u][0],u)-1;
			else if(sn==e[u][1]) return 2+dfs3(e[u][0],u)-1;
			else return s[u][1]+2+dfs3(e[u][0],u)-1;
		}
		if(que(1,1,n,u)==0)
		{
			if(sn==-1) return s[u][1]+1+dfs3(e[u][0],u)-1;
			else if(sn==e[u][1]) return 1+dfs3(e[u][0],u)-1;
			else return s[u][1]+2+dfs3(e[u][0],u)-1;
		}
		if(que(1,1,n,u)==1)
		{
			if(sn==-1) return s[u][1]+s[u][2]+1+dfs3(e[u][0],u)-1;
			else if(sn==e[u][1]) return 1+dfs3(e[u][0],u)-1;
			else return s[u][1]+1+dfs3(e[u][0],u)-1;
		}
	}
}
int main()
{
	freopen("traversing.in","r",stdin);
	freopen("traversing.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;	
	for(int i=1;i<=n;i++)
	{
		cin>>e[i][1]>>e[i][2];
		if(e[i][1]==0&&e[i][2]==0) sm++;
		e[e[i][1]][0]=e[e[i][2]][0]=i;
	}
	dfs(1);
	bool b1=0,b2=0;
	for(int i=1;i<=q;i++)
	{
		cin>>o[i];
		if(o[i]==1&&b2==1) b1=1;
		if(o[i]==2) b2=1;
		if(o[i]==1) cin>>ll[i]>>rr[i]>>x[i];
		if(o[i]==2) cin>>x[i];
	}
	if(b1==0)
	{
		bd(1,1,n);
		int k;
		for(int i=1;i<=q;i++)
		{
			if(o[i]==1)
			{
				ud(1,1,n,ll[i],rr[i],x[i]+2);
			}
			else 
			{
				k=i;
				break;
			}
		}
		id=0;
		dfs2(1);
		for(int i=k;i<=q;i++) cout<<d[x[i]]<<endl;
	}
	else if(sm==(n+1)/2)
	{
		bd(1,1,n);
		for(int i=1;i<=q;i++)
		{
			if(o[i]==1)
			{
				ud(1,1,n,ll[i],rr[i],x[i]+2);
			}
			else cout<<dfs3(x[i],-1)<<endl;
		}
	}
	else 
	{
		for(int i=1;i<=q;i++)
		{
			if(o[i]==1)
			{
				for(int j=ll[i];j<=rr[i];j++) a[j]=x[i];
			}
			else cout<<dfs1(x[i],-1)<<endl;
		}
	}
	return 0;
}
