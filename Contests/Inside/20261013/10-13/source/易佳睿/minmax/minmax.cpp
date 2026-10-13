#include<bits/stdc++.h>
using namespace std;
constexpr int X=1e5+5;

int N,M,a[X],b[X];
vector<int> G[X];

void solve()
{
    for(int i=1;i<=N;i++) G[i].clear();

    cin>>N>>M;
    for(int i=1;i<=N;i++) cin>>a[i];
    for(int i=1;i<=M;i++) cin>>b[i];

    for(int i=1;i<=N;i++) G[a[i]].push_back(i);

    for(int i=1,j=0;i<=M;i++){
        // cerr<<j<<' ';
        auto it=upper_bound(G[b[i]].begin(),G[b[i]].end(),j);
        if(it==G[b[i]].end()){
            // cerr<<endl;
            cout<<"No\n"; return ;
        }
        else j=*it;
    }
    // cerr<<endl;
    cout<<"Yes\n";
}

signed main()
{
    freopen("minmax.in","r",stdin);
    freopen("minmax.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--) solve();
}