#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
vector<int> g[200005];
int f[5005][5005][2];//0weiyi
int h[200005];
void dfs(int u,int fa)
{
    h[u]=0;
    f[u][0][0]=1;
    for(int v:g[u])
    {
        if(v^fa)
        {
            dfs(v,u);
            h[u]=max(h[u],h[v]+1);
            // cout<<h[u]<<'\n';
            for(int i=0;i<=h[u];i++)
            {
                for(int j=0;j<min(h[v]+1,i);j++)
                {
                    // cout<<u<<" "<<i<<" "<<j<<'\n';
                    if(j+1==i)
                    {
                        f[u][i][1]=(f[u][i][1]+f[u][i][0])%mod*(f[v][j][0]+f[v][j][1])%mod;
                    }
                    else
                    {
                        f[u][i][0]=(f[u][i][0]*(f[v][j][0]+f[v][j][1])%mod)%mod;
                        f[u][i][1]=(f[u][i][1]*(f[v][j][0]+f[v][j][1])%mod)%mod;
                    }
                }
            }
        }
    }
}
signed main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(g[1].size()==1)
    {
        cout<<1;
        return 0;
    }
    dfs(1,0);
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         cout<<f[i][j][1]<<' ';
    //     }
    //     cout<<'\n';
    // }
    int ans=0;
    for(int i=0;i<=h[1];i++)
    {
        ans=(ans+f[1][i][1])%mod;
    }
    cout<<ans;
}