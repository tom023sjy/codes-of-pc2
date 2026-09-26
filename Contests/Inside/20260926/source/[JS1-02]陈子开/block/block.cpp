#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5;
int val[N],dp[N];
vector<int> e[N];
bool book[N];

void dfs(int u) {
    dp[u]=val[u];
    int sz=e[u].size();
    if(book[u]) {
        for(int i=1;i<sz;i++) {
            dfs(e[u][i]);
            dp[u]=max(dp[u],dp[u]+dp[e[u][i]]);
        }
    }
    else {
        for(int i=0;i<sz;i++) {
            dfs(e[u][i]);
            dp[u]=max(dp[u],dp[u]+dp[e[u][i]]);
        }
    }
    return ;
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>val[i];
    }
    for(int i=1;i<=n;i++) {
        int num;
        cin>>num;
        for(int j=1;j<=num;j++) {
            int x;
            cin>>x;
            e[i].push_back(x);
        }
    }
    while(m--) {
        int u,v;
        cin>>u>>v;
        book[v]=true;
    }
    dfs(1);
    int ans=-1e18;
    for(int i=1;i<=n;i++) {
        // cout<<dp[i]<<' ';
        ans=max(ans,dp[i]);
    }
    cout<<ans;
    return ;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("block.in","r",stdin);
    freopen("blobk.out","w",stdout);
    solve();
    return 0;
}