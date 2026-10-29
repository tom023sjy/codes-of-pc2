#include<iostream>
#include<cstdio>
#define N 20
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
long long n,k[N+1],x,y,res,ans;
int main()
{
	freopen("express.in","r",stdin);
	freopen("express.ans","w",stdout);
	n=read(),ans=inf;
	for (int i=1;i<=n;++i) k[i]=read();
	for (int i=0;i<(1<<n);++i)
	{
		x=y=res=0;
		for (int j=1;j<=n;++j)
		{
			if (i&(1<<(j-1))) res+=abs(k[j]-k[x]),x=j;
			else res+=abs(k[j]-k[y]),y=j;
		}
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}
