#include <bits/stdc++.h>
using namespace std;

const int N=2001,H=51;
int n,a[N],c[55];
bitset <N*H> dp[N];

inline int read ()
{
    int x=0,f=1;
    char c=getchar();
    while (c<'0'||c>'9')
    {
        if (c=='-') f=-f;
        c=getchar();
    }
    while (c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}

inline void write (int x)
{
    if (x<0) putchar('-'),x=-x;
    if (x>=10) write(x/10);
    putchar(x%10+'0');
}

signed main()
{
    //freopen("ex_cup4.in","r",stdin);
    freopen("cup.in","r",stdin);
    freopen("cup.out","w",stdout);
    n=read();
    for (int i=1;i<=n;i++) a[i]=read(),c[a[i]]++;
    sort(a+1,a+n+1);
    dp[0][0]=1;
 //   cout<<dp[0];
    for (int i=n-1;i>=1;i--)
    {
        for (int j=0;j<=i;j++)
        {
            /*for (int k=0;k<=n;k++)
            {
                if (j>=a[i]&&k>=1) dp[j-a[i]][k-1]|=dp[j][k];
                dp[j+a[i]][k+1]|=dp[j][k];
            }*/
            if (j>=1) dp[j-1]|=(dp[j]>>a[i]);
            if (a[i]!=a[i-1]) dp[j+1]|=(dp[j]<<a[i]);
        }
    }
    for (int i=0;i<=n*50;i++) if (dp[0][i]) cout<<i<<' ';
    return 0;
}
