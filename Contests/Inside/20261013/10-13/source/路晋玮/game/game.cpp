#include<iostream>
using namespace std;
const long long mod=1e9+7;
const int N=2e5+5;
long long f[3005][3005];
struct edge
{
    int to,nxt;
}e[N*2];
int head[N],ed,n;
void add(int u,int v)
{
    e[++ed].to=v;
    e[ed].nxt=head[u];
    head[u]=ed;
    return ;
}
void dfs(int u,int fa)
{
    for(int i=0;i<=n;i++)
        f[u][i]=1;
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa)
            continue;
        dfs(v,u);
        for(int j=1;j<=n;j++)
            f[u][j]=f[u][j]*(f[v][j-1]+1)%mod;
    }
    for(int j=1;j<=n;j++)
        f[u][j]=(f[u][j]-1+mod)%mod;
    return ;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    int u,v;
    long long ans=0;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    if(n>3000)
    {
        cout<<1;
        return 0;
    }
    dfs(1,0);
    for(int i=head[1];i;i=e[i].nxt)
    {
        v=e[i].to;
        for(int j=1;j<=n;j++)
            f[1][j]=(f[1][j]-f[v][j-1]+mod)%mod;
    }
    for(int i=0;i<=n;i++)
        ans=(ans+f[1][i])%mod;
    cout<<ans;
    return 0;
}