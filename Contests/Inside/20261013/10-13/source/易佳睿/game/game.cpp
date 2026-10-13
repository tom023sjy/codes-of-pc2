#include<bits/stdc++.h>
using namespace std;
constexpr int X=2e5+5,Mod=1e9+7;

int N,fa[X],dep[X],res=1;
vector<int> G[X];
vector<int> nG[X];

bool vis[X];

inline pair<int,int> DFS(int f,int u,int d)
{
    int sz=1, dp=d;
    for(int v:nG[u]){
        if(f==v) continue;
        pair<int,int> res(0,0);
        res=DFS(u,v,d+1);
        sz+=res.first;
        dp=max(dp,res.second);
    } 
    return make_pair(sz,dp);
}

inline bool check()
{
    int SZ=0;
    for(int i=1;i<=N;i++) SZ+=vis[i];
    if(DFS(0,1,1).first!=SZ) return 0;
    // cerr<<"IN\n";
    int dp=0, cnt=0;
    for(int v:nG[1]){
        pair<int,int> res=DFS(1,v,2);
        if(res.second==dp) cnt++;
        else if(res.second>dp) dp=res.second, cnt=1;
    } 
    // cerr<<dp<<' '<<cnt<<endl;
    if(cnt>=2) return 1;
    return 0;
}

signed main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    for(int i=1;i<N;i++){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    if(N>10) return cout<<1, 0;

    for(int i=2;i<(1<<N);i++){
        for(int j=1;j<=N;j++) vis[j]=0;
        for(int j=1;j<=N;j++) nG[j].clear();
        for(int j=1;j<=N;j++){
            if(i&(1<<j-1)) vis[j]=1; 
        }

        // for(int i=1;i<=N;i++) cerr<<vis[i]<<' '; cerr<<endl;

        if(vis[1]==0) continue;
        for(int j=1;j<=N;j++){
            if(!vis[j]) continue;
            for(int k:G[j]){
                if(vis[k]) nG[j].push_back(k);
            }
        }
        // for(int i=1;i<=N;i++){
        //     cerr<<i<<": ";
        //     for(int x:nG[i]) cerr<<x<<' ';
        //     cerr<<endl;
        // }

        // cerr<<"IN\n";

        res+=check();
    }

    cout<<res;

}