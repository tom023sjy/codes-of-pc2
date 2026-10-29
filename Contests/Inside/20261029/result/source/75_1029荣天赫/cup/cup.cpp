#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int a[N],b[N],vis[N],n;
set<int> st;
void DFS(int dep){
    if(dep==n+1){
        // for(int i=1;i<=n;i++) cout<<a[b[i]]<<" ";
        // cout<<'\n';
        int tmp=0;
        for(int i=1;i<=n;i++){
            int pmx=0,smx=0;
            for(int l=1;l<i;l++) pmx=max(pmx,a[b[l]]);
            for(int r=i+1;r<=n;r++) smx=max(smx,a[b[r]]);
            tmp+=max(0,min(pmx,smx)-a[b[i]]);
        }
        st.insert(tmp);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        b[dep]=i;
        vis[i]=1;
        DFS(dep+1);
        vis[i]=0;
    }
    return ;
}
int main(){
    freopen("cup.in","r",stdin);
    freopen("cup.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    DFS(1);
    for(auto x:st) cout<<x<<" ";
    cout<<'\n';
    return 0;
}