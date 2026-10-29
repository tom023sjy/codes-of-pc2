#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,m;
bool check(int n)
{
    int Sum=0;
    for(int i=1;i<n;i++)
        if(__gcd(i,n)==1) Sum+=i;
    return Sum==m;
}
signed main()
{
    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>m;
        bool Flag=0;
        for(int i=1;i<=403;i++)
            if(check(i))
            {
                cout<<i<<'\n';
                Flag=1;
                break;
            }
        if(Flag) continue;
        long double M=1.0*m,n=0.5+sqrt(2.0*m+2.25);
        printf("%.0llf",n);
    }
}
