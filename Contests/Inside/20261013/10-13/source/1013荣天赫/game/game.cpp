#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n;
vector<int> G[N];
bool check(){
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++){
        if(G[i].size()==1) cnt1++;
        if(G[i].size()==2) cnt2++;
    }
    return (cnt1==2)&&(cnt2==n-2);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v),G[v].push_back(u);
    }
    if(check()) cout<<1<<endl;
    return 0;
}