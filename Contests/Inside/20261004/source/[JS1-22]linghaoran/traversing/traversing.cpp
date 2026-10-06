#include<bits/stdc++.h>
using namespace std;
int cnt,ans,n,q,son[100005][2],ask[100005][4],x[100005];
void bl(int r,int q){
    if(x[r]==-1){
        ++cnt;
        if(r==q) ans=cnt;
        if(son[r][0]) bl(son[r][0],q);
        if(son[r][1]) bl(son[r][1],q);
    }
    if(x[r]==0){
        if(son[r][0]) bl(son[r][0],q);
        ++cnt;
        if(r==q) ans=cnt;
        if(son[r][1]) bl(son[r][1],q);
    }
    if(x[r]==1){
        if(son[r][0]) bl(son[r][0],q);
        if(son[r][1]) bl(son[r][1],q);
        ++cnt;
        if(r==q) ans=cnt;
    }
}
int main(){
	freopen("traversing.in","r",stdin);
	freopen("traversing.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
    fill(x+1,x+n+1,-1);
    for(int i=1;i<=n;++i){
        cin>>son[i][0]>>son[i][1];
    }
    for(int i=1;i<=q;++i){
        cin>>ask[i][0];
        if(ask[i][0]==1){
            cin>>ask[i][1]>>ask[i][2]>>ask[i][3];
        }
        if(ask[i][0]==2){
            cin>>ask[i][1];
        }
    }
    if(n<=5000&&q<=5000){
        for(int i=1;i<=q;++i){
            cnt=0,ans=0;
            if(ask[i][0]==1){
                for(int j=ask[i][1];j<=ask[i][2];++j){
                    x[j]=ask[i][3];
                }
            }
            else{
                bl(1,ask[i][1]);
                cout<<ans<<'\n';
            }
        }
    }
    return 0;
}
