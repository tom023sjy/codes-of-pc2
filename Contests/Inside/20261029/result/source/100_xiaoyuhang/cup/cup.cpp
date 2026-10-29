#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,h[N];
vector<int> a[N];
bitset<100001> f[2];
int main(){
    freopen("cup.in","r",stdin);
    freopen("cup.out","w",stdout); 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i];
    sort(h+1,h+n+1);
    for(int i=1;i<=n;i++){
        a[i].push_back(0);int lst=0;
        for(int j=i;j<n;j++){
            int v=h[j]-h[i];
            if(lst==v) continue;
            lst=v;
            a[i].push_back(v);
        }
    } 
    int nw=0,lst=0;
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        lst=nw;
        nw^=1;
        f[nw].reset();
        for(int v:a[i]){
            f[nw]|=f[lst]<<v;
        }
    }
    for(int i=0;i<100001;i++){
        if(f[nw][i]) cout<<i<<" ";
    }
    return 0;
}