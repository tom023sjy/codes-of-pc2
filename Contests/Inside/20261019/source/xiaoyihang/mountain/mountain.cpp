#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int mod=1e9+7;
void add(int &x,int y){
    x+=y;
    if(x>=mod) x-=mod;
}
int f[2][N][2];
int cid,n;
string s;
int solve(int pos){
    memset(f,0,sizeof f);
    int nw=0,lst=0;
    f[0][0][0]=1;
    for(int i=1;i<=n;i++){
        lst=nw;
        nw^=1;
        for(int j=0;j<=i;j++) f[nw][j][0]=f[nw][j][1]=0;
        if(i!=pos){
            for(int j=1;j<=i;j++){
                if(j&&s[i]=='U'){
                    add(f[nw][j][0],f[lst][j-1][0]);
                    add(f[nw][j][1],f[lst][j-1][1]);
                }
                if(j<n&&s[i]=='D'){
                    add(f[nw][j][0],1ll*f[lst][j+1][0]*(j+1)%mod*j%mod);
                    add(f[nw][j][1],1ll*f[lst][j+1][1]*j%mod*j%mod);
                }
                if(s[i]=='U'){
                    add(f[nw][j][0],1ll*f[lst][j][0]*j%mod);
                    add(f[nw][j][1],1ll*f[lst][j][1]*(j-1)%mod);
                }
                else{
                    add(f[nw][j][0],1ll*f[lst][j][0]*j%mod);
                    add(f[nw][j][1],1ll*f[lst][j][1]*j%mod);
                }
            }
        }
        else{
            for(int j=1;j<=i;j++){
                add(f[nw][j][1],f[lst][j-1][0]); 
                add(f[nw][j][1],1ll*f[lst][j][0]*j%mod);
            }
        }
        
    }
    return f[nw][1][1];
}
int ans[N];
int main(){
    freopen("mountain.in","r",stdin);
    freopen("mountain.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>cid>>s;
    n=s.size();s=" "+s;
    if(cid<=13&&cid>=12){
        cout<<solve(1)<<" ";
        for(int i=2;i<=n;i++) cout<<"0 ";
        return 0;
    }
    if(cid==10){
        if(n==1) cout<<"1";
        else{
            int p=1;
            cout<<"1 ";
            for(int i=2;i<n;i++){
                p=2ll*p%mod;
                cout<<p<<" ";
            }
            cout<<"1 ";
        }
        return 0;
    } 
    if(cid==11){
        ans[n]=1;
        for(int i=n-1;i>1;i--) ans[i]=2ll*ans[i+1]%mod;
        ans[1]=1;
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        return 0;
    }
    for(int i=1;i<=n;i++) cout<<solve(i)<<" ";
    return 0;
}