#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=1e5+5,M=5005;
struct node{
    int x1,y1,x2,y2,c;
}a[N];
int cid,n,h,w;
int s[M][M];
int cnt; 
ull ans;
bool vis[N];
void solve(){
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        s[1][1]+=a[i].c;
        s[a[i].x1][a[i].y1]-=a[i].c;
        s[a[i].x1][a[i].y2+1]+=a[i].c;
        s[a[i].x2+1][a[i].y1]+=a[i].c;
        s[a[i].x2+1][a[i].y2+1]-=a[i].c;
    }
    int mx=0,p1=0,p2=0; 
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
            if(mx<s[i][j]){
                mx=s[i][j];
                p1=i,p2=j;
            }
        }
    }
    cnt-=mx;  
    ull num=1ll*mx*(mx-1)/2;
    ans+=num; 
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        if(!(a[i].x1<=p1&&p1<=a[i].x2&&a[i].y1<=p2&&p2<=a[i].y2)) vis[i]=1;
    } 
    for(int i=1;i<=h;i++) for(int j=1;j<=w;j++) s[i][j]=0;
}
int main(){
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>cid>>n>>h>>w; 
    for(int i=1;i<=n;i++){
        cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2>>a[i].c;
        // cerr<<i<<"\n";
    }
    // cerr<<"YES\n";
    for(int i=1;i<=n;i++) cnt+=a[i].c;
    int tot=0;
    while(cnt){
        solve(); 
    } 
    cout<<ans;
    return 0;
}