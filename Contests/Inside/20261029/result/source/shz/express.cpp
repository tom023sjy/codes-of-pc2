#include <bits/stdc++.h>
using namespace std;
const int N=1000002;
#define lowbit(x) (x&(-x))
#define ll long long
const ll inf=100000000000000000;
int n;
ll tree[N][2],dp[N];
inline void add(int x,ll k,int tp)
{
	if (tp==1) x=n+1-x;
	for (;x<=n;x+=lowbit(x)) tree[x][tp]=min(tree[x][tp],k);
}
inline ll ask(int x,int tp)
{
	if (tp==1) x=n+1-x;
	ll ans=inf;
	for (;x;x-=lowbit(x)) ans=min(ans,tree[x][tp]);
	return ans;
}
inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
ll a[N],b[N];
int c[N];
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
int main()
{
	freopen("express.in","r",stdin);
	freopen("express.out","w",stdout);
	n=read();
	++n;
	a[1]=0,c[1]=1;
	for (int i=2;i<=n;i++) a[i]=read(),c[i]=i;
	sort(c+1,c+n+1,cmp);
	for (int i=1;i<=n;i++) b[c[i]]=i;
	ll sum=0,ans=inf;
	for (int i=1;i<=n;i++) tree[i][0]=inf,tree[i][1]=inf;
	for (int i=1;i<=n;i++) dp[i]=inf;
	add(b[1],0,0),add(b[1],0,1);
	dp[b[1]]=0;
	for (int i=2;i<=n;i++)
	{
		ll res=sum;
		sum+=abs(a[i]-a[i-1]);
		ll w=inf;
		w=min(w,ask(b[i],0)+a[i]);
		w=min(w,ask(b[i],1)-a[i]);
		w+=res;
		dp[b[i-1]]=min(dp[b[i-1]],w-sum);
		ans=min(ans,w);
		add(b[i-1],w-a[i-1]-sum,0);
		add(b[i-1],w+a[i-1]-sum,1);
	}
	for (int i=1;i<=n;i++) ans=min(ans,dp[i]);
	cout << ans+sum;
	return 0;
}