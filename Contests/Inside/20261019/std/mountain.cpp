#include <bits/stdc++.h>
using namespace std;

const int N = 5010,mod = 1e9+7;

int cid,n;
int tp[N];
string s;
int f[N][N],g[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("mountain.in","r",stdin);
    freopen("mountain.out","w",stdout);
    cin >> cid >> s;n = s.size();s = ' ' + s;
    if(n == 1)
    {
        cout << 1;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i] == 'U') tp[i] = 1;
        else tp[i] = 0;
    }
    f[0][0] = 1;
    f[1][1] = tp[1]?1:0;
    for(int i=2;i<=n;i++)
    {
        if(tp[i])
        {
            for(int j=1;j<i;j++)
            {
                f[i][j] = (f[i][j] + 1ll*f[i-1][j]*j) % mod;
                f[i][j+1] = (f[i][j+1] + 1ll*f[i-1][j]*(j+1)) % mod;
            }
        }
        else
        {
            for(int j=1;j<i;j++)
            {
                f[i][j] = (f[i][j] + 1ll*f[i-1][j]*j) % mod;
                f[i][j-1] = (f[i][j-1] + 1ll*f[i-1][j]*(j-1)) % mod;
            }
        }
    }
    g[n+1][0] = 1;
    g[n][1] = tp[n]?0:1;
    for(int i=n-1;i>=1;i--)
    {
        if(tp[i])
        {
            for(int j=1;j<=n-i;j++)
            {
                g[i][j] = (g[i][j] + 1ll*g[i+1][j]*j) % mod;
                g[i][j-1] = (g[i][j-1] + 1ll*g[i+1][j]*(j-1)) % mod;
            }
        }
        else
        {
            for(int j=1;j<=n-i;j++)
            {
                g[i][j] = (g[i][j] + 1ll*g[i+1][j]*j) % mod;
                g[i][j+1] = (g[i][j+1] + 1ll*g[i+1][j]*(j+1)) % mod;
            }
        }
    }
    cout << g[2][1] << ' ';
    for(int i=2;i<n;i++)
    {
        int ans=0;
        for(int j=1;j<i;j++)
        {
            ans = (ans + 1ll*f[i-1][j]*g[i+1][j+1]) % mod;
            ans = (ans + 1ll*f[i-1][j]*g[i+1][j]*2) % mod;
            ans = (ans + 1ll*f[i-1][j]*g[i+1][j-1]) % mod;
        }
        cout << ans << ' ';
    }
    cout << f[n-1][1] << ' ';
}