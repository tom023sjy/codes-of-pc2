#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5e5;
struct G
{
	int id;
	ll x;
};
ll a[N+4];
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
int main()
{
	freopen("hire.in","r",stdin);
	freopen("hire.out","w",stdout);
	int n=read(),m=read(),k=read(),d=read();
//	if(n<=2e3&&m<=2e3)
//	{
		while(m--)
		{
			queue<G> q;
			bool f=true;
			int x=read();
			a[x]+=read();
			for(int i=1;i<=n;++i)
			{
				ll now=k;
				q.push({i,a[i]});
				if(q.front().id<i-d)
				{
					f=false;
					break;
				}
				while(!q.empty()&&now>=q.front().x)
				{
					now-=q.front().x;
					q.pop();
				}
				if(!q.empty()&&now>0) q.front().x-=now;
			}
			if(q.empty()&&f) printf("YES\n");
			else printf("NO\n");
		}
//		return 0;
//	}
}
