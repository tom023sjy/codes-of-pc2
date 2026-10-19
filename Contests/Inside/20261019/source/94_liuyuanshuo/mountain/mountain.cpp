#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1000000007;
int n,a[100020],vis[100020],ans[100020],dp[505][505][2];
void dfs(int now,int v){
    // cout<<now<<" "<<v<<" "<<n<<" "<<a[now]<<"\n";
    if (vis[now]) return;
    vis[now]=1;
    if (v>=n-1) {
        ans[now]++;
        ans[now]%=mod;
        vis[now]=0;
        return ;
    }
    if (a[now]) for (int i=1;i<now;i++) dfs(i,v+1);
    else for (int i=now+1;i<=n;i++) dfs(i,v+1);
    vis[now]=0;
}
int qp(int a,int b){
    int res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
}
string s;
signed main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    // freopen("chess.in","r",stdin);
    // freopen("chess.out","w",stdout);
    int c;
    cin>>c;
    cin>>s;
    n=s.size();
    s="0"+s;    
    if (c==10){
        int now=1;
        for (int i=1;i<n;i++){
            cout<<now<<" ";
            now=(now*2)%mod;
        }
        cout<<1<<"\n";
        // return 0;
    }
    if (c==11){
        cout<<1<<" ";
        for (int i=n-2;i>=0;i--) cout<<qp(2,i)<<" ";
        cout<<"\n";
        // return 0;
    }
    for (int i=1;i<=n;i++) a[i]=s[i]=='D';
    // for (int i=1;i<=n;i++) dp[i][i][a[i]]=1;
    // for (int len=2;len<=n;len++){
    //     for (int i=1;i+len-1<=n;i++){
    //         int j=i+len-1;
    //         for (int k=i;k<j;k++){
    //             dp[i][j][0]+=dp[i][k][0]*dp[k+1][j][0]+dp[i][k][1]*dp[k+1][j][0];
    //             dp[i][j][1]+=dp[i][k][1]*dp[k+1][j][1]+dp[i][k][1]*dp[k+1][j][0];
    //             cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<"\n";
    //         }
    //     }
    // }
    // dp[1][0][1]=1;
    // dp[n+1][n][0]=1;
    // for (int i=1;i<=n;i++){
    //     cout<<dp[1][i-1][1]*dp[i+1][n][0]<<" ";
    // }
    dfs(0,-1);
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<"\n";
    // cout<<dp[1][n][0]<<" "<<dp[1][n][1]<<"\n";
    return 0;
}