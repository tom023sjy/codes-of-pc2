#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5e3+10;
const ll mod=1e9+7;
int a[N],b[N];
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
bool ch(int x)
{
	return x%3==0;
}
int main()
{
	freopen("three.in","r",stdin);
	freopen("three.out","w",stdout);
	int n=read(),m=read();
	bool i3=true,i4=true;
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		++b[a[i]];
		if(b[a[i]]>2) i3=false;
		if(a[i]%4==0) i4=false;
	}
	if(i3)
	{
		for(int i=1;i<=m+2;++i)
		{
			if(b[i]<0)
			{
				printf("0");
				return 0;
			}
			for(int j=1;j<=2;++j) b[i+j]-=b[i];
			b[i]=0;
		}
		printf("1");
		return 0;
	}
	if(i4)
	{
		ll ans=1;
		for(int i=1;i<=m;i+=4)
		{
			if(!ch(b[i]+b[i+1]+b[i+2]))
			{
				printf("0");
				return 0;
			}
			ll sum=0;
			int cc=min(b[i],min(b[i+1],b[i+2]));
			for(int j=0;j<=cc;++j) if(ch(b[i]-j)&&ch(b[i+1]-j)&&ch(b[i+2]-j)) ++sum;
			ans=ans*sum%mod;
		}
		printf("%lld",ans);
		return 0;
	}
	int c1=mod,c2=mod;
	ll ans=0;
	for(int i=1;i<=4;++i)
	{
		if(i<=3) c1=min(c1,b[i]);
		if(i>1) c2=min(c2,b[i]);
	}
	for(int i=0;i<=c1;++i) for(int j=0;j<=c2;++j) if(ch(b[1]-i)&&ch(b[2]-i-j)&&ch(b[3]-i-j)&&ch(b[4]-j)) ++ans;
	printf("%lld",ans);
}
