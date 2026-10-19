#include<iostream>
using namespace std;
const long long mod=1e9+7;
string str;
long long f[1100005][21],C[5005][5005];
int n,cid;
void solveA()
{
    for(int i=1;i<n;i++)
    {
        long long ans=0;
        for(int j=1;j<n;j++)
            ans=(ans+C[i-1][n-j-1])%mod;
        cout<<ans<<" ";
    }
    cout<<1<<"\n";
    return ;
}
void solveB()
{
    cout<<"1 ";
    for(int i=2;i<=n;i++)
    {
        long long ans=0;
        for(int j=1;j<n;j++)
            ans=(ans+C[n-i][n-j-1])%mod;
        cout<<ans<<" ";
    }
    return ;
}
int main()
{
    freopen("mountain.in","r",stdin);
    freopen("mountain.out","w",stdout);
    cin>>cid>>str;
    n=str.length();
    for(int i=0;i<=n;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
    if(cid==10)
    {
        solveA();
        return 0;
    }
    if(cid==11)
    {
        solveB();
        return 0;
    }
    for(int i=1;i<=n;i++)
        f[1<<(i-1)][i]=1;
    for(int s=1;s<(1<<n);s++)
    {
        for(int i=1;i<=n;i++)
        {
            if(((s>>(i-1))&1)==0)
                continue;
            int t=s-(1<<(i-1));
            for(int j=1;j<=n;j++)
            {
                if(((t>>(j-1))&1)==0)
                    continue;
                if(str[j-1]=='U'&&i>j)
                    f[s][i]=(f[s][i]+f[t][j])%mod;
                if(str[j-1]=='D'&&i<j)
                    f[s][i]=(f[s][i]+f[t][j])%mod;
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<f[(1<<n)-1][i]<<" ";
    return 0;
}