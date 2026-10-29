#include<bits/stdc++.h>
using namespace std;
int n,h[1005],vis[1005],vv[1005],lmx[1005],rmx[1004];
set<int>ans;
void dfs(int x){
    if (x>n){
            int sum=0;
        for (int i=1;i<=n;i++) lmx[i]=max(lmx[i-1],vis[i]);
        for (int i=n;i>=1;i--) rmx[i]=max(rmx[i+1],vis[i]);
        for (int i=1;i<=n;i++) {
            sum+=max(0,min(lmx[i],rmx[i])-vis[i]);
        }
        ans.insert(sum);
    }
    for(int i=1;i<=n;i++){
        if (vv[i]==1) continue;
        vv[i]=1;
        vis[x]=h[i];
        dfs(x+1);
        vis[x]=0;
        vv[i]=0;
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("cup.in","r",stdin);
    freopen("cup.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>h[i];
    dfs(1);
    for (auto it=ans.begin();it!=ans.end();it++) cout<<(*it)<<" ";
    return 0;
}
