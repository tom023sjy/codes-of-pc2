#include<bits/stdc++.h>
using namespace std;
#define homo_number 114514
#define mod 998244353
//#define mod 1000000007
#define int long long
int n,a[1000005],b[1000005];
int inv[1000005];
struct node
{
    int l,r,add,dat1,dat2,dat0;
    //dat1 -j dat2 +j
};
node t[4000005];
void pushdown(int p)
{
    if(t[p].add)
    {
        t[p*2].dat0+=t[p].add;
        t[p*2+1].dat0+=t[p].add;
        t[p*2].dat1+=t[p].add;
        t[p*2+1].dat1+=t[p].add;
        t[p*2].dat2+=t[p].add;
        t[p*2+1].dat2+=t[p].add;
        t[p*2].add+=t[p].add;
        t[p*2+1].add+=t[p].add;
        t[p].add=0;
    }
    return;
}
void pushup(int p)
{
    t[p].dat0=min(t[p*2].dat0,t[p*2+1].dat0);
    t[p].dat1=min(t[p*2].dat1,t[p*2+1].dat1);
    t[p].dat2=min(t[p*2].dat2,t[p*2+1].dat2);
    return;
}
void build(int p,int l,int r)
{
    t[p].l=l;
    t[p].r=r;
    if(l==r)
    {
        if(l==1) t[p].dat0=t[p].dat1=t[p].dat2=0;
        else t[p].dat0=t[p].dat1=t[p].dat2=1e18;
        return;
    }
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    pushup(p);
    return;
}
void update1(int p,int l,int r,int d)//all +d
{
    if(t[p].l>=l&&t[p].r<=r)
    {
        t[p].add+=d;
        t[p].dat0+=d;
        t[p].dat1+=d;
        t[p].dat2+=d;
        return;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2;
    if(l<=mid) update1(p*2,l,r,d);
    if(r>mid) update1(p*2+1,l,r,d);
    pushup(p);
    return; 
}
void update2(int p,int l,int r,int d)//f[l] = d
{
    if(t[p].l>=l&&t[p].r<=r)
    {
        t[p].dat0=d;
        t[p].dat1=d-inv[l];
        t[p].dat2=d+inv[l];
        return;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2;
    if(l<=mid) update2(p*2,l,r,d);
    if(r>mid) update2(p*2+1,l,r,d);
    pushup(p);
    return; 
}
int querya(int p,int l,int r)
{
    if(t[p].l>=l&&t[p].r<=r)
    {
        return t[p].dat0;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2,res=1e18;
    if(l<=mid) res=min(res,querya(p*2,l,r));
    if(r>mid) res=min(res,querya(p*2+1,l,r));
    return res;
}
int queryl(int p,int l,int r)
{
    if(t[p].l>=l&&t[p].r<=r)
    {
        return t[p].dat1;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2,res=1e18;
    if(l<=mid) res=min(res,queryl(p*2,l,r));
    if(r>mid) res=min(res,queryl(p*2+1,l,r));
    return res;
}
int queryr(int p,int l,int r)
{
    if(t[p].l>=l&&t[p].r<=r)
    {
        return t[p].dat2;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2,res=1e18;
    if(l<=mid) res=min(res,queryr(p*2,l,r));
    if(r>mid) res=min(res,queryr(p*2+1,l,r));
    return res;
}
signed main()
{
    freopen("express.in","r",stdin);
    freopen("express.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 0; i <= n; i++) b[i+1]=a[i];
    sort(b+1,b+n+2);
    int m=unique(b+1,b+n+2)-b-1;
    for(int i = 1; i <= m; i++) inv[i]=b[i];
    for(int i = 0; i <= n; i++) a[i]=lower_bound(b+1,b+m+1,a[i])-b;
    int ncnt=0;
    build(1,1,m);
    for(int i = 1; i <= n; i++)
    {
        int nl=queryl(1,1,a[i])+inv[a[i]],nr=queryr(1,a[i],m)-inv[a[i]];
        // cout<<i<<' '<<nl<<' '<<nr<<endl;
        update1(1,1,m,abs(inv[a[i]]-inv[a[i-1]]));
        update2(1,a[i-1],a[i-1],min(nl,nr));
    }
    cout<<querya(1,1,m);
    return 0;
}