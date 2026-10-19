#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>pii;
#define fi first
#define se second
const int N = 1e5+10;
const int M = 5050;
int cid;
int n,h,w;
int ans = 0;
struct node{
    int xx,xy,yx,yy,num;
}a[N];
int c[M][M];
int sum[M][M];
bool vis[N];
signed main(){
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>cid;
    cin>>n>>h>>w;
    for(int i = 1;i<=n;i++){
        cin>>a[i].xx>>a[i].yx>>a[i].xy>>a[i].yy>>a[i].num;
        c[1][1]+=a[i].num;
        c[a[i].xx][a[i].yx]-=a[i].num;
        c[a[i].xy+1][a[i].yx]+=a[i].num;
        c[a[i].xx][a[i].yy+1]+=a[i].num;
        c[a[i].xy+1][a[i].yy+1]-=a[i].num;
    }
    for(int i = 1;i<=h;i++){
        for(int j = 1;j<=w;j++){
            sum[i][j] = c[i][j]+sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
        }
    }
    while(1){
        int maxn = 0;
        pii tmp = {0,0};
        for(int i = 1;i<=h;i++){
            for(int j = 1;j<=w;j++){
                if(sum[i][j]>maxn){
                    maxn = sum[i][j];
                    tmp = {i,j};
                }
            }
        }
        if(maxn==0)break;
        ans+=maxn*(maxn-1)/2;
        for(int i = 1;i<=n;i++){
            if(vis[i])continue;
            if(!(a[i].xx<=tmp.fi&&tmp.fi<=a[i].xy&&a[i].yx<=tmp.se&&tmp.se<=a[i].yy)){
                vis[i] = 1;
                c[1][1]-=a[i].num;
                c[a[i].xx][a[i].yx]+=a[i].num;
                c[a[i].xy+1][a[i].yx]-=a[i].num;
                c[a[i].xx][a[i].yy+1]-=a[i].num;
                c[a[i].xy+1][a[i].yy+1]+=a[i].num;
            }
        }
        for(int i = 1;i<=h;i++){
            for(int j = 1;j<=w;j++){
                sum[i][j] = c[i][j]+sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
            }
        }
    }
    cout<<ans;
    return 0;
}