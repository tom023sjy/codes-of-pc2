#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using  namespace std;
const int N=3e6+5,MOD=1e9+7;
int nxt[N],nt[N],h[N],top,dep[N],vis[N];
void add(int u,int v)
{
	top++;
	nxt[top]=v;
	nt[top]=h[u];
	h[u]=top;
}
int n,DEP[N];
void dfs(int x)
{
	vis[x]=1;
	DEP[x]=1;
	for(int i=h[x];i;i=nt[i])
	{
		if(nxt[i]!=1&&vis[nxt[i]]==0)
		{
			dfs(nxt[i]);
			DEP[x]=max(DEP[x],DEP[nxt[i]]+1);
		}
	}
	return ;
}
int TOP=0,U[N],num[N],ANS=0;
vector <int>v[N],siz[N];
void ds(int x)
{
	vis[x]=1;
	for(int i=h[x];i;i=nt[i])
	{
		if(nxt[i]!=1&&vis[nxt[i]]==0)
		{
			dep[nxt[i]]=dep[x]+1;
			ds(nxt[i]);
		}
	}
	v[TOP][dep[x]]++;
	siz[TOP][dep[x]]++;
}
int fp(int x,int y)
{
	int cnt=1;
	while(y)
	{
		if(y%2==1)cnt=cnt*x%MOD;
		x=x*x%MOD;
		y/=2;
	}
	return cnt;
}
int dp[N][2],op,H,DP[N][2];
void f(int x,int pre)
{
	dp[x][op]=1;
	/*if(DEP[x]+1<H)
	{	
		dp[x][op]=DP[x][0];
		DP[x][1]=0;
		return ;
	}*/
	if(dep[x]==H)
	{
		DP[x][0]=1;
		DP[x][1]=1;
		return ;
	}
	DP[x][0]=1;
	for(int i=h[x];i;i=nt[i])
	{
		if(nxt[i]==pre||nxt[i]==1)continue;
		f(nxt[i],x);
		DP[x][0]*=DP[nxt[i]][0];
		DP[x][0]%=MOD;
		dp[x][op]*=dp[nxt[i]][op]+1;
		dp[x][op]%=MOD;
	}
	int cnt=0;
	for(int i=h[x];i;i=nt[i])
	{
		if(nxt[i]==pre||nxt[i]==1)continue;
		int OOO=fp(DP[nxt[i]][0],MOD-2);
		cnt+=DP[x][0]*OOO%MOD*DP[nxt[i]][1]%MOD;
		cnt%=MOD;
	}
	DP[x][1]=cnt;
	return ;
}
/*
3
1 2 
1 3
*/
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld",&n);
	bool FLAG=1;
	int _U,_V;
	for(int i=1;i<n;i++)
	{
		scanf("%lld%lld",&_U,&_V);
		if(_V!=_U+1)FLAG=0;
		add(_U,_V);
		add(_V,_U); 
	}
	if(FLAG)
	{
		printf("1\n");
		return 0;
	}
	for(int i=h[1];i;i=nt[i])
	{
		dfs(nxt[i]);
	}
	memset(vis,0,sizeof(vis));
	for(int i=h[1];i;i=nt[i])
	{
		TOP++;
		v[TOP].resize(DEP[nxt[i]]+3);
		siz[TOP].resize(DEP[nxt[i]]+3);
		dep[nxt[i]]=1;
		ds(nxt[i]);
	//cout<<-1;
		num[nxt[i]]=TOP;
		for(int j=1;j<=DEP[nxt[i]];j++)siz[TOP][j]+=siz[TOP][j-1];
	}
	U[0]=1;
	ANS+=1;
	op=0;
	for(int x=1;x<=n;x++)
	{
		op^=1;
		U[x]=1;
		if(x==2)
		{
			x=2;
		}
		for(int j=h[1];j;j=nt[j])
		{
			/*if(DEP[nxt[j]]<x)U[x]*=(siz[num[nxt[j]]][DEP[nxt[j]]]+1);
			else U[x]*=(siz[num[nxt[j]]][x]+1);*/
			H=x;
			if(DEP[nxt[j]]+1>=x)
			{
				f(nxt[j],1);
			}
			U[x]*=dp[nxt[j]][op]+1;
			U[x]%=MOD;
		}
		
		int cnt=0,ct=0,CT=0;
		for(int j=h[1];j;j=nt[j])
		{
			if(DEP[nxt[j]]<x)continue;
			int OOO=fp(dp[nxt[j]][op^1]+1,MOD-2);
			CT+=DP[nxt[j]][1]*(U[x-1]*OOO%MOD)%MOD;
			ct+=((dp[nxt[j]][op]-dp[nxt[j]][op^1]+MOD)%MOD)*(U[x-1]*OOO%MOD)%MOD;
			cnt+=v[num[nxt[j]]][x]*(U[x-1]*OOO%MOD)%MOD;
			CT%=MOD;
			ct%=MOD;
			cnt%=MOD;
		}
		int VVV=U[x]-U[x-1]-cnt-ct+CT;
		if(VVV==0)break;
		ANS+=U[x]-U[x-1]-cnt-ct+CT;
		
		while(ANS<MOD)ANS+=MOD;
		ANS%=MOD;
		//cout<<U[x]-U[x-1]-cnt-ct+CT<<endl;
	}
	printf("%lld\n",ANS);
	return 0;
}
