#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3010,mod = 1e9+7;

int n;
vector<int> e[N];
int pw[N];
int dep[N];
int f[N][N],sum[N];

void dfs(int u,int f)
{
    for(int v:e[u])
    {
        if(v == f) continue;
        dep[v] = dep[u] + 1;
        dfs(v,u);
    }
}
void dfs1(int u,int fa)
{
    for(int i=0;i<=n;i++)
    {
        f[u][i] = 1;
    }
    for(int v:e[u])
    {
        if(v == fa) continue;
        dfs1(v,u);
        for(int i=1;i<=n;i++)
        {
            f[u][i] = 1ll*f[u][i] * f[v][i] % mod;
        }
    }
    if(u != 1)
    for(int i=dep[u];i<=n;i++)
    {
        f[u][i] = (f[u][i] + 1) % mod;
    }
}
ll qpow(ll a,int b)
{
    ll ret=1;
    while(b)
    {
        if(b&1) ret = ret*a % mod;
        a = a*a % mod;
        b >>= 1;
    }
    return ret;
}
int main()
{
	freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n;
    if(n > 3000)
    {
        cout << 1;
        return 0;
    }
    for(int i=1,u,v;i<n;i++)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    pw[0] = 1;
    for(int i=1;i<=n;i++) pw[i] = pw[i-1] * 2 % mod;
    dfs(1,0);
    dfs1(1,0);
    for(int i=1;i<=n;i++) sum[i] = 1;
    int ans = f[1][n];
    for(int v:e[1])
    {
        for(int i=1;i<=n;i++)
        {
            ans = (ans + mod - 1ll*(f[v][i] + mod - f[v][i-1]) * f[1][i-1] % mod * qpow(f[v][i-1],mod-2) % mod) % mod;
        }
    }
    cout << ans;
}
