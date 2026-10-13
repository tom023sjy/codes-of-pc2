#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int a[N],b[N],n,m,id[N];
bool check(){
    int pos=1;
    for(int i=1;i<=n;i++){
        if(pos<=m&&a[i]==b[pos]) id[pos]=i,pos++;
    }
    return pos==m+1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    freopen("minmax.in","r",stdin);
    freopen("minmax.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=m;i++) cin>>b[i];
        if(!check()) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}