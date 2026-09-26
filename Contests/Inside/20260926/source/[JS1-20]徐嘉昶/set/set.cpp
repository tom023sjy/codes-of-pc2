#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int n,ans=1;
int cnt[40005];
int vis[40005];
int qpow(int a,int b)
{
    int re=1;
    while(b)
    {
        if(b&1) re*=a,re%=MOD;
        a*=a,a%=MOD;
        b>>=1;
    }
    return re;
}
signed main()
{
    freopen("set.in","r",stdin);
    freopen("set.out","w",stdout);
    cin>>n;
    vis[0]=1,cnt[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=n*(n+1)/2;j>=i;j--)
        {
            if(vis[j-i])
            {
                cnt[j]+=cnt[j-i];
                vis[j]=1;
                cnt[j]%=(MOD-1);
            }
        }
    }
    for(int i=1;i<=n*(n+1)/2;i++)
    {
        ans*=qpow(i,cnt[i]);
        ans%=MOD;
    }
    cout<<ans;
    return 0;
}