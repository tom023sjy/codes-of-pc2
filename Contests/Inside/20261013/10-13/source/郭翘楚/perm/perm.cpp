#include <bits/stdc++.h>
using namespace std;
int d[500005];
int son[500005];
vector<int> g[500005];
vector<int> e[500005];
int deg[500005];
void dfs(int u,int fa)
{
    for(int v:g[u])
    {
        if(v^fa)
        {
            if(d[u]==-1||d[u]>1)
            {
                e[u].push_back(v);
                deg[v]++;
                // printf("pos[%d]<pos[%d]\n",u,v);
            }
            else if(d[u]==1)
            {
                e[v].push_back(u);
                deg[u]++;
                // printf("pos[%d]<pos[%d]\n",v,u);
                d[u]=0;
            }
            dfs(v,u);
        }
    }
}
int n;
int v[500005];
bool vis[500005];
bool bfs()
{
    priority_queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(deg[i]==0)
        {
            q.push(-i);
        }
    }
    int cnt=0;
    // return false;
    while(!q.empty())
    {
        int u=-q.top();
        vis[u]=1;
        v[u]=++cnt;
        q.pop();
        for(int v:e[u])
        {
            if(vis[v]) continue;
            deg[v]--;
            if(deg[v]==0) q.push(-v);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(deg[i]!=0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    freopen("perm.in","r",stdin);
    freopen("perm.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i];
        if(d[i]==0)
        {
            cout<<-1;
            return 0;
        }
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        sort(g[i].begin(),g[i].end());
    }
    dfs(1,0);
    if(bfs())
    {
        for(int i=1;i<=n;i++)
        {
            cout<<v[i]<<' ';
        }
    }
    else
    {
        cout<<-1;
    }
}