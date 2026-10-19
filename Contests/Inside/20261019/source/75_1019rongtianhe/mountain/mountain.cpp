#include<bits/stdc++.h>
using namespace std;
const int M=2e6+5;
const int N=5005;
const int mod=1e9+7;
int f[M][22],n;
int a[N],pw[N];
bool checkA(){
    for(int i=1;i<n;i++){
        if(a[i]!=0) return 0;
    }
    if(a[n]!=1) return 0;
    return 1;
}
bool checkB(){
    for(int i=2;i<=n;i++){
        if(a[i]!=1) return 0;
    }
    if(a[1]!=0) return 0;
    return 1;
}
int main(){
    freopen("mountain.in","r",stdin);
    freopen("mountain.out","w",stdout);
    int id;
    cin>>id;
    string s;
    cin>>s;
    n=s.length();
    for(int i=1;i<=n;i++){
        if(s[i-1]=='U') a[i]=0;
        else a[i]=1;
    }
    if(checkA()){
        pw[0]=1;
        for(int i=1;i<=n;i++) pw[i]=1ll*pw[i-1]*2%mod;
        for(int i=1;i<n;i++) cout<<pw[i-1]<<" ";
        cout<<1<<endl;
        return 0;
    }
    if(checkB()){
        pw[0]=1;
        for(int i=1;i<=n;i++) pw[i]=1ll*pw[i-1]*2%mod;
        cout<<1<<" ";
        for(int i=2;i<=n;i++) cout<<pw[n-i]<<" ";
        cout<<endl;
        return 0;
    }
    // for(int i=1;i<=n;i++) tmp[1]=i,vis[i]=1,DFS(2,i),vis[i]=0;
    for(int i=1;i<=n;i++) f[(1<<i-1)][i]=1;
    for(int i=1;i<(1<<n);i++){
        for(int j=1;j<=n;j++){
            if(!(i>>(j-1)&1)) continue;
            if(a[j]==0){
                for(int k=j+1;k<=n;k++){
                    if(i>>(k-1)&1) continue;
                    f[i|(1<<k-1)][k]=(f[i|(1<<k-1)][k]+f[i][j])%mod;
                }
            }
            else{
                for(int k=1;k<j;k++){
                    if(i>>(k-1)&1) continue;
                    f[i|(1<<k-1)][k]=(f[i|(1<<k-1)][k]+f[i][j])%mod;
                }
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<f[(1<<n)-1][i]<<" ";
    return 0;
}