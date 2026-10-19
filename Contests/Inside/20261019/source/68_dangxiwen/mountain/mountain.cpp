#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int mod=1e9+7;
const int mx=5100;
int op[mx];
string s;
int n;
int dp[1100000][21];
int fread()
{
    int x=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*w;
}
int ksm(int x,int y)
{
    int ans=1;
    while(y)
    {
        if(y&1) ans=ans*x,ans%=mod;
        x*=x,x%=mod;
        y>>=1;
    }
    return ans;
}
int fac[2*mx],finv[2*mx];
void init()
{
    fac[0]=finv[0]=1;
    for(int i=1;i<2*mx;i++) fac[i]=fac[i-1]*i%mod,finv[i]=ksm(fac[i],mod-2);
}
int C(int x,int y)
{
    return fac[x]*finv[x-y]%mod*finv[y]%mod;
}
signed main()
{
    freopen("mountain.in","r",stdin);
    freopen("mountain.out","w",stdout);
    int cid=fread();
    cin>>s;
    n=s.size();
    s=" "+s;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='U') op[i]=1;
    }
    if(cid<=5)
    {
        // bitset<3> b;
        int maxn=(1<<n)-1;
        for(int i=1;i<=n;i++) 
        {
            dp[1<<(i-1)][i]=1;
            // b=(1<<(i-1));
            // cout<<b<<' '<<i<<endl;
        }
        for(int i=1;i<=maxn;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(((i>>j-1)&1)==0)
                {
                    // b=i;
                    // cout<<"DEBUG1:"<<b<<' '<<j<<endl;
                    continue;
                } 
                // b=i;
                // cout<<"Y1:"<<b<<' '<<j<<endl;
                if(op[j]==1)
                {
                    for(int k=j+1;k<=n;k++)
                    {
                        if((i>>(k-1)&1)==1) 
                        {
                            // b=i;
                            // cout<<"DEBUG2:"<<b<<' '<<j<<' '<<k<<endl;
                            continue;
                        }
                        // b=i;
                        // cout<<"YEAH:"<<b<<' '<<j<<' '<<k<<endl;
                        dp[i|(1<<k-1)][k]+=dp[i][j];
                        dp[i|(1<<k-1)][k]%=mod;
                        // b=(i|(1<<k-1));
                        // cout<<b<<' '<<k<<' '<<dp[i|(1<<k-1)][k]<<endl;
                    }
                }
                else
                {
                    for(int k=1;k<=j-1;k++)
                    {
                        if((i>>(k-1)&1)==1) 
                        {
                            // b=i;
                            // cout<<"DEBUG2:"<<b<<' '<<j<<' '<<k<<endl;
                            continue;
                        }
                        // b=i;
                        // cout<<"YEAH:"<<b<<' '<<j<<' '<<k<<endl;
                        dp[i|(1<<k-1)][k]+=dp[i][j];
                        dp[i|(1<<k-1)][k]%=mod;
                        // b=(i|(1<<k-1));
                        // cout<<b<<' '<<k<<' '<<dp[i|(1<<k-1)][k]<<endl;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++) cout<<dp[maxn][i]<<' ';
        return 0;
    }
    if(cid==10)
    {
        for(int i=1;i<=n-1;i++)
        {
            cout<<1*ksm(2,(i-1))<<' ';
        }
        cout<<1;
        return 0;
    }
    if(cid==11)
    {
        cout<<1<<' ';
        for(int i=2;i<=n;i++)
        {
            cout<<ksm(2,(n-i))<<" ";
        }
        return 0;
    }
    return 0;
}