#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,a[N][N],b[N][N];
//void out()
//{
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=i;j++)
//		{
//			printf("%d ",a[i][j]); 
//		}
//		puts("");
//	}
//	puts("--------------");
//}
void rtt()
{
	for(int l=n,x=1,y=1;l>1;l-=3,x+=2,y++)
	{
		for(int i=1;i<l;i++)
		{
			swap(a[x+i][y],a[x+l-i-1][y+l-i-1]);
			swap(a[x+i][y],a[x+l-1][y+i]);
		}
	}
}
void rvs()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<<1<=i;j++)
		{
			swap(a[i][j],a[i][i-j+1]);
		}
	}
}
int chk()
{
	int ret=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(a[i][j]!=b[i][j])
			{
				ret++;
			}
		}
	}
	return ret;
}
int main()
{
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			scanf("%d",&a[i][j]); 
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			scanf("%d",&b[i][j]); 
		}
	}
	int ans=0x7fffffff;
	for(int i=0;i<3;i++)
	{
		rtt();
		ans=min(ans,chk());
	}
	rvs();
	for(int i=0;i<3;i++)
	{
		rtt();
		ans=min(ans,chk());
	}
	printf("%d",ans);
	return 0;
}
