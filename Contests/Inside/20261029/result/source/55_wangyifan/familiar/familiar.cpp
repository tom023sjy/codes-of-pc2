#include <bits/stdc++.h>
using namespace std;

const int N=1005;
int n,m,q,a[N][N],op,x,y,k,l1,r1,mid1,ans,l2,r2,mid2,res,f;
char c;

inline int read ()
{
    x=0,f=1;
    c=getchar();
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

inline int check (int md,int x)
{
    l2=1,r2=m,res=0;
    while (l2<=r2)
    {
        mid2=l2+r2>>1;
       // printf("qwqwqwq(%d %d %d)\n",mid2,a[x][mid2],res);
        if (a[x][mid2]>md) res=m-mid2+1,r2=mid2-1;
        else l2=mid2+1;
    }
    //printf("{%d %d %d}\n",md,x,res);
    return res;
}

inline int minn (int x,int y) {return (x<y)?x:y;}

inline int maxx (int x,int y) {return (x>y)?x:y;}

signed main()
{
  //  freopen("ex_familiar5.in","r",stdin);
    freopen("familiar.in","r",stdin);
    freopen("familiar.out","w",stdout);
    n=read(),m=read(),q=read();
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) a[i][j]=read();
    while (q--)
    {
        op=read();
        if (op==1)
        {
            x=read(),y=read(),k=read();
            l1=maxx(1,m-k+1),r1=m,ans=1e9;
            while (l1<=r1)
            {
                mid1=l1+r1>>1;
             //   printf("x:(%d %d)\n",mid1,ans);
                if (check(a[x][mid1],y)+m-mid1+1<=k) ans=minn(ans,a[x][mid1]),r1=mid1-1;
                else l1=mid1+1;
            }
            l1=maxx(1,m-k+1),r1=m;
            while (l1<=r1)
            {
                mid1=l1+r1>>1;
                //printf("y:(%d %d %d)\n",mid1,ans,check(a[y][mid1],x));
                if (check(a[y][mid1],x)+m-mid1+1<=k) ans=minn(ans,a[y][mid1]),r1=mid1-1;
                else l1=mid1+1;
            }
            cout<<ans<<'\n';
        }
        else
        {
            x=read(),y=read();
            l1=1,r1=m,res=m+1;
            while (l1<=r1)
            {
                mid1=l1+r1>>1;
                if (a[x][mid1]<=y) res=mid1,l1=mid1+1;
                else r1=mid1-1;
            }
            a[x][res]=y;
        }
    }
    return 0;
}
