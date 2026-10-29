#include<iostream>
#include<math.h>
#define int long long
using namespace std;

int n,arr[1005],dp[1005][1005],sum[1005]={};

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("express.in","r",stdin);
	freopen("express.out","w",stdout);
	cin>>n;
	sum[0]=0;
	arr[0]=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		sum[i]=sum[i-1]+abs(arr[i]-arr[i-1]);
	}
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		dp[i][0]=sum[i];
		dp[0][i]=sum[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i||j) dp[i][j]=2e18;
			if(i==j) continue;
			if(i>j){
				for(int k=0;k<j;k++) dp[i][j]=min(dp[i][j],dp[k][j]+abs(arr[j+1]-arr[k])+sum[i]-sum[j+1]);
				for(int k=j+1;k<i;k++) dp[i][j]=min(dp[i][j],dp[k][j]+sum[i]-sum[k]);
			}
			else{
				for(int k=0;k<i;k++) dp[i][j]=min(dp[i][j],dp[i][k]+abs(arr[i+1]-arr[k])+sum[j]-sum[i+1]);
				for(int k=i+1;k<j;k++) dp[i][j]=min(dp[i][j],dp[i][k]+sum[j]-sum[k]);
			}
			//cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
		}
	}
	int as=2e18;
	for(int i=0;i<=n;i++) as=min(as,min(dp[i][n],dp[n][i]));
	cout<<as;
	return 0;
}
