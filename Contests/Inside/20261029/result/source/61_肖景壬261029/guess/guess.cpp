#include<bits/stdc++.h>
using namespace std;
#define homo_number 114514
#define mod 998244353
//#define mod 1000000007
//#define int long long
int n,m,tc,phi[500005],p[500005],pcnt;
int calc(int x)
{
    int ret=0;
    for(int i = 1; i < x; i++)
    {
        if(__gcd(i,x)==1) ret+=i;
    }
    return ret;
}
signed main()
{
    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    phi[1]=1;
    for(int i = 2; i <= 100000; i++)
    {
        if(!phi[i])
        {
            pcnt++;
            p[pcnt]=i;
            phi[i]=i-1;
            for(int j = 1; j<=pcnt&&i*p[j]<=100000; j++)
            {
                if(i%p[j]==0)
                {
                    phi[i*p[j]]=phi[i]*p[j];
                    break;
                }
                phi[i*p[j]]=phi[i]*(p[j]-1);
            }
        }
    }
    cin>>tc;
    while(tc--)
    {
        cin>>m;
        m*=2;
        for(int i = 1;; i++)
        {
            if(phi[i]*i==m)
            {
                cout<<i<<'\n';
                break;
            }
        }
    }
    return 0;
}