#include<bits/stdc++.h>
using namespace std;
const int N = 330;
const int M = 5e5+10;
bool dp[N][N][N];
int a[M];
int b[M];
int ans[N];
int n;
signed main(){
	freopen("maxmin.in","r",stdin);
	freopen("maxmin.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>a[i];
	for(int i = 1;i<=n;i++)cin>>b[i];
	bool flag = 0;
	for(int i = 1;i<=n;i++)if(a[i]!=b[i])flag = 1;
	if(flag==0){
		cout<<n<<' ';
		for(int i = 1;i<n;i++)cout<<0<<" ";
		return 0; 
	}
	dp[1][a[1]][b[1]] = 1;
	for(int i = 2;i<=n;i++){
		for(int j = 1;j<i;j++){
			for(int k = 1;k<i;k++){
				dp[i][max(a[i],a[j])][max(b[i],b[k])]|=dp[i-1][a[j]][b[k]];
				dp[i][min(a[i],a[j])][min(b[i],b[k])]|=dp[i-1][a[j]][b[k]];
			}
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(dp[n][i][j])ans[abs(i-j)]++;
		}
	}
	for(int i = 0;i<n;i++)cout<<ans[i]<<" ";
	return 0;
}
