#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
int h[2005];
bool pan[20];
bool panans[100005];
int premax[20],lstmax[20];
int x[20];int n;
void dfs(int k)
{
    if (k > n)
    {
        int fmax=0,ans=0;
        for (int i = 1;i <= n;i++)
        {
            fmax=max(fmax,x[i]);
            premax[i]=fmax;
        }
        fmax=0;
        for (int i = n;i >= 1;i--)
        {
            fmax=max(fmax,x[i]);
            lstmax[i]=fmax;
        }
        for (int i = 1;i <= n;i++)
        {
            ans+=min(premax[i],lstmax[i])-x[i];
        }
        panans[ans]=1;
        return;
    }
    for (int i = 1;i <= n;i++)
    {
        if(pan[i])
        {
            continue;
        }
        pan[i]=1;
        x[k]=h[i];
        dfs(k+1);
        pan[i]=0;
        x[k]=0;
    }
    return;
}
signed main()
{
    freopen("cup.in","r",stdin);
    freopen("cup.out","w",stdout);
    
    read(n);
    for (int i = 1;i <= n;i++)
    {
        read(h[i]);
    }
    dfs(1);
    for (int i = 0;i <= 50*n;i++)
    {
        if (panans[i])
        {
            write(i);
            putchar(' ');
        }
    }
    return 0;
}