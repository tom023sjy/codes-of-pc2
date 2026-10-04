#include <bits/stdc++.h>
using namespace std;
int n,m,a[5010],dp[5010],x;
int main(){
	freopen("three.in","r",stdin);
	freopen("three.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>x;
		a[x]++;
	}
	dp[0]=1;
	if(a[1]%3==0) dp[1]=1;
	if(a[2]%3==0) dp[2]=1;
	for(int i=3;i<=m;++i){
		if(a[i]){
			if(a[i]%3==a[i-1]%3&&a[i-2]%3==a[i-1]%3){dp[i]=(dp[i-3]+min(a[i]/3,min(a[i-1]/3,a[i-2]/3))*dp[i-3]);}
			else if(a[i]%3==0) dp[i]=dp[i-1];
			else dp[i]=0;
		}
		else dp[i]=dp[i-1];
	}
	cout<<dp[n];
	return 0;
}
