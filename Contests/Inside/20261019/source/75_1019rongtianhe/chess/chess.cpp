#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ll ans=0;
const int N=1e5+5;
int c[N];
struct node{
    int x,y,xx,yy,c;
}a[N];
bool cmp(node p,node q){
    return p.c>q.c;
}
int vis[5005][5005],used[N],tmp[5005][5005];
int n,H,W;
void DFS(int dep){
    if(dep==n+1){
        ll tmp=0;
        for(int i=1;i<=H;i++){
            for(int j=1;j<=W;j++) cout<<vis[i][j]<<" ",tmp+=vis[i][j]*(vis[i][j]-1)/2;
            cout<<endl;
        }
        cout<<tmp<<endl<<endl;
        ans=max(ans,tmp);
        return ;
    }
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            if(i>=a[dep].x&&i<=a[dep].xx&&j>=a[dep].y&&j<=a[dep].yy) continue;
            vis[i][j]+=a[dep].c;
            DFS(dep+1);
            vis[i][j]-=a[dep].c;
        }
    }
}
void add(){
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++) tmp[i][j]=vis[i][j];
    }
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            tmp[i][j]+=tmp[i-1][j];
        }
    }
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            tmp[i][j]+=tmp[i][j-1];
        }
    }
    return ;
}
bool checkA(){
    for(int i=1;i<=n;i++){
        if(a[i].x==1&&a[i].y==1) return 0;
    }
    return 1;
}
int main(){
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    int id;
    cin>>id;
    cin>>n>>H>>W;
    for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].xx>>a[i].yy>>a[i].c;
    sort(a+1,a+n+1,cmp);
    if(checkA()){
        int tot=0;
        for(int i=1;i<=n;i++) tot+=a[i].c;
        cout<<1ll*tot*(tot-1);
        return 0; 
    }
    // DFS(1);
    for(int i=1;i<=n;i++){
        ull tot=0;
        for(int j=1;j<=H;j++){
            for(int k=1;k<=W;k++) vis[j][k]=0;
        }
        for(int j=i;j<=n;j++){
            if(used[j]) continue;
            vis[a[j].x][a[j].y]++;
            vis[a[j].xx+1][a[j].y]--;
            vis[a[j].x][a[j].yy+1]--;
            vis[a[j].xx+1][a[j].yy+1]++;
            add();
            int mi=1e9;
            for(int x=1;x<=H;x++){
                for(int y=1;y<=W;y++){
                    mi=min(mi,tmp[x][y]);
                }
            }
            if(mi!=0){
                vis[a[j].x][a[j].y]--;
                vis[a[j].xx+1][a[j].y]++;
                vis[a[j].x][a[j].yy+1]++;
                vis[a[j].xx+1][a[j].yy+1]--;
                continue;
            }
            // for(int x=1;x<=H;x++){
            //     for(int y=1;y<=W;y++) cout<<vis[x][y]<<" ";
            //     cout<<endl;
            // }
            used[j]=1;
            // cout<<tot<<"--->";
            tot+=a[j].c;
            // cout<<tot<<endl;
        }
        ans+=(tot-1)*tot/2;
    }
    cout<<ans<<endl;
}