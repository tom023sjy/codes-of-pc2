#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,d[N];
vector<int>G[N];
vector<int>E[N];
int ban[N];
int dep[N],deg[N];
int b[N<<1],f[N],fa[N];
int stk[N],tp;
void push(int x){stk[++tp]=x;}
void pop(int lim,vector<int>&vec){while(tp&&dep[stk[tp]]+d[stk[tp]]<=lim)vec.push_back(stk[tp--]);}
void dfs(int x,int f){
    dep[x]=dep[f]+1;::f[x]=b[dep[x]];fa[x]=b[d[x]+dep[x]];
    b[d[x]+dep[x]]=x;vector<int>vec;
    pop(dep[x],vec);if(tp)E[stk[tp]].push_back(x),deg[x]++;
    pop(dep[x]+d[x],vec);push(x);
    for(int i:G[x])if(i^f)dfs(i,x);
    b[d[x]+dep[x]]=fa[x];
    reverse(vec.begin(),vec.end());
    tp--;for(int i:vec)push(i);
}
priority_queue<int,vector<int>,greater<int> >q;
void upd(int x){
    x=f[x];
    while(ban[x]){
        ban[x]=0;
        if(!deg[x])q.push(x);
        x=fa[x];
    }
}
int solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)G[i].clear(),E[i].clear(),ban[i]=1,f[i]=fa[i]=deg[i]=0;tp=0;
    for(int i=1;i<=n;i++){
        scanf("%d",d+i);
        if(d[i]==-1)d[i]=n,ban[i]=0;
    }
    for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),G[u].push_back(v),G[v].push_back(u);
    dfs(1,0);
    for(int i=1;i<=n;i++)if(!ban[i]&&!deg[i])q.push(i);
    vector<int>ans;
    while(q.size()){
        int x=q.top();q.pop();ans.push_back(x),upd(x);
        for(int i:E[x]){
            deg[i]--;
            if(!deg[i]&&!ban[i])q.push(i);
        }
    }
    if(ans.size()!=n){
        puts("-1");
        return 0;
    }
    for(int i:ans)printf("%d ",i);puts("");
    return 0;
}
int main(){
    int t=1;
    while(t--)solve();
    return 0;
}