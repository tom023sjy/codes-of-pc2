#include<iostream>
#include<cstdio>
#include<cmath>
#define N 100
#define inf 1e9
#define INF 2e18
using namespace std;
__int128 read()
{
	char c=0;
	__int128 sum=0;
	while (c<'0'||c>'9') c=getchar();
	while ('0'<=c&&c<='9') sum=sum*10+c-'0',c=getchar();
	return sum;
}
struct node
{
	__int128 num,data;
};
node tong[N+1];
int T,length;
__int128 n,m;
void write(__int128 x)
{
	if (!x) return;
	write(x/10),printf("%d",(int)(x%10));
	return;
}
int main()
{
	freopen("guess.in","r",stdin);
	freopen("guess.out","w",stdout);
	__int128 x;
	T=read();
	while (T--)
	{
		m=read(),length=0,n=1;
		if (m<=inf)
		{
			for (__int128 i=2;i*i<=m;++i)
				if (m%i==0)
				{
					tong[++length]=(node){i,0};
					while (m%i==0) tong[length].data++,m/=i;
				}
			if (m!=1) tong[++length]=(node){m,1};
			for (int i=length;i>=1;--i)
				if (tong[i].num==2||tong[i].data)
				{
					if (tong[i].num==2)
					{
						for (int j=1;j<=(tong[i].data+2)>>1;++j) n*=tong[i].num;
					}
					else
					{
						for (int j=1;j<=((tong[i].data+1)>>1);++j) n*=tong[i].num;
						x=(tong[i].num-1)>>1;
						if (tong[1].num==2) tong[1].data--;
						for (int j=1;j<=i-1;++j)
							while (x%tong[j].num==0)
								x/=tong[j].num,tong[j].data--;
					}
				}
		}
		else
		{
			for (int i=log(INF)/log(2);i>=0;--i)
				if ((((n+(1ll<<i))*(n+(1ll<<i)-1))>>1)<=m)
					n+=(1ll<<i);
		}
		write(n),puts("");
	}
	return 0;
}
