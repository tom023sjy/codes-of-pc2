#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=5e3+5;
int n,h,w;
typedef long long ll;
bool vis[N];
int l1[N],r1[N],l2[N],r2[N],c[N];
int dt[M][M],f[M][M];
ll C2(int x){return 1ll*x*(x-1)/2;}
ll ans;
int sm;
int main(){
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    scanf("%*d%d%d%d",&n,&h,&w);
    for(int i=1;i<=n;i++)scanf("%d%d%d%d%d",l1+i,l2+i,r1+i,r2+i,c+i),sm+=c[i],f[l1[i]][l2[i]]+=c[i],f[r1[i]+1][l2[i]]-=c[i],f[r1[i]+1][r2[i]+1]+=c[i],f[l1[i]][r2[i]+1]-=c[i];
    for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)f[i][j]+=f[i][j-1];
    for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)f[i][j]+=f[i-1][j];
    while(sm){
        int vx=1,vy=1;
        for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)if(f[i][j]<f[vx][vy])vx=i,vy=j;
        ans+=C2(sm-f[vx][vy]);
        memset(dt,0,sizeof(dt));
        for(int i=1;i<=n;i++)if(!vis[i]&&!(l1[i]<=vx&&vx<=r1[i]&&l2[i]<=vy&&vy<=r2[i])){
            vis[i]=1;sm-=c[i];
            dt[l1[i]][l2[i]]+=c[i],dt[r1[i]+1][l2[i]]-=c[i],dt[r1[i]+1][r2[i]+1]+=c[i],dt[l1[i]][r2[i]+1]-=c[i];
        }
        for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)dt[i][j]+=dt[i][j-1];
        for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)dt[i][j]+=dt[i-1][j];
        for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)f[i][j]-=dt[i][j];
    }
    printf("%lld\n",ans);
    return 0;
}