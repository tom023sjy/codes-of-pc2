#include<bits/stdc++.h>
using namespace std;
// #define mod 998244353
#define mod 1000000007
#define int long long
int n,x,y,f[5005][5005],dep[500005],g[5005][5005];
vector<int> v[500005];
int fpow(int x,int y)
{
    int ret=1;
    while(y)
    {
        if(y&1)
        {
            ret*=x;
            ret%=mod;
        }
        x*=x;
        x%=mod;
        y>>=1;
    }
    return ret;
}
void pdfs(int x,int fa)
{
    dep[x]=dep[fa]+1;
    for(int i = 0; i < v[x].size(); i++)
    {
        if(v[x][i]!=fa)
        {
            pdfs(v[x][i],x);
        }
    }
    return;
}
void dfs(int x,int fa,int mxdp)
{
    if(dep[x]>mxdp) return;
    for(int i = 0; i < v[x].size(); i++)
    {
        if(v[x][i]!=fa)
        {
            dfs(v[x][i],x,mxdp);
            if(f[x][mxdp]==0) f[x][mxdp]=f[v[x][i]][mxdp];
            else f[x][mxdp]*=f[v[x][i]][mxdp];
            f[x][mxdp]%=mod;
        }
    }
    f[x][mxdp]++;
    f[x][mxdp]%=mod;
    return;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i = 1; i < n; i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    if(v[1].size()==1)
    {
        cout<<"1\n";
        return 0;
    }
    pdfs(1,0);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < v[1].size(); j++)
        {
            dfs(v[1][j],1,i);
            f[v[1][j]][i]++;
            g[v[1][j]][i]=f[v[1][j]][i];
            if(f[v[1][j]][i])
            {
                if(f[0][i]==0) f[0][i]=f[v[1][j]][i];
                else f[0][i]*=f[v[1][j]][i];
                f[0][i]%=mod;
            }
        }
    }
    for(int i = n; i >= 1; i--)
    {
        for(int j = 0; j < v[1].size(); j++)
        {
            g[v[1][j]][i]-=g[v[1][j]][i-1];
            g[v[1][j]][i]%=mod;
        }
    }
    int ans=0,nnow,mm;
    for(int i = 1; i <= n; i++)
    {
        nnow=1;
        mm=1;
        for(int j = 0; j < v[1].size(); j++)
        {
            nnow*=(f[v[1][j]][i-1]+g[v[1][j]][i]);
            mm*=f[v[1][j]][i-1];
            nnow%=mod;
            mm%=mod;
        }
        nnow=(nnow-mm)%mod;
        for(int j = 0; j < v[1].size(); j++)
        {
            if(g[v[1][j]][i]==0) continue;
            nnow-=g[v[1][j]][i]*(f[v[1][j]][i-1]?(f[0][i-1]*fpow(f[v[1][j]][i-1],mod-2))%mod:f[0][i-1]);
            nnow%=mod;
        }
        ans+=nnow;
        ans%=mod;
    }
    cout<<(ans+mod)%mod<<'\n';
    return 0;
}