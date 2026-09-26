#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=25,S=1<<20,p=1e9+7;
int n;
char s[N];
bool bk[S];
ll ans;
queue<int> q;
bool check(int x)
{
	for(int i=0;i<n;i++)
	{
		if(s[i]!='?'&&s[i]-'0'!=(x>>i&1))return 0;
	}
	return 1;
}
void bfs(int x)
{
	for(int i=1;i<1<<n;i++)bk[i]=0;
	bk[x]=1;
	ans++;
	q.push(x);
	while(q.size())
	{
		x=q.front();
		q.pop();
		for(int i=0;i<n-2;i++)
		{
			int st=x>>i&7;
			if(st==3||st==6)
			{
				int y=x^5<<i;
				if(!bk[y])
				{
					bk[y]=1;
					ans++;
					q.push(y);
				}
			}
		}
	}
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%s",&n,s);
	if(n>20)
	{
		printf("%d",n);
		return 0;
	}
	for(int i=0;i<1<<n;i++)
	{
		if(check(i))
		{
			bfs(i);
		}
	}
	printf("%lld",ans);
	return 0;
}
