#include <bits/stdc++.h>
using namespace std;
const int N=1002;
int n,m,T;
vector<int>a[N];
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
int ask(int x,int y,int k)
{
	int l1=0,r1=m-1,l2=0,r2=m-1;
	while (l1<=r1&&l2<=r2)
	{
		int m1=(l1+r1)>>1,m2=(l2+r2)>>1;
		int cnt=m1+m2+1;
		if (a[x][m1]<=a[y][m2])
		{
			if (cnt<k) l1=m1+1;
			else r2=m2-1;
		}
		else
		{
			if (cnt<k) l2=m2+1;
			else r1=m1-1;
		}
	}
	
	if (l1>r1)
	{
		if (l1==0) return a[y][k-1];
		return max(a[x][l1-1],a[y][k-1-l1]);
	}
	else
	{
		if (l2==0) return a[x][k-1];
		return max(a[y][l2-1],a[x][k-1-l2]);
	}
}
int main()
{
	freopen("familiar.in","r",stdin);
	freopen("familiar.out","w",stdout);
	n=read(),m=read(),T=read();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			int x=read();
			a[i].push_back(x);
		}
	}
	while (T--)
	{
		int op=read(),x=read(),y=read();
		if (op==1)
		{
			int k=read();
			printf("%d\n",ask(x,y,m+m+1-k));
		}
		else
		{
			int d=upper_bound(a[x].begin(),a[x].end(),y)-a[x].begin()-1;
			if (d==-1) continue;
			a[x][d]=y;
		}
	}
	return 0;
}