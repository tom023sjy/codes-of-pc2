#include<iostream>
using namespace std;
const int N=2e5+5;
struct edge
{
    int to,nxt;
}e[N*2];
int head[N],ed,fa[N],p[N],pos[N],d[N],cur[N],flag;
int n,vis[N];
void add(int u,int v)
{
    e[++ed].to=v;
    e[ed].nxt=head[u];
    head[u]=ed;
    return ;
}
void dfs(int u,int lst)
{
    fa[u]=lst;
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==lst)
            continue;
        dfs(v,u);
    }
    return ;
}
bool check()
{
    for(int i=1;i<=n;i++)
    {
        cur[i]=N;
        pos[p[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        int len=1,u=fa[i];
        while(u)
        {
            if(pos[i]<pos[u])
                cur[u]=min(cur[u],len);
            len++;
            u=fa[u];
        }
    }
    for(int i=1;i<=n;i++)
        if(cur[i]==N)
            cur[i]=-1;
    for(int i=1;i<=n;i++)
        if(cur[i]!=d[i])
            return 0;
    return 1;
}
void dfs1(int k)
{
    if(k>n)
    {
        flag=check();
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            p[k]=i;
            dfs1(k+1);
            vis[i]=0;
            if(flag)
                return ;
        }
    }
    return ;
}
int main()
{
    freopen("perm.in","r",stdin);
    freopen("perm.out","w",stdout);
    int u,v;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>d[i];
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    if(n>10)
    {
        cout<<-1;
        return 0;
    }
    dfs(1,0);
    dfs1(1);
    if(flag)
    {
        for(int i=1;i<=n;i++)
            cout<<p[i]<<" ";
    }
    else
        cout<<-1;
    return 0;
}