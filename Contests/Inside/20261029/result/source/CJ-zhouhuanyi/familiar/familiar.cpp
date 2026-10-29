#include<iostream>
#include<cstdio>
#include<cmath>
#define N 1000
#define inf 1e9
using namespace std;
int read()
{
	char c=0;
	int sum=0;
	while (c<'0'||c>'9') c=getchar();
	while ('0'<=c&&c<='9') sum=sum*10+c-'0',c=getchar();
	return sum; 
}
int n,m,T,a[N+1][N+1];
int F(int x,int d)
{
	return lower_bound(a[x]+1,a[x]+m+1,d+1)-a[x]-1;
}
int main()
{
	freopen("familiar.in","r",stdin);
	freopen("familiar.out","w",stdout);
	int op,x,y,k,ps,d;
	n=read(),m=read(),T=read();
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			a[i][j]=read();
	while (T--)
	{
		op=read();
		if (op==1)
		{
			x=read(),y=read(),k=(m<<1)+1-read(),d=0;
			for (int i=log(inf)/log(2);i>=0;--i)
				if (d+(1<<i)<=inf&&F(x,d+(1<<i))+F(y,d+(1<<i))<k)
					d+=(1<<i);
			printf("%d\n",d+1);
		}
		else
		{
			x=read(),k=read(),ps=lower_bound(a[x]+1,a[x]+m+1,k+1)-a[x]-1;
		    if (ps) a[x][ps]=k;
		}
	}
	return 0;
}
