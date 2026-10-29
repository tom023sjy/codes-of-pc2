#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 500
#define M 50000
using namespace std;
int read()
{
	char c=0;
	int sum=0;
	while (c<'0'||c>'9') c=getchar();
	while ('0'<=c&&c<='9') sum=sum*10+c-'0',c=getchar();
	return sum; 
}
int n,p[N+1],h[N+1],hs[N+1],p1[N+1],p2[N+1],res;
bool used[M+1];
int main()
{
	freopen("cup.in","r",stdin);
	freopen("cup.ans","w",stdout);
	n=read();
	for (int i=1;i<=n;++i) p[i]=i,h[i]=read();
	do
	{
		res=0;
		for (int i=1;i<=n;++i) hs[i]=h[p[i]];
		p1[1]=hs[1],p2[n]=hs[n];
		for (int i=2;i<=n;++i) p1[i]=max(p1[i-1],hs[i]);
		for (int i=n-1;i>=1;--i) p2[i]=max(p2[i+1],hs[i]);
		for (int i=2;i<=n-1;++i) res+=max(min(p1[i],p2[i])-hs[i],0);
		used[res]=1;
	}
	while (next_permutation(p+1,p+n+1));
	for (int i=0;i<=M;++i)
		if (used[i])
			printf("%d ",i);
	puts("");
	return 0;
}
