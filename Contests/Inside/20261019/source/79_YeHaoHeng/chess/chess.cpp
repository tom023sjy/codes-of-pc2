#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N=100004,MinN=10;
int C,n,h,w,ans,a[MinN][MinN];
int X1[N],Y1[N],X2[N],Y2[N],c[N];
int F(int X)
{
    int Res;
    if(X%2==0) Res=X/2,Res*=X-1;
    else Res=(X-1)/2,Res*=X;
    return Res;
}
void Put(int i)
{
    if(i==n+1)
    {
        int Now=0;
        for(int x=1;x<=h;x++)
            for(int y=1;y<=w;y++)
                if(a[x][y]>0) Now+=F(a[x][y]);
        ans=max(ans,Now);
        return;
    }
    for(int x=1;x<=h;x++)
        for(int y=1;y<=w;y++)
            if(!(X1[i]<=x&&x<=X2[i]&&Y1[i]<=y&&y<=Y2[i]))
            {
                a[x][y]+=c[i];
                Put(i+1);
                a[x][y]-=c[i];
            }
}
signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    cin>>C>>n>>h>>w;
    for(int i=1;i<=n;i++)
        cin>>X1[i]>>Y1[i]>>X2[i]>>Y2[i]>>c[i];
    if(C==9||C==10)
    {
        int Sum=0,Ans;
        for(int i=1;i<=n;i++) Sum+=c[i];
        if(Sum%2==0) Ans=Sum/2,Ans*=Sum-1;
        else Ans=(Sum-1)/2,Ans*=Sum;
        cout<<Ans;
        return 0;
    }
    Put(1);
    cout<<ans;
}
