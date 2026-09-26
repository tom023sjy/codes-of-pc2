#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans=1,vis[200],md=998244353;
int vv[4100];
void dfs(int x){
	if (x>n) {
		int res=0;
		for (int i=1;i<=n;i++) res=(res+vis[i]*i)%md;
		if (res) ans=(ans*res)%md;
//		cout<<res<<"\n";
		vv[res]++;
		return ;
	}
	dfs(x+1);
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
}
int dp[210020];
void out(__int128 a){
	while(a){
		cout<<(int)(a%10);
		a/=10; 
	}
}
int poww(int a,int b){
	int res=1;
	while(b){
		if (b&1) res=(res*a)%md;
		b>>=1;
		a=(a*a)%md;
	}
	return res;
}
signed main(){
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	cin>>n;
//	dfs(1);
//	cout<<vv[22]<<" ";
	dp[1]=1;
	for (int i=2;i<=n;i++){
		for (int j=21000;j>1;j--) dp[j]=(dp[j]+dp[j-i])%(md-1);
		dp[i]+=1;
	}
	ans=1;
	for (int i=1;i<=21000;i++){
		ans=(ans*poww(i,dp[i]))%md;
	}
	cout<<ans;
	return 0;
}
