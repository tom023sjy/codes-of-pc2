#include <bits/stdc++.h>
#define int __int128
using namespace std;

const int N=2e5+5;
int T,n,p[N],vis[N],cnt=0;

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

void init ()
{
    for (int i=2;i<=2e5;i++)
    {
        if (!vis[i]) cnt++,p[cnt]=i;
        for (int j=1;j<=cnt&&i*p[j]<=2e5;j++)
        {
            vis[i*p[j]]=1;
            if (i%p[j]==0) break ;
        }
    }
}

void solve (int m)
{
    m*=2;
    for (int i=cnt;i>=1;i--)
    {
        if (m%p[i]==0)
        {
            m/=(p[i]-1);
        }
    }
    write(m);
}

signed main()
{
    //freopen("ex_guess1.in","r",stdin);
    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);
    T=read();
    init();
    while (T--)
    {
        n=read();
        if (n>1e9) write(sqrt(n*2)+1);
        else solve(n);
        putchar('\n');
    }
    return 0;
}
