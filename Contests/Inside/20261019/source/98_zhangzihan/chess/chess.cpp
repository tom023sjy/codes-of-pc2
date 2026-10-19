#include <iostream>
#define int unsigned long long
using namespace std;
const int N=3e6+5;
int n,H,W,x[N],y[N],X[N],Y[N],c[N];
int s[5005][5005],Ovo,flag[N];
signed main()
{
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    scanf("%lld%lld%lld%lld",&Ovo,&n,&H,&W);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld%lld%lld%lld",&x[i],&y[i],&X[i],&Y[i],&c[i]);
        s[1][1]+=c[i];
        s[x[i]][y[i]]-=c[i];
        s[X[i]+1][y[i]]+=c[i];
        s[x[i]][Y[i]+1]+=c[i];
        s[X[i]+1][Y[i]+1]-=c[i];
    }
    int mx=1,XX,YY,ans=0;
    while(mx)
    {
        mx=0;
        for(int i=1;i<=H;i++)
        {
            for(int j=1;j<=W;j++)
            {
                //cout<<i<<" "<<j<<" "<<s[i][j]<<endl;
                s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+s[i][j];
                //cout<<s[i][j]
                if(s[i][j]>mx)
                {
                    mx=s[i][j];
                    XX=i;
                    YY=j;
                }
            }
        }
    // cout<<mx<<endl;
        for(int i=1;i<=H;i++)for(int j=1;j<=W;j++)s[i][j]=0;
        ans+=mx*(mx-1)/2;
        for(int i=1;i<=n;i++)
        {
            if(x[i]<=XX&&XX<=X[i]&&y[i]<=YY&&YY<=Y[i]&&flag[i]==0)
            {
                s[1][1]+=c[i];
                s[x[i]][y[i]]-=c[i];
                s[X[i]+1][y[i]]+=c[i];
                s[x[i]][Y[i]+1]+=c[i];
                s[X[i]+1][Y[i]+1]-=c[i];
            }
            else flag[i]=1;
        }
    }
    /*mx=0;
    for(int i=1;i<=H;i++)
    {
        for(int j=1;j<=W;j++)
        {
           // cout<<i<<" "<<j<<" "<<s[i][j]<<endl;
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+s[i][j];
            if(s[i][j]>mx)
            {
                mx=s[i][j];
                XX=i;
                YY=j;
            }
        }
    }
    ans+=mx*(mx-1)/2;*/
    cout<<ans;
    return 0;
}
/*
0
2 1 2
1 1 1 1 3
1 2 1 2 4
*/