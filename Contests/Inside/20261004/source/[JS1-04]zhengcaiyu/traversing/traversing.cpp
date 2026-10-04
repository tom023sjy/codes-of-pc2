#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e5+4;
struct G
{
	int l,r,now;
}a[N];
struct ques
{
	int op,l,r,x;
}Q[N];
int ans,to;
bool f;
inline int read()
{
	int sum=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum*f;
}
void dfs(int p)
{
	if(p==0) return;
	if(a[p].now==-1)
	{
		++ans;
		if(p==to) f=true;
		if(f) return;
		dfs(a[p].l);
		if(f) return;
		dfs(a[p].r);
		if(f) return;
	}
	if(a[p].now==0)
	{
		dfs(a[p].l);
		if(f) return;
		++ans;
		if(p==to) f=true;
		if(f) return;
		dfs(a[p].r);
		if(f) return;
	}
	if(a[p].now==1)
	{
		dfs(a[p].l);
		if(f) return;
		dfs(a[p].r);
		if(f) return;
		++ans;
		if(p==to) f=true;
		if(f) return;
	}
}
int main()
{
	freopen("traversing.in","r",stdin);
	freopen("traversing.out","w",stdout);
	int n=read(),q=read();
	for(int i=1;i<=n;++i)
	{
		a[i].l=read();
		a[i].r=read();
		a[i].now=-1;
	}
	for(int i=1;i<=q;++i)
	{
		int op=read();
		if(op==1)
		{
			int l=read(),r=read(),x=read();
			Q[i]={op,l,r,x};
		}
		else Q[i]={op,0,0,read()};
	}
	for(int j=1;j<=q;++j)
	{
		if(Q[j].op==1) for(int i=Q[j].l;i<=Q[j].r;++i) a[i].now=Q[j].x;
		else
		{
			f=false;
			ans=0;
			to=Q[j].x;
			dfs(1);
			printf("%d\n",ans);
		}
	}
}
