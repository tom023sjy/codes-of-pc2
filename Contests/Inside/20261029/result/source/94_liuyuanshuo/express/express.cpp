#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100020],dp[1005][1005],ans=0x3f3f3f3f3f3f3f3f;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("express.in","r",stdin);
    freopen("express.out","w",stdout);
    memset(dp,0x3f,sizeof dp);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    dp[0][0]=0;
    for (int i=1;i<=n;i++){
        for (int j=0;j<i;j++){
            dp[i][j]=min(dp[i][j],dp[i-1][j]+abs(a[i]-a[i-1]));
            dp[i][i-1]=min(dp[i][i-1],dp[i-1][j]+abs(a[j]-a[i]));
            if (i==n) ans=min(ans,dp[i][j]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
