#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e6+5,INF=1e17;
int n,m,x[N],a[N],b[N],dp[N],lst[N],ans=INF,tag=0;

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

struct Seg
{
    int t[N*4];
    inline void push_up (int p) {t[p]=min(t[p<<1],t[p<<1|1]);}
    inline void build (int pl,int pr,int p,int op)
    {
        if (pl==pr) {if (pl==0) t[p]=op*b[pl];else t[p]=INF;return ;}
        int mid=pl+pr>>1;
        build(pl,mid,p<<1,op);
        build(mid+1,pr,p<<1|1,op);
        push_up(p);
    }
    inline void update (int pl,int pr,int p,int k,int d)
    {
        if (pl==pr) {t[p]=min(t[p]+tag,d)-tag;return ;}
        int mid=pl+pr>>1;
        if (mid>=k) update(pl,mid,p<<1,k,d);
        else update(mid+1,pr,p<<1|1,k,d);
        push_up(p);
        //printf("[%d %d %d]\n",pl,pr,t[p]);
    }
    inline int query (int pl,int pr,int p,int l,int r)
    {
        if (l<=pl&&pr<=r) return t[p];
        int mid=pl+pr>>1,res=INF;
        if (mid>=l) res=query(pl,mid,p<<1,l,r);
        if (mid+1<=r) res=min(res,query(mid+1,pr,p<<1|1,l,r));
        return res;
    }
    inline int query_ed (int pl,int pr,int p)
    {
        if (pl==pr) return t[p]+tag-b[pl];
        int mid=pl+pr>>1;
        return min(query_ed(pl,mid,p<<1),query_ed(mid+1,pr,p<<1|1));
    }
};
Seg s1,s2;

signed main()
{
   // freopen("ex_express4.in","r",stdin);
    freopen("express.in","r",stdin);
    freopen("express.out","w",stdout);
    n=read();
    for (int i=1;i<=n;i++) x[i]=read(),b[i]=x[i];
    sort(b+1,b+n+1);
    m=unique(b+1,b+n+1)-b-1;
    for (int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+m+1,x[i])-b;
    //for (int i=1;i<=m;i++) dp[i]=INF;
    s1.build(0,m,1,1);
    s2.build(0,m,1,-1);
    for (int i=1;i<=n;i++)
    {
      /*  int mn=INF;
        for (int j=0;j<=a[i];j++) mn=min(mn,dp[j]-b[j]+x[i]);
        for (int j=a[i]+1;j<=m;j++) mn=min(mn,dp[j]+b[j]-x[i]);
        for (int j=0;j<=m;j++) dp[j]+=abs(x[i]-x[i-1]);
        dp[a[i-1]]=min(dp[a[i-1]],mn);*/
        int mn=min(s1.query(0,m,1,a[i],m)+tag-x[i],s2.query(0,m,1,0,a[i])+tag+x[i]);
        tag+=abs(x[i]-x[i-1]);
    //    printf("|||[%d %d %d]\n",i,mn,tag);
        s1.update(0,m,1,a[i-1],mn+x[i-1]);
        s2.update(0,m,1,a[i-1],mn-x[i-1]);
    }
    ans=s1.query_ed(0,m,1);
    cout<<ans;
    return 0;
}
