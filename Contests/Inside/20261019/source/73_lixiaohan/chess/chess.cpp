#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
long long x[5005][5005],y[5005][5005];
int X1[100005],Y1[100005],X2[100005],Y2[100005],c[100005];
bool vis[100005];
signed main(){
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int C,n,h,w,sum=0,has=0;
    cin>>C>>n>>h>>w;
    int cnt=n;
    for(int i=1;i<=n;i++){
        cin>>X1[i]>>Y1[i]>>X2[i]>>Y2[i]>>c[i];
        has+=c[i];
    }
    while(cnt){
        memset(x,0,sizeof(x));
        for(int i=1;i<=n;i++){
            if(vis[i]){
                continue;
            }
            x[X1[i]][Y1[i]]-=c[i];
            x[X1[i]][Y2[i]+1]+=c[i];
            x[X2[i]+1][Y1[i]]+=c[i];
            x[X2[i]+1][Y2[i]+1]-=c[i];
        }
        long long ma=-1000000000000000000,idx=0,idy=0;
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                x[i][j]+=x[i-1][j]+x[i][j-1]-x[i-1][j-1];
                if(x[i][j]>ma){
                    ma=x[i][j];
                    idx=i,idy=j;
                }
            }
        }
        sum+=(has+ma)*(has+ma-1)/2;
        has=-ma;
        for(int i=1;i<=n;i++){
            if(vis[i]){
                continue;
            }
            if(!(X1[i]<=idx&&idx<=X2[i]&&Y1[i]<=idy&&idy<=Y2[i])){
                cnt--;
                vis[i]=true;
            }
        }
    }
    cout<<sum;
    return 0;
}
