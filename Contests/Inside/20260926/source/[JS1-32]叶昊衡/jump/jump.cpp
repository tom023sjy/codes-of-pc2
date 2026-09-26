#include<bits/stdc++.h> 
using namespace std;
const int mod=1e9+7;
int n;
long long ans;
bool vis[1100005];
string st;
queue<int>q;
void work()
{
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		for(int i=0;i<n-2;i++)
			if(p>>i&1)
				if(p>>(i+1)&1)
					if(!(p>>(i+2)&1))
					{
						int now=p-(1<<i)+(1<<(i+2));
						if(!vis[now])
						{
							vis[now]=1,ans++;
							q.push(now);
						}
					}
		for(int i=2;i<n;i++)
			if(p>>i&1)
				if(p>>(i-1)&1)
					if(!(p>>(i-2)&1))
					{
						int now=p-(1<<i)+(1<<(i-2));
						if(!vis[now])
						{
							vis[now]=1,ans++;
							q.push(now);
						}
					}
	}
}
void init(int t,int now)
{
	if(t==n)
	{
		q.push(now),ans++;
		memset(vis,0,sizeof(vis));
		vis[now]=1;
		work();
	}
	else
	{
		if(st[t]=='?')
		{
			init(t+1,now*2);
			init(t+1,now*2+1);
		}
		else init(t+1,now*2+(st[t]-'0'));
	}
}
signed main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>st;
	init(0,0);
	cout<<ans;
}
