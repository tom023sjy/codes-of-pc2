#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 500010;

int n;
int a[N];
vector<int> e[N];
int fa[N];
int p[N],pos[N];

void dfs(int u,int f)
{
    fa[u] = f;
    for(int v:e[u])
    {
        if(v == f) continue;
        dfs(v,u);
    }
}
int dfs1(int u,int f)
{
    if(pos[u]) return 0;
    int ret=n+1;
    for(int v:e[u])
    {
        if(v == f) continue;
        ret = min(ret,dfs1(v,u) + 1);
    }
    return ret;
}

int main()
{
    freopen("perm.in","r",stdin);
    freopen("perm.out","w",stdout);
    cin >> n;
    if(n > 3000)
    {
        cout << "-1";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1,u,v;i<n;i++)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(pos[j]) continue;
            int A=dfs1(j,fa[j]);
            if(A == n+1) A = -1;
            // cerr << j << ' ' << A << ',' << a[j] << '\n';
            if(A != a[j]) continue;
            bool fl=0;
            for(int u=fa[j],d=1;u;u=fa[u],d++)
            {
                if(!pos[u] && ((a[u] != -1 && d < a[u]) || a[u] == -1)) fl=1;
            }
            // cerr << fl << '\n';
            if(fl) continue;
            p[i] = j;
            pos[j] = i;
            break;
        }
        // cerr << i << ' ' << p[i] << "QWQ!\n";
        if(!p[i])
        {
            cout << "-1";
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout << p[i] << ' ';
    }
}