#include <bits/stdc++.h>
using namespace std;
#define int __int128_t
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
int gcd(int x,int y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y,x%y);
}
bool check(int n,int m)
{
    int now=0;
    for (int i = 1;i <= n;i++)
    {
        if (gcd(i,n) == 1)
        {
            now+=i;
        }
    }
    return (now == m);
}
vector<int> yin;
void chai(int x)
{
    for (int i = 2;i <= x;i++)
    {
        while (x%i == 0)
        {
            yin.push_back(i);
            x/=i;
        }
        if (x == 1)
        {
            break;
        }
        if (i > x)
        {
            yin.push_back(x);
            break;
        }
    }
    return;
}
signed main()
{
    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);
    int T,m;
    read(T);
    //write(gcd(9,3));
    for (int chtholly = 1;chtholly <= T;chtholly++)
    {
        read(m);
        /*if (m <= 1e9)
        {
            yin.clear();
            chai(m);
            continue;
        }*/
        int ans=0;
        for (int n = 1;n <= 400;n++)
        {
            if (check(n,m))
            {
                /*write(gcd(n,m));
                putchar(' ');
                write(m/n);
                putchar('\n');*/
                ans=n;
                break;
            }
        }
        if (ans)
        {
            write(ans);
            putchar('\n');
            continue;
        }
        int l=1,r=LLONG_MAX;
        //r*=10000000;
        int mid;
        while (l <= r)
        {
            /*write(l);
            putchar(' ');
            write(r);
            putchar('\n');*/
            mid=(l+r)/2;
            if (mid*(mid-1)/2 == m)
            {
                ans=mid;
                break;
            }
            else if (mid*(mid-1)/2 > m)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        write(ans);
        putchar('\n');
    }
    return 0;
}