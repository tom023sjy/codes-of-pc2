#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000001
#define inf 1e18
using namespace std;
int read()
{
	char c=0;
	int sum=0;
	while (c<'0'||c>'9') c=getchar();
	while ('0'<=c&&c<='9') sum=sum*10+c-'0',c=getchar();
	return sum; 
}
long long n,tong[N+1],length,k[N+1],ps[N+1],s[N+1],dp[N+1],c[2][N+1],ans;
int lowbit(int x)
{
	return x&(-x);
}
void add(int op,int x,long long d)
{
	for (;x<=length;x+=lowbit(x)) c[op][x]=min(c[op][x],d);
	return;
}
long long Sum(int op,int x)
{
	long long res=inf;
	for (;x>=1;x-=lowbit(x)) res=min(res,c[op][x]);
	return res;
}
int main()
{
	freopen("express.in","r",stdin);
	freopen("express.out","w",stdout);
	n=read(),ans=inf;
	for (int i=2;i<=n+1;++i) k[i]=read();
	for (int i=1;i<=n+1;++i) tong[++length]=k[i];
	sort(tong+1,tong+length+1),length=unique(tong+1,tong+length+1)-tong-1;
	for (int i=1;i<=length;++i) c[0][i]=c[1][i]=inf;
	for (int i=1;i<=n+1;++i) s[i]=s[i-1]+abs(k[i]-k[i-1]);
	for (int i=0;i<=n+1;++i) ps[i]=lower_bound(tong+1,tong+length+1,k[i])-tong;
	for (int i=1;i<=n+1;++i)
	{
		if (i!=1) dp[i]=min(Sum(0,ps[i])+k[i]+s[i-1],Sum(1,length+1-ps[i])-k[i]+s[i-1]);
		add(0,ps[i-1],dp[i]-k[i-1]-s[i]),add(1,length+1-ps[i-1],dp[i]+k[i-1]-s[i]);
	}
	for (int i=1;i<=n+1;++i) ans=min(ans,dp[i]+s[n+1]-s[i]);
	printf("%lld\n",ans);
	return 0;
}
