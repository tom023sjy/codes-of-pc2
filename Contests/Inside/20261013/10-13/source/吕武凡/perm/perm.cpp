#include<bits/stdc++.h>
using namespace std;
int n,d[500010],inv[500010],fa[500010],dep[500010],minn=1e9,p[500010],len=0;
vector<int> G[500010],E[500010];
void DFS(int s,int f)
{
    fa[s]=f,dep[s]=dep[f]+1;
    for(auto t:G[s])
    {
        if(t==f) continue;
        DFS(t,s);
    }
}
void DFS1(int s,int rt)
{
    for(auto t:G[s])
    {
        if(t==fa[s]) continue;
        E[rt].push_back(t),inv[t]++;
        DFS1(t,rt);
    }
}
void fmin(int s,int dp)
{
    for(auto t:G[s])
    {
        if(t==fa[s]) continue;
        if(dep[t]==dp) minn=min(minn,t);
        else fmin(t,dp);
    }
}
void DFS2(int s,int rt,int dp)
{
    for(auto t:G[s])
    {
        if(t==fa[s]) continue;
        if(dep[t]==dp)
        {
            if(t==minn) E[t].push_back(rt),inv[rt]++;
        }
        else if(dep[t]<dp) E[rt].push_back(t),inv[t]++;
        else return;
        DFS2(t,rt,dp);
    }
}
struct node
{
    int w;
    bool operator<(const node&x)const
    {
        return x.w<w;
    }
};
priority_queue<node> q;
void tp()
{
    for(int i=1;i<=n;i++)
    {
        if(inv[i]==0) q.push({i});
    }
    while(q.size())
    {
        node u=q.top();
        q.pop();
        int id=u.w;
        p[++len]=id;
        for(auto t:E[id])
        {
            if(inv[t]==1) q.push({t});
            inv[t]--;
        }
    }
}
int main()
{
    freopen("perm.in","r",stdin);
    freopen("perm.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>d[i];
    for(int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        G[u].push_back(v),G[v].push_back(u);
    }
    if(n>3000)
    {
        cout<<-1;
        return 0;
    }
    DFS(1,0);
    for(int i=1;i<=n;i++)
    {
        if(d[i]==0)
        {
            cout<<-1;
            return 0;
        }
        if(d[i]==-1) DFS1(i,i);
        if(d[i]>0)
        {
            minn=1e9;
            fmin(i,dep[i]+d[i]);
            DFS2(i,i,dep[i]+d[i]);
        }
    }
    tp();
    if(len!=n) cout<<-1;
    else for(int i=1;i<=n;i++) cout<<p[i]<<" ";
}