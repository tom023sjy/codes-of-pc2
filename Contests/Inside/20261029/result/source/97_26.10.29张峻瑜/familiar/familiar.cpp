#include <bits/stdc++.h>
using namespace std;
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
int a[1005][1005],n,m;
int getx(int num,int x)
{
    int l=1,r=m;
    int mid,pos=m+1;
    while (l <= r)
    {
        mid=(l+r)/2;
        if (a[x][mid] >= num)
        {
            pos=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return pos;
}
int gety(int num,int y)
{
    int l=1,r=m;
    int mid,pos=m+1;
    while (l <= r)
    {
        mid=(l+r)/2;
        if (a[y][mid] > num)
        {
            pos=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return pos;
}
int main()
{
    freopen("familiar.in","r",stdin);
    freopen("familiar.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T,k,opt,x,y;
    cin >> n >> m >> T;
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= m;j++)
        {
            cin >> a[i][j];
        }
    }
    for (int chtholly = 1;chtholly <= T;chtholly++)
    {
        cin >> opt >> x >> y;
        if (opt == 1)
        {
            cin >> k;
            int ans=0;
            int l=1,r=m;
            int mid;
            while (l <= r)
            {
                mid=(l+r)/2;
                int fpos=gety(a[x][mid],y);
                if (m-mid+(m-fpos+1)+1 == k)
                {
                    ans=a[x][mid];
                    break;
                }
                else if (m-mid+(m-fpos+1)+1 < k)
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            if (ans)
            {
                cout << ans << '\n';
                continue;
            }
            l=1,r=m;
            while (l <= r)
            {
                mid=(l+r)/2;
                int fpos=getx(a[y][mid],x);
                if (m-mid+(m-fpos+1)+1 == k)
                {
                    ans=a[y][mid];
                    break;
                }
                else if (m-mid+(m-fpos+1)+1 < k)
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            cout << ans << '\n';
        }
        else
        {
            int fpos=gety(y,x);
            fpos--;
            if (fpos >= 1)
            {
                a[x][fpos]=y;
            }
        }
    }
    return 0;
}