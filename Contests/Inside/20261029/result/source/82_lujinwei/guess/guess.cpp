#include<bits/stdc++.h>
using namespace std;
int sum[405];
int Gcd(int x,int y)
{
    if(y==0)
        return x;
    return Gcd(y,x%y);
}
__int128 read()
{
    __int128 x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
int main()
{
    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);
    int T;
    __int128 m;
    for(int i=1;i<=400;i++)
    {
        for(int j=1;j<=i;j++)
            if(Gcd(i,j)==1)
                sum[i]+=j;
    }
        
    T=read();
    while(T--)
    {
        m=read();
        long long ans=0;
        for(int i=1;i<=400;i++)
            if(sum[i]==m)
            {
                ans=i;
                break;
            }
        if(ans)
        {
            cout<<ans<<"\n";
            continue;
        }
        __int128 l=1,r=2e18,mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            __int128 val=mid*(mid-1)/2;
            if(val==m)
            {
                ans=mid;
                break;
            }
            if(val<m)
                l=mid+1;
            else
                r=mid-1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}