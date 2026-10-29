#include<bits/stdc++.h>
using namespace std;
int n,a[1000010],b[1000010];
struct seg
{
    struct tree
    {
        int l,r;
        long long add,chk;
        long long minn;
    }s[4000005];
    void pushup(int p)
    {
        s[p].minn=min(s[p<<1].minn,s[p<<1|1].minn);
        return;
    }
    void addtag(int p,long long x)
    {
        s[p].add+=x,s[p].chk+=x;
        s[p].minn+=x;
        return;
    }
    void mintag(int p,long long x)
    {
        s[p].chk=min(s[p].chk,x);
        s[p].minn=min(s[p].minn,x);
        return;
    }
    void pushdown(int p)
    {
        if(s[p].add!=0)
        {
            addtag(p<<1,s[p].add);
            addtag(p<<1|1,s[p].add);
            s[p].add=0;
        }
        if(s[p].chk!=1e18)
        {
            mintag(p<<1,s[p].chk);
            mintag(p<<1|1,s[p].chk);
            s[p].chk=1e18;
        }
        return;
    }
    void build(int p,int l,int r)
    {
        s[p].l=l,s[p].r=r,s[p].add=0,s[p].chk=1e18;
        if(l==r)
        {
            s[p].minn=1e18;
            return;
        }
        int mid=(l+r)/2;
        build(p<<1,l,mid);
        build(p<<1|1,mid+1,r);
        pushup(p);
        return;
    }
    void updateadd(int p,int l,int r,long long x)
    {
        if(s[p].l>=l&&s[p].r<=r)
        {
            addtag(p,x);
            return;
        }
        pushdown(p);
        int mid=(s[p].l+s[p].r)/2;
        if(mid>=l) updateadd(p<<1,l,r,x);
        if(mid<r) updateadd(p<<1|1,l,r,x);
        pushup(p);
        return;
    }
    void updatemin(int p,int l,int r,long long x)
    {
        if(s[p].l>=l&&s[p].r<=r)
        {
            mintag(p,x);
            return;
        }
        pushdown(p);
        int mid=(s[p].l+s[p].r)/2;
        if(mid>=l) updatemin(p<<1,l,r,x);
        if(mid<r) updatemin(p<<1|1,l,r,x);
        pushup(p);
        return;
    }
    long long querymin(int p,int l,int r)
    {
        if(s[p].l>=l&&s[p].r<=r) return s[p].minn;
        pushdown(p);
        int mid=(s[p].l+s[p].r)/2;
        long long res=1e18;
        if(mid>=l) res=min(res,querymin(p<<1,l,r));
        if(mid<r) res=min(res,querymin(p<<1|1,l,r));
        return res;
    }
}S[2],T[2][2];
int main()
{
    freopen("express.in","r",stdin);
    freopen("express.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+n+1,a[i])-b;
    S[0].build(1,0,n),S[1].build(1,0,n);
    T[0][0].build(1,0,n),T[0][1].build(1,0,n);
    T[1][0].build(1,0,n),T[1][1].build(1,0,n);
    S[0].updatemin(1,0,0,b[a[1]]),S[1].updatemin(1,0,0,b[a[1]]);
    T[0][0].updatemin(1,0,0,b[a[1]]),T[0][1].updatemin(1,0,n,b[a[1]]);
    T[1][0].updatemin(1,0,0,b[a[1]]),T[1][1].updatemin(1,0,n,b[a[1]]);
    for(int i=2;i<=n;i++)
    {
        long long f0=1e18,f1=1e18;
        f0=min(f0,T[1][0].querymin(1,a[i],a[i])-b[a[i]]);
        f0=min(f0,T[1][1].querymin(1,a[i],a[i])+b[a[i]]);
        f1=min(f0,T[0][0].querymin(1,a[i],a[i])-b[a[i]]);
        f1=min(f0,T[0][1].querymin(1,a[i],a[i])+b[a[i]]);
        S[0].updateadd(1,0,i-2,abs(b[a[i]]-b[a[i-1]])),S[1].updateadd(1,0,i-2,abs(b[a[i]]-b[a[i-1]]));
        S[0].updatemin(1,i-1,i-1,f0),S[1].updatemin(1,i-1,i-1,f1);
        T[0][0].updateadd(1,0,n,abs(b[a[i]]-b[a[i-1]])),T[0][1].updateadd(1,0,n,abs(b[a[i]]-b[a[i-1]]));
        T[1][0].updateadd(1,0,n,abs(b[a[i]]-b[a[i-1]])),T[1][1].updateadd(1,0,n,abs(b[a[i]]-b[a[i-1]]));
        T[0][0].updatemin(1,0,a[i-1],f0+b[a[i-1]]),T[0][1].updatemin(1,a[i-1],n,f0-b[a[i-1]]);
        T[1][0].updatemin(1,0,a[i-1],f1+b[a[i-1]]),T[1][1].updatemin(1,a[i-1],n,f1-b[a[i-1]]);
    }
    cout<<min(S[0].s[1].minn,S[1].s[1].minn);
    // memset(f,0x3f3f3f3f,sizeof(f));
    // f[1][0][0]=f[1][0][1]=a[1];
    // for(int i=2;i<=n;i++)
    // {
    //     for(int j=0;j<=i-2;j++) 
    //     {
    //         f[i][i-1][0]=min(f[i][i-1][0],f[i-1][j][1]+abs(a[i]-a[j]));
    //         f[i][i-1][1]=min(f[i][i-1][1],f[i-1][j][0]+abs(a[i]-a[j]));
    //         if(i==n) ans=min(ans,min(f[i][i-1][0],f[i][i-1][1]));
    //     }
    //     for(int j=0;j<=i-2;j++)
    //     {
    //         f[i][j][0]=f[i-1][j][0]+abs(a[i]-a[i-1]);
    //         f[i][j][1]=f[i-1][j][1]+abs(a[i]-a[i-1]);
    //         if(i==n) ans=min(ans,min(f[i][j][0],f[i][j][1]));
    //     }
    // }
    //cout<<ans;
}