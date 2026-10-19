#include<bits/stdc++.h>
using namespace std;
int id,n;
string str;
long long dp[2][510][510][510];
const long long mod=1e9+7;
int main()
{
    freopen("mountain.in","r",stdin);
    freopen("mountain.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>id>>str;
    n=str.size();
    if(id==10)
    {
        long long res=1ll;
        for(int i=1;i<n;i++) cout<<res<<" ",res=2ll*res%mod;
        cout<<1;
        return 0;
    }
    else if(id==11)
    {
        long long ans[5010];
        long long res=1ll;
        for(int i=1;i<n;i++) ans[i]=res,res=2ll*res%mod;
        cout<<1<<" ";
        for(int i=n-1;i>=1;i--) cout<<ans[i]<<" ";
        return 0;
    }
    dp[1][(str[0]=='D')][(str[0]=='U')][1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=n-i+1;j++)
        {
            for(int k=0;j+k<=n-i+1;k++)
            {
                if(j+k==0) continue;
                for(int p=1;p<=i;p++) dp[i&1][j][k][p]=0;
                for(int p=1;p<i;p++)
                {
                    if(str[p-1]=='U') 
                    {
                        if(str[i-1]=='D') 
                        {
                            if(j>=1) dp[i&1][j][k][i]+=dp[(i-1)&1][j-1][k+1][p];
                        }
                        else dp[i&1][j][k][i]+=dp[(i-1)&1][j][k][p];
                    }
                    if(j>=(str[i-1]=='D')&&k>=(str[i-1]=='U'))
                    {
                        dp[i&1][j][k][i]+=dp[(i-1)&1][j-(str[i-1]=='D')][k-(str[i-1]=='U')][p];
                    }
                    dp[i&1][j][k][i]%=mod;
                }
                for(int p=1;p<i;p++)
                {
                    if(j>=(str[i-1]=='D')&&k>=(str[i-1]=='U'))
                    {
                        dp[i&1][j][k][p]+=dp[(i-1)&1][j-(str[i-1]=='D')][k-(str[i-1]=='U')][p]*(j+k-1)%mod;
                    }
                    if(str[i-1]=='D')
                    {
                        dp[i&1][j][k][p]+=dp[(i-1)&1][j][k][p]*(j+k)%mod;
                        if(k>=(str[p-1]=='U'))
                        {
                            if(j>=1) dp[i&1][j][k][p]+=dp[(i-1)&1][j-1][k+1][p]*(k+1-(str[p-1]=='U'))%mod;
                            dp[i&1][j][k][p]+=dp[(i-1)&1][j][k+1][p]*(k+1-(str[p-1]=='U'))%mod;    
                        }
                    }
                    else 
                    {
                        if(k>=(str[p-1]=='U')) dp[i&1][j][k][p]+=dp[(i-1)&1][j][k][p]*(k-(str[p-1]=='U'))%mod;
                    }
                    dp[i&1][j][k][p]%=mod;
                }
            }
        }
    }
    for(int p=1;p<=n;p++) cout<<dp[n&1][(str[p-1]=='D')][(str[p-1]=='U')][p]<<" ";
}