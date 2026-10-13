#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int d[N],dfn[N],tot,ed[N],dep[N],in[N],tag[N];
vector<int> G[N],vec[N],G2[N];
int n;
void DFS(int u,int fa){
    dep[u]=dep[fa]+1;
    vec[dep[u]].push_back(u);
    dfn[u]=++tot;
    ed[u]=dfn[u];
    for(auto v:G[u]){
        if(v==fa) continue;
        DFS(v,u);
        ed[u]=max(ed[u],ed[v]);
    }
    return ;
}
vector<int> ans;
void topo(){
    priority_queue<int,vector<int>,greater<int>> Q;
    for(int i=1;i<=n;i++){
        if(in[i]==0&&!tag[i]) Q.push(i);
    }
    while(Q.size()){
        int u=Q.top();
        Q.pop();
        ans.push_back(u);
        for(int i=1;i<=n;i++){
            if(!tag[i]) continue;
            if(dfn[u]<dfn[i]||dfn[u]>ed[i]) continue;
            if(dep[u]-dep[i]==d[i]){
                tag[i]=0;
                if(in[i]==0) Q.push(i);
            }
        }
        for(auto v:G2[u]){
            in[v]--;
            if(in[v]==0&&tag[v]==0) Q.push(v);
        }
    }
    if(ans.size()!=n) cout<<-1<<endl;
    else{
        for(auto x:ans) cout<<x<<" ";
        cout<<endl;
    }
    return ;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    freopen("perm.in","r",stdin);
    freopen("perm.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>d[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v),G[v].push_back(u);
    }
    DFS(1,0);
    for(int i=1;i<=n;i++){
        if(d[i]==-1){
            for(int j=dep[i]+1;j<=n;j++){
                for(auto x:vec[j]){
                    if(dfn[x]<dfn[i]||dfn[x]>ed[i]) continue;
                    G2[i].push_back(x),in[x]++;
                }
            }
            continue;
        }
        tag[i]=1;
        // int mi=1e9,cnt=0;
        // for(auto x:vec[dep[i]+d[i]]){
        //     if(dfn[x]<dfn[i]||dfn[x]>ed[i]) continue;
        //     if(x<i){
        //         G2[x].push_back(i),in[i]++,cnt++;
        //     }
        //     mi=min(mi,x);
        // }
        // if(cnt==0){
        //     G2[mi].push_back(i),in[i]++;
        // }
        for(int j=dep[i]+1;j<dep[i]+d[i];j++){
            for(auto x:vec[j]){
                if(dfn[x]<dfn[i]||dfn[x]>ed[i]) continue;
                G2[i].push_back(x),in[x]++;
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(auto x:G2[i]) cout<<x<<" ";
    //     cout<<endl;
    // }
    topo();
    return 0;
}