#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int a[5005];
int f[5005][5005];
int main()
{
    int cid;
    cin>>cid;
    string s;
    cin>>s;
    int n=s.size();
    for(int i=1;i<=n;i++)
    {
        if(s[i-1]=='U') a[i]=1;
        else a[i]=-1;
    }
    if(cid==10)
    {
        if(n==1) cout<<"1";
        else
        {
            int p=1;
            cout<<"1 ";
            for(int i=2;i<n;i++)
            {
                p=2ll*p%mod;
                cout<<p<<" ";
            }
            cout<<"1 ";
        }
        return 0;
    } 
    for(int pos=1;pos<=n;pos++)
    {
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                f[i][j]=0;
            }
        }
        f[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            if(i==pos)
            {
                for(int j=1;j<=i;j++)
                {
                    f[i][j]=f[i-1][j]*j%mod;
                }
            }
            else
            {
                for(int j=1;j<=i;j++)
                {
                    if(a[i]==1)
                    {
                        f[i][j]=(f[i][j]+f[i-1][j]*(j-1)%mod)%mod;
                        f[i][j]+=f[i-1][j-1];
                        f[i][j]%=mod;
                    }
                    else
                    {
                        f[i][j]+=f[i-1][j+1]*j%mod*j%mod;
                        f[i][j]+=f[i-1][j]*j;
                        f[i][j]%=mod;
                    }
                }
            }
        }
        cout<<f[n][1]<<' ';
    }
}