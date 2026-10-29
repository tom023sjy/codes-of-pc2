#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1005;
int n,ans=1e18,k[N],dp[N][N];
int Abs(int x) {return (x>0)?(x):(-x);}
signed main()
{
    freopen("express.in","r",stdin);
    freopen("express.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>k[i];
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0LL;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i;j++)
            dp[i][i-1]=min(dp[i][i-1],dp[i-1][j]+Abs(k[j]-k[i])),
            dp[i][j]=min(dp[i][j],dp[i-1][j]+Abs(k[i]-k[i-1]));
    for(int i=0;i<=n;i++) ans=min(ans,dp[n][i]);
    cout<<ans;
}
