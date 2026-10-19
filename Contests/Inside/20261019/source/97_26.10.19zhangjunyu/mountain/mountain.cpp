#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
const int MOD=1e9+7;
inline void read(int &a)
{
    int s=0,w=1;
    char ch=getchar();
    while (ch > '9' or ch < '0')
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
    putchar('0'+x%10);
    return;
}
string s;
int dp[1100005][20];
int popcount(int x)
{
    int cnt=0;
    while (x > 0)
    {
        if (x&1)
        {
            cnt++;
        }
        x/=2;
    }
    return cnt;
}
vector<int> num[25];
int qpow(int x,int y)
{
    int ans=1,base=x;
    while (y > 0)
    {
        if (y&1)
        {
            ans*=base;
            ans%=MOD;
        }
        base*=base;
        base%=MOD;
        y/=2;
    }
    return ans;
}
signed main()
{
    freopen("mountain.in","r",stdin);
    freopen("mountain.out","w",stdout);
    int cid;
    cin >> cid;
    cin >> s;
    int n=s.length();
    //s=' '+s;
    for (int i = 0;i < n;i++)
    {
        dp[(1<<i)][i]=1;
    }
    for (int i = 0;i < (1<<n);i++)
    {
        num[popcount(i)].push_back(i);
    }
    if (cid == 10)
    {
        int now=1;
        for (int i = 1;i < n;i++)
        {
            write(now);
            putchar(' ');
            now*=2;
            now%=MOD;
        }
        write(1);
        return 0;
    }
    if (cid == 11)
    {
        write(1);
        putchar(' ');
        for (int i = n-2;i >= 0;i--)
        {
            write(qpow(2,i));
            putchar(' ');
        }
        return 0;
    }
    for (int tiat=1;tiat < n;tiat++)
    {
        for (int k = 0;k < num[tiat].size();k++)
        {
            for (int i = 0;i < n;i++)
            {
                if ((1<<i)&num[tiat][k])
                {
                    if (s[i] == 'U')
                    {
                        for (int j = i+1;j < n;j++)
                        {
                            if ((1<<j)&num[tiat][k])
                            {
                                continue;
                            }
                            dp[num[tiat][k]|(1<<j)][j]+=dp[num[tiat][k]][i];
                            dp[num[tiat][k]|(1<<j)][j]%=MOD;
                        }
                    }
                    else
                    {
                        for (int j = i-1;j >= 0;j--)
                        {
                            if ((1<<j)&num[tiat][k])
                            {
                                continue;
                            }
                            dp[num[tiat][k]|(1<<j)][j]+=dp[num[tiat][k]][i];
                            dp[num[tiat][k]|(1<<j)][j]%=MOD;
                        }
                    }
                }
            }
        }
        
    }
    for (int i = 0;i < n;i++)
    {
        write(dp[(1<<n)-1][i]);
        putchar(' ');
    }
    return 0;
}