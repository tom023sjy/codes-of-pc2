#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005,mod=1e9+7;
int C,n,ans[N],S[N];
bool Vis[N];
string s;
void Put(int u,int tot,int Side)
{
    if(tot==n)
    {
        ans[u]=(ans[u]+1)%mod;
        return;
    }
    if(Side)
    {
        for(int i=u+1;i<=n;i++)
            if(!Vis[i])
            {
                Vis[i]=1;
                Put(i,tot+1,S[i]);
                Vis[i]=0;
            }
    }
    else
    {
        for(int i=u-1;i>=1;i--)
            if(!Vis[i])
            {
                Vis[i]=1;
                Put(i,tot+1,S[i]);
                Vis[i]=0;
            }
    }
}
signed main()
{
    freopen("mountain.in","r",stdin);
    freopen("mountain.out","w",stdout);
    cin>>C>>s,n=s.size();
    for(int i=1;i<=n;i++) S[i]=(s[i-1]=='U');
    if(C==10)
    {
        for(int i=1,x=1;i<n;i++) cout<<x<<' ',x=(x*2)%mod;
        cout<<1;
        return 0;
    }
    else if(C==11)
    {
        for(int i=n,x=1;i>1;i--) ans[i]=x,x=(x*2)%mod;
        ans[1]=1;
        for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
        return 0;
    }
    else for(int i=1;i<=n;i++)
    {
        Vis[i]=1;
        Put(i,1,S[i]);
        Vis[i]=0;
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
}
