#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 12;
int n,d[MAXN];
int dfn[MAXN],rb[MAXN],ht[MAXN],idx,dep[MAXN];
int bfn[MAXN],p[MAXN];
vector<int> ton[MAXN];
int tl[MAXN],tr[MAXN];
vector<int> E[MAXN];
int res[MAXN];
void dfs1(int u,int f)
{
    dfn[u] = ++idx;
    dep[u] = dep[f] + 1;
    ton[dep[u]].push_back(u);
    ht[u] = 1;
    for (int v:E[u])
    {
        if (v==f) continue ;
        dfs1(v,u);
        ht[u] = max(ht[u],ht[v]+1);
    }
    rb[u] = idx;
}
int vis[MAXN];
bool check(int x)
{
    if (d[x]!=n+2)
    {
        int flag = 0;
        for (int y=1;y<=n;y++)
            if (dfn[x]<=dfn[y]&&dfn[y]<=rb[x]&&dep[y]==d[x]&&vis[y]) flag = 1;
        if (flag==0) return 0;
    }
    for (int y=1;y<=n;y++)
    {
        if (dfn[y]<dfn[x]&&dfn[x]<=rb[y]&&dep[x]<d[y]&&vis[y]==0)
            return 0;
    }
    return 1;
}
int v1[MAXN],v2[MAXN],deg[MAXN];
vector<int> T[MAXN<<2];
void add(int k,int l,int r,int L,int R,int id)
{
    if (r<L||l>R) return ;
    if (L<=l&&r<=R) return T[k].push_back(id),void();
    int md = (l+r)>>1;
    add(k<<1,l,md,L,R,id),add(k<<1|1,md+1,r,L,R,id);
}
set<int> st;
void erase(int k,int l,int r,int pos)
{
    for (int x:T[k])
    {
        if (v1[x]==0)
        {
            v1[x] = 1;
            if (v2[x]) st.insert(x);
        }
    }
    T[k].clear();
    if (l==r) return ;
    int md = (l+r)>>1;
    if (pos<=md) erase(k<<1,l,md,pos);
    else erase(k<<1|1,md+1,r,pos);
}
int jp[MAXN][20];
int mx[MAXN][20];
vector<int> F[MAXN];
void dfs2(int u,int f)
{
    mx[u][0] = d[f];
    jp[u][0] = f;
    for (int i=1;i<20;i++)
        jp[u][i] = jp[jp[u][i-1]][i-1],
        mx[u][i] = max(mx[u][i-1],mx[jp[u][i-1]][i-1]);
    if (mx[u][19]>dep[u])
    {
        int x = u;
        for (int k=19;k>=0;k--)
            if (mx[x][k]<=dep[u]) x = jp[x][k];
        x = jp[x][0];
        F[x].push_back(u);
    }
    // for (int x=f;x;x=jp[x][0])
    //     if (d[x]>dep[u]) 
    //     {
    //         F[x].push_back(u);
    //         break;
    //     }
    for (int v:E[u])
    {
        if (v==f) continue ;
        dfs2(v,u);
    }
}
int main()
{
    freopen("perm.in","r",stdin);
    freopen("perm.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",d+i);
    for (int i=1;i<n;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        E[u].push_back(v),E[v].push_back(u);
    }
    dfs1(1,0);
    for (int d=1,t=0;d<=ht[1];d++)
    {
        tl[d] =t+1;
        for (int x:ton[d])
        {
            t ++;
            p[t] = x;
            bfn[x] = t;
        }
        tr[d] = t;
    }
    // cerr << ht[2];
    for (int i=1;i<=n;i++)
        if (d[i]>ht[i]-1||d[i]==0) return printf("-1\n"),0;
    for (int i=1;i<=n;i++)
        if (d[i]==-1) d[i] = n+2;
        else d[i] = dep[i] + d[i];
    for (int i=1;i<=n;i++)
    {
        if (d[i]==n+2) v1[i] = 1;
        else 
        {
            int L,R;
            int l=tl[d[i]],r = tr[d[i]],md;
            while (l<=r)
            {
                md = (l+r)>>1;
                if (dfn[i]<=dfn[p[md]]) L = md,r = md-1;
                else l = md+1;
            }
            l = tl[d[i]],r = tr[d[i]];
            while (l<=r)
            {
                md = (l+r)>>1;
                if (dfn[p[md]]<=rb[i]) R = md,l = md+1;
                else r = md-1;
            }
            add(1,1,n,L,R,i);
        }
    }
    dfs2(1,0);
    for (int u=1;u<=n;u++)
        for (int v:F[u]) deg[v] ++;
    for (int u=1;u<=n;u++)
        if (deg[u]==0) v2[u] = 1;
    for (int u=1;u<=n;u++)
        if (v1[u]&&v2[u]) st.insert(u);
    for (int i=1;i<=n;i++)
    {
        if (st.empty()) return printf("-1"),0;
        int x = *st.begin();st.erase(st.begin());
        vis[x] = 1;
        // assert(check(x));
        res[i] = x;
        erase(1,1,n,bfn[x]);
        for (int y:F[x])
        {
            deg[y] --;
            if (deg[y]==0)
            {
                v2[y] = 1;
                if (v1[y]==1) st.insert(y);
            }
        }
    }
    for (int i=1;i<=n;i++) printf("%d ",res[i]);
    return 0;
}