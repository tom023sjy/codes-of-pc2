#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
const int MOD=1e9+7;
bool test3=true;
bool test4=true;
int n,m;
int num[N];
int rst[N];
int dp[N][N>>1];

int add(int a,int b) {
    return (a+b>=MOD)?(a+b-MOD):(a+b);
}

void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        int tmp;
        cin>>tmp;
        if(tmp%4==0) {
            test4=false;
        }
        num[tmp]++;
    }
    for(int i=1;i<=m;i++) {
        rst[i]=num[i]%3;
        if(num[i]>=3) test3=false;
        num[i]/=3;
    }
    for(int i=1;i<=m-2;i++) {
        if(rst[i+1]<rst[i]||rst[i+2]<rst[i]) {
            cout<<0;
            return ;
        }
        rst[i+1]-=rst[i];
        rst[i+2]-=rst[i];
        rst[i]=0;
    }
    if(rst[m-1]>0||rst[m]>0) {
        cout<<0;
        return ;
    }
    if(test3) {
        cout<<1;
        return ;
    }
    if(test4) {
        int ans=1;
        for(int i=1;i<=m;i+=4) {
            ans=ans*min({num[i]+1,num[i+1]+1,num[i+2]+1})%MOD;
        }
        cout<<ans;
        return ;
    }
    if(m<=4) {
        int ans=0;
        int maxn=min({num[2],num[3],num[4]});
        for(int i=0;i<=maxn;i++) {
            ans=add(ans,min({num[1]+1,num[2]-i+1,num[3]-i+1}));
        }
        cout<<ans;
        return ;
    }
    memset(dp[2],1,sizeof dp[2]);
    for(int i=3;i<=m;i++) {
        int maxn=min({num[i-2],num[i-1],num[i]});
        for(int j=0;j<=maxn;j++) {
            dp[i][j]=add(dp[i][j],dp[i-1][num[i-1]-j+1]);
        }
    }
    cout<<dp[m][num[m]];
    return ;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("three.in","r",stdin);
    freopen("three.out","w",stdout);
    solve();
    return 0;
}