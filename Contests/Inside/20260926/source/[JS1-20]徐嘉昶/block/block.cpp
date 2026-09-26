#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
int w[100005];
vector<int> mp[100005];
map<pair<int,int>,bool> xxkan;
int sz[100005],dp[100005];
void dfs1(int u,int fa)
{
    for(int i=0;i<mp[u].size();i++)
    {
        if(mp[u][i]==fa) continue;
        dfs1(mp[u][i],u);
        sz[u]+=sz[mp[u][i]];
    }
    sz[u]++;
}
int pre;
void dfs2(int u,int fa,int tof)
{
    
}
signed main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
        dp[i]=w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int num;
        cin>>num;
        while(num--)
        {
            int v;
            cin>>v;
            mp[i].push_back(v);
        }
    }
    dfs1(1,0);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        xxkan[{u,v}]=xxkan[{v,u}]=1;
    }
    int maxn=-1e15;
    for(int i=0;i<(1ll<<n);i++)
    {
        pre=0,ans=-1e15;
        dfs2(1,0,i);
        maxn=max(maxn,ans);
    }
    cout<<maxn;
    return 0;
}
/*
6 3
2 2 1 3 2 5
2 2 6
3 3 4 5
0
0
0
0
3 4
5 6
2 6
*/