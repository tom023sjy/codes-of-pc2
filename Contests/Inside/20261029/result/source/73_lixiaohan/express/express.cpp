#include<bits/stdc++.h>
using namespace std;
#define int long long
int min(int a,int b){
    return a<b?a:b;
}
int dp[1000005],x[1000005];
void solve(int n){
    int jian=0;
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++){
        cin>>x[i];
        jian+=abs(x[i]-x[i-1]);
    }
    dp[0]=abs(x[1]);
    for(int i=2;i<=n;i++){
        int mi=1e18;
        for(int j=0;j<i-1;j++){
            mi=min(mi,dp[j]+abs(x[i]-x[j])-abs(x[j]-x[j+1]));
        }
        dp[i-1]=mi;
    }
    int mi=1e18;
    for(int i=0;i<n;i++){
        mi=min(mi,dp[i]-abs(x[i]-x[i+1]));
    }
    cout<<mi+jian;
}
int f[1000005][55];
signed main(){
    freopen("express.in","r",stdin);
    freopen("express.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    if(n<=5000){
        solve(n);
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    memset(f,0x3f,sizeof(f));
    for(int i=0;i<=50;i++){
        f[0][i]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=50;j++){
            f[i][j]=f[i-1][j]+abs(x[i]-x[i-1]);
        }
        for(int j=0;j<=50;j++){
            f[i][x[i-1]]=min(f[i][x[i-1]],f[i-1][j]+abs(j-x[i]));
        }
    }
    int mi=1e18;
    for(int i=0;i<=50;i++){
        mi=min(mi,f[n][i]);
    }
    cout<<mi;
    return 0;
}
