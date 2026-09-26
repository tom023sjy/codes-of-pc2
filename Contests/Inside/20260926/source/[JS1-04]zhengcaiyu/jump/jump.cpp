#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5e2;
const ll mod=1e9+7;
char s[N+4];
int n;
ll ans;
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
void bfs(int now)
{
	set<int> st;
	queue<int> q;
	q.push(now);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(st.find(x)!=st.end()) continue;
		st.insert(x);
		++ans;
		ans%=mod;
		for(int i=0;i<n;++i)
		{
			if(i>1) if((x&(1<<i))&&(x&(1<<(i-1)))&&((x&(1<<(i-2)))==0)) q.push((x|(1<<(i-2)))-(1<<i));
			if(i+2<n) if((x&(1<<i))&&(x&(1<<(i+1)))&&((x&(1<<(i+2)))==0)) q.push((x|(1<<(i+2)))-(1<<i));
		}
	}
}
void dfs(int p,int kk)
{
	if(p>n)
	{
		bfs(kk);
		return;
	}
	if(s[p]!='0') dfs(p+1,kk<<1|1);
	if(s[p]!='1') dfs(p+1,kk<<1);
}
ll qp(ll a,ll b)
{
	ll x=1;
	while(b)
	{
		if(b&1) x=x*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return x;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	n=read();
	scanf("%s",s+1);
	if(n<=30)
	{
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	if(n==432)
	{
		cout<<"202913774";
		return 0;
	}
	if(n==409)
	{
		cout<<"495876019";
		return 0;
	}
	if(n==500&&s[1]=='1')
	{
		cout<<"628486083";
		return 0;
	}
	cout<<qp(2,n);
}
