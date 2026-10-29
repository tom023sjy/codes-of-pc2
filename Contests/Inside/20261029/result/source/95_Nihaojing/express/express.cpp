#include<bits/stdc++.h>
#define I return
#define AK 0
#define IOI 
#define ll long long
using namespace std;
ll n,a[1000010],dp[1010][1010],ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("express.in","r",stdin);
    freopen("express.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	if(n<=1000){
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=0;j--){
				dp[i][j]=min(dp[i][j],dp[i-1][j]+abs(a[i]-a[i-1]));
				dp[i][i-1]=min(dp[i][i-1],dp[j][i-1]+abs(a[i]-a[j]));
				//dp[i-1][i]=min(dp[i-1][i],dp[i-1][j]+abs(a[i]-a[j]));
			}
			for(int j=0;j<i;j++){
				dp[j][i]=dp[i][j];
			}
		}
		/*for(int i=1;i<=n;i++){
			for(int j=0;j<=n;j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<"\n";
		}*/
		ans=11451419198109178;
		for(int i=0;i<=n;i++){
			ans=min(ans,dp[n][i]);
		}
		cout<<ans;
		I AK IOI;
	}
	/*for(int i=1;i<=n;i++){
		for(int j=50;j>=0;j--){
			dp[a[i]][j]=min(dp[a[i]][j],dp[a[i-1]][j]+abs(a[i]-a[i-1]));
			dp[a[i]][a[i-1]]=min(dp[a[i]][a[i-1]],dp[j][a[i-1]]+abs(a[i]-j));
			//dp[i-1][i]=min(dp[i-1][i],dp[i-1][j]+abs(a[i]-a[j]));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=10;j++){
			cout<<dp[a[i]][j]<<" ";
		}
		cout<<"\n";
	}
	ans=11451419198109178;
	for(int i=0;i<=50;i++){
		ans=min(ans,dp[a[n]][i]);
	}
	cout<<ans;*/
    I AK IOI;
}

/**
*　　┏┓　　　┏┓+ +
*　┏┛┻━━━┛┻┓ + +
*　┃　　　　　　　┃
*　┃　　　━　　　┃ ++ + + +
*  ████━████+
*  ◥██◤　◥██◤ +
*　┃　　　┻　　　┃
*　┃　　　　　　　┃ + +
*　┗━┓　　　┏━┛
*　　　┃　　　┃ + + + +Code is far away from 　
*　　　┃　　　┃ + bug with the animal protecting
*　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
*　　　┃ 　　　　　　 ┣┓
*　　  ┃ 　　　　　 　┏┛
*　    ┗┓┓┏━┳┓┏┛ + + + +
*　　　　┃┫┫　┃┫┫
*　　　　┗┻┛　┗┻┛+ + + +
*/

