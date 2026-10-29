#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k[1000005],ans=LLONG_MAX;
//dp[i][j][0]：前i个任务，Y去i，Z在j的最小总路程
//dp[i][j][1]：前i个任务，Z去i，Y在j的最小总路程
signed main(){
	freopen("express.in","r",stdin);
	freopen("express.out","w",stdout);
	scanf("%lld",&n);
	int dp[n+1][n+1][2];
	for(int i=1;i<=n;i++)scanf("%lld",&k[i]);
	memset(dp,0x3f,sizeof(dp));
	dp[1][0][0]=dp[1][0][1]=k[1];
	for(int i=1;i<n;i++){
		for(int j=0;j<=n;j++){
			dp[i+1][i][0]=min(dp[i+1][i][0],dp[i][j][1]+abs(k[i+1]-k[j]));
			dp[i+1][i][1]=min(dp[i+1][i][1],dp[i][j][0]+abs(k[i+1]-k[j]));
			dp[i+1][j][0]=min(dp[i+1][j][0],dp[i][j][0]+abs(k[i+1]-k[i]));
			dp[i+1][j][1]=min(dp[i+1][j][1],dp[i][j][1]+abs(k[i+1]-k[i]));
		}
	}
	for(int i=0;i<=n;i++)ans=min({ans,dp[n][i][0],dp[n][i][1]});
	cout<<ans;
	return 0;
}
