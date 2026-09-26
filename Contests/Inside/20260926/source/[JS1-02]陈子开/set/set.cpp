#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
const int N=20120;

int dp[N][205];

int Pow(int a,int b) {
    int res=1;
    while(b>0) {
        if(b&1) res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

void solve() {
    int n,ans=1;
    cin>>n;
    for(int i=1;i<=n+1;i++) {
        dp[0][i]=1;
    }
    for(int i=1;i<=n*(n+1)/2;i++) {
        for(int j=min(i,n);j>=1;j--) {
            dp[i][j]=(dp[i][j+1]+dp[i-j][j+1])%(MOD-1);
        }
    }
    for(int i=1;i<=n*(n+1)/2;i++) {
        ans=ans*Pow(i,dp[i][1])%MOD;
    }
    cout<<ans;
    return ;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("set.in","r",stdin);
    freopen("set.out","w",stdout);
    solve();
    return 0;
}