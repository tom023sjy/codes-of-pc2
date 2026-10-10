#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,v[10],dp[1000005][7];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>t;
	while(t--){
		string n;
		cin>>n;
		int m=n.size(),ans=0,maxx=0;
		memset(dp, 0, sizeof dp);
		string s=" "+n;
		for(int i=1;i<=9;i++)cin>>v[i];
		for(int i=m;i;i--)for(int j=1;j<=6;j++)dp[i][j]=max(dp[i+1][j],dp[i+1][j-1]+v[s[i]-'0']-(int)pow(10,j-1)*(s[i]-'0'));
		for(int i=1;i<=m;i++)ans+=v[s[i]-'0'];
		for(int i=1;i<=6;i++)maxx=max(maxx,dp[1][i]);
		cout<<ans-maxx<<"\n";
	}
	return 0;
}
//dp[i][j]：后 i 个数中选了 j 位，比这 j 位一个个消所能赚的最大
//dp[i][0]=0;
//i:n-1 j:1-6
//dp[i][j]=max(dp[i+1][j],
//             dp[i+1][j-1]+v[s[i]-'0']-pow(10,j-1)*(s[i]-'0'))
//最后用一个个消得和减去max(dp[1][1],...,dp[1][6]) 
