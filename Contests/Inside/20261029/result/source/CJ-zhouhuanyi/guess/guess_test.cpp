#include<iostream>
#include<cstdio>
#include<cmath>
#define N 100
#define inf 2e18
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
	//freopen("guess.in","r",stdin);
	//freopen("guess.out","w",stdout);
	__int128 x,p1,p2;
	T=read();
	while (T--)
	{
		m=(read()<<1),length=0,n=1;
		if (m<=inf)
		{
			for (__int128 i=2;i*i*i<=m;++i)
				if (m%i==0)
				{
					tong[++length]=(node){i,0};
					while (m%i==0) tong[length].data++,m/=i;
				}
			if (m!=1)
			{
				p1=p2=0;
				for (__int128 i=1;i*i*i<=m;++i)
				{
					x=0;
					for (__int128 j=log(inf)/log(2);j>=0;--j)
						if (x+(1<<j)<=inf&&(x+(1<<j))*(x+(1<<j))*i+(x+(1<<j))==m)
							x+=(1<<j);
					if (x*x*i+x==m)
					{
						p1=x*i+1,p2=x;
						break;
					}
				}
				if (!p1) tong[++length]=(node){m,1};
				else tong[++length]=(node){p2,1},tong[++length]=(node){p1,1};
			}
			for (int i=1;i<=length;++i) cout<<(int)(tong[i].num)<<','<<(int)(tong[i].data)<<endl;
		}
		else
		{
			for (int i=log(inf)/log(2);i>=0;--i)
				if ((n+(1ll<<i))*(n+(1ll<<i)-1)<=m)
					n+=(1ll<<i);
		}
		write(n),puts("");
	}
	return 0;
}
