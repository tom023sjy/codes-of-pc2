#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 12;
const int mod = 1e9 + 7;
long long pw[MAXN];
int n;
vector<int> E[MAXN];
vector<long long> res[MAXN];
int ht[MAXN],hson[MAXN];
void dfs1(int u,int f)
{
    ht[u] = 1;
    for (int v:E[u])
    {
        if (v==f) continue ;
        dfs1(v,u);
        if (ht[v]>ht[hson[u]]) hson[u] = v;
        ht[u] = max(ht[u],ht[v]+1);
    }
}
long long f[MAXN],d[MAXN];
int lb[MAXN],rb[MAXN],idx;
struct SegTreeNode{
    long long c,b;
}T[MAXN<<2];
inline void opt(int k,long long c,long long b) 
{
    T[k].b = (T[k].b*c + b)%mod;
    T[k].c = T[k].c*c%mod;
}
inline void pushdown(int k)
{
    opt(k<<1,T[k].c,T[k].b),opt(k<<1|1,T[k].c,T[k].b);
    T[k].c = 1,T[k].b = 0;
}
void modify(int k,int l,int r,int L,int R,long long c,long long b)
{
    if (L<=l&&r<=R) return opt(k,c,b),void();
    if (r<L||l>R) return ;
    pushdown(k);
    int md = (l+r)>>1;
    modify(k<<1,l,md,L,R,c,b),modify(k<<1|1,md+1,r,L,R,c,b);
}
long long query(int k,int l,int r,int pos)
{
    if (l==r) return T[k].b;
    int md = (l+r)>>1;
    pushdown(k);
    if (pos<=md) return query(k<<1,l,md,pos);
    else return query(k<<1|1,md+1,r,pos);
}
void dfs2(int u,int fa)
{
    if (hson[u])
    {
        lb[hson[u]] = lb[u] + 1,
        rb[hson[u]] = rb[u];
        dfs2(hson[u],u);
    }
    // for (int k=lb[u];k<=rb[u];k++) f[k] = (f[k] + 1)%mod;
    modify(1,1,n,lb[u],rb[u],1,1);
    for (int v:E[u])
    {
        if (v==hson[u]||v==fa) continue ;
        lb[v] = idx+1,rb[v] = idx + ht[v];
        idx += ht[v];
        dfs2(v,u);
        // rec(lb[v],rb[v]);
        for (int i=lb[v];i<=rb[v];i++)
        {
            int j = i-lb[v]+lb[u] + 1;
            long long cur = (query(1,1,n,i)+1)%mod;
            if (i<rb[v]) modify(1,1,n,j,j,cur,0);
            else modify(1,1,n,j,rb[u],cur,0);
            // if (i<rb[v]) f[j] = f[j]*(f[i]+1)%mod;
            // else for (int k=j;k<=rb[u];k++) f[k] = f[k]*(f[i]+1)%mod;
        }
    }
}
int main()
{
    for (int i=0;i<MAXN*4;i++) T[i].c = 1;
    pw[0] = 1;for (int i=1;i<MAXN;i++) pw[i] = pw[i-1]*2ll%mod;
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<n;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        E[u].push_back(v),E[v].push_back(u);
    }
    vector<int> cur;
    long long ans = 1;
    dfs1(1,0);
    for (int v:E[1])
    {
        cur.push_back(v);
        res[v].resize(ht[v]+1,0);
        lb[v] = idx+1,rb[v] = idx + ht[v];idx += ht[v];
        dfs2(v,1);
        for (int i=1;i<=ht[v];i++) res[v][i] = query(1,1,n,lb[v]+i-1);
        for (int i=0;i<=ht[v];i++) res[v][i] = (res[v][i] + 1)%mod;
    }
    long long coef = 1;
    for (int d=1;!cur.empty()&&d<=n;d++)
    {
        long long f[3],g[3];
        memset(f,0,sizeof(f));
        f[0] = 1;
        for (int x:cur)
        {
            memset(g,0,sizeof(g));
            for (int u=0;u<=2;u++)
            {
                g[u] = (g[u] + f[u]*res[x][d-1])%mod;
                int v = min(2,u+1);
                g[v] = (g[v] + f[u]*(res[x][d]-res[x][d-1]+mod))%mod;
            }
            memcpy(f,g,sizeof(f));
        }
        ans = (ans + coef*f[2])%mod;
        vector<int> ncur;
        for (int x:cur)
        {
            if (res[x].size()==d+1) coef = coef*res[x][d]%mod;
            else ncur.push_back(x);
        }
        cur = ncur;
    }
    printf("%lld",ans);
    return 0;
}