#include <bits/stdc++.h>
using namespace std;
#define int long long
inline void read(int &a)
{
    int s=0,w=1;
    char ch=getchar();
    while (ch < '0' or ch > '9')
    {
        if (ch == '-')
        {
            w=-1;
        }
        ch=getchar();
    }
    while (ch >='0' and ch <= '9')
    {
        s=s*10+ch-'0';
        ch=getchar();
    }
    a=s*w;
}
void write(int x)
{
    if (x < 0)
    {
        putchar('-');
        x=-x;
    }
    if (x > 9)
    {
        write(x/10);
    }
    putchar(x%10+'0');
    return;
}

int a[1000005];
int dp[1005][2][1005];//到第i个，且谁送最后一个，且另一个人在哪
signed main()
{
    freopen("express.in","r",stdin);
    freopen("express.out","w",stdout);
    int n;
    read(n);
    for (int i = 1;i <= n;i++)
    {
        read(a[i]);
    }
    dp[1][0][0]=a[1];
    dp[1][1][0]=a[1];
    for (int i = 2;i <= n;i++)
    {
        for (int k = i-1;k >= 0;k--)
        {
            dp[i][0][k]=LLONG_MAX/2;
            
            
            
            
            //dp[i][0][k]=min(dp[i][0][k],dp[i-1][1][k]+abs(a[i]-a[j]));
            
            dp[i][1][k]=LLONG_MAX/2;
            
            
            
            
            //dp[i][1][k]=min(dp[i][1][k],dp[i-1][0][k]+abs(a[i]-a[j]));
            if (k == i-1)
            {
                for (int j = i-2;j >= 0;j--)
                {
                    dp[i][1][k]=min(dp[i][1][k],dp[i-1][0][j]+abs(a[i]-a[j]));
                }
                for (int j = i-2;j >= 0;j--)
                {
                    dp[i][0][k]=min(dp[i][0][k],dp[i-1][1][j]+abs(a[i]-a[j]));
                }
            }
            else
            {
                dp[i][0][k]=min(dp[i][0][k],dp[i-1][0][k]+abs(a[i]-a[i-1]));
                dp[i][1][k]=min(dp[i][1][k],dp[i-1][1][k]+abs(a[i]-a[i-1]));
            }
        }
    }
    int ans=LLONG_MAX/2;
    for (int i = n-1;i >= 0;i--)
    {
        ans=min({ans,dp[n][0][i],dp[n][1][i]});
    }
    write(ans);
    return 0;
}