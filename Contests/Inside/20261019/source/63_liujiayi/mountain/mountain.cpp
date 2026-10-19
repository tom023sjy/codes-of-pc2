#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,mod=1e9+7;
inline void chk(int&x,int y){(x+=y)>=mod&&(x-=mod);}
char s[N];
int n,f[N][N],g[N][N];
int jie[N];
int ans[N];
int main(){
    freopen("mountain.in","r",stdin);
    freopen("mountain.out","w",stdout);
    scanf("%*d%s",s+1);n=strlen(s+1);
    f[0][0]=1;
    g[n+1][0]=1;
    jie[0]=1;
    for(int i=1;i<=n;i++)jie[i]=1ll*jie[i-1]*i%mod;
    for(int i=1;i<=n;i++)for(int j=0;j<i;j++)if(f[i-1][j]){
        if(s[i]=='U'){
            chk(f[i][j+1],f[i-1][j]);
            chk(f[i][j],1ll*f[i-1][j]*j%mod);
        }else{
            chk(f[i][j],1ll*f[i-1][j]*j%mod);
            if(j>=2)chk(f[i][j-1],1ll*f[i-1][j]*j*(j-1)%mod);
        }
    }
    for(int i=n;i>=1;i--)for(int j=0;j<=n-i;j++)if(g[i+1][j]){
        if(s[i]=='D'){
            chk(g[i][j],1ll*g[i+1][j]*j%mod);
            chk(g[i][j+1],g[i+1][j]);
        }else{
            chk(g[i][j],1ll*g[i+1][j]*j%mod);
            if(j>=2)chk(g[i][j-1],1ll*g[i+1][j]*j*(j-1)%mod);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=min(i-1,n-i);j++)if(f[i-1][j]&&g[i+1][j])chk(ans[i],2ll*f[i-1][j]*g[i+1][j]%mod*jie[j]%mod*jie[j]%mod);
        for(int j=0;j<=min(i-2,n-i);j++)if(f[i-1][j+1]&&g[i+1][j])chk(ans[i],1ll*f[i-1][j+1]*g[i+1][j]%mod*jie[j+1]%mod*jie[j]%mod);
        for(int j=0;j<=min(i-1,n-i-1);j++)if(f[i-1][j]&&g[i+1][j+1])chk(ans[i],1ll*f[i-1][j]*g[i+1][j+1]%mod*jie[j]%mod*jie[j+1]%mod);
    }
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    return 0;
}