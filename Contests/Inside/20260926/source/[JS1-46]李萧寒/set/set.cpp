#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int qpow(int w,int b){
	if(b==0){
		return 1;
	}
	int r=qpow(w,b/2);
	r=r*r%mod;
	if(b%2==1){
		r*=w;
		r%=mod;
	}
	return r;
}
int dp[20105];
signed main(){
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	int n;
	cin>>n;
	if(n==1){
		cout<<1;
		return 0;
	}
	dp[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=20100;j>=i+1;j--){
			dp[j]+=dp[j-i];
			dp[j]%=(mod-1);
		}
		dp[i]++;
	}
	int sum=1;
	for(int i=1;i<=n*(n+1)/2;i++){
		sum*=qpow(i,dp[i]);
		sum%=mod;
	}
	cout<<sum;
	return 0;
}
