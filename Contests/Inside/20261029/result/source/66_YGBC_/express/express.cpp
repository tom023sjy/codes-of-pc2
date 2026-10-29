#include<bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int X=1005, Y=1e6+5, V=55;

int N,k[X],f[X][X],res;
int g[Y][V];

void A()
{
    memset(f,0x3f,sizeof f);
    f[0][0]=0; f[1][0]=k[1];

    for(int i=2;i<=N;i++){
        for(int j=0;j<i-1;j++) f[i][j]=f[i-1][j]+abs(k[i]-k[i-1]);
        for(int j=0;j<i-1;j++) f[i][i-1]=min(f[i][i-1],f[i-1][j]+(abs(k[i]-k[j])));
    }

    res=0x3f3f3f3f3f3f3f3f;

    for(int i=0;i<N;i++) res=min(res,f[N][i]);

    cout<<res;
}
void B()
{
    memset(g,0x3f,sizeof g);

    g[0][0]=0, g[1][0]=k[1];

    for(int i=2;i<=N;i++){
        for(int p=0;p<=50;p++) g[i][p]=g[i-1][p]+abs(k[i]-k[i-1]);
        for(int p=0;p<=50;p++) g[i][k[i-1]]=min(g[i][k[i-1]],g[i-1][p]+abs(k[i]-p));
    }

    res=0x3f3f3f3f3f3f3f3f;

    for(int i=0;i<=50;i++) res=min(res,g[N][i]);

    cout<<res;
}

signed main()
{
    freopen("express.in","r",stdin);
    freopen("express.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    for(int i=1;i<=N;i++) cin>>k[i];

    if(N<=1000) A();
    else B();
} 