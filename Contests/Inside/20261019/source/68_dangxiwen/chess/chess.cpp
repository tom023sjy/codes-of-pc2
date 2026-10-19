#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mx=5100;
int n,H,W;
int vis[mx][mx];
int fread()
{
    int x=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*w;
}
struct tree
{
    int l,r,num,tag;
}t[mx][4*mx];
struct chess
{
    int x,y,xx,yy,c;
}che[110000];
void build(int i,int p,int l,int r)
{
    t[i][p].l=l,t[i][p].r=r;
    if(l==r) return ;
    int mid=(l+r)/2;
    build(i,p<<1,l,mid),build(i,p<<1|1,mid+1,r);
}
void pushup(int i,int p)
{
    t[i][p].num=(t[i][p<<1].num+t[i][p<<1|1].num);
}
void pushdown(int i,int p)
{
    if(t[i][p].tag)
    {
        t[i][p<<1].num+=(t[i][p<<1].r-t[i][p<<1].l+1)*t[i][p].tag;
        t[i][p<<1|1].num+=(t[i][p<<1|1].r-t[i][p<<1|1].l+1)*t[i][p].tag;
        t[i][p<<1].tag+=t[i][p].tag;
        t[i][p<<1|1].tag+=t[i][p].tag;
        t[i][p].tag=0;
    }
}
void add(int i,int p,int l,int r,int x)
{
    if(t[i][p].l>=l&&t[i][p].r<=r)
    {
        t[i][p].num+=(t[i][p].r-t[i][p].l+1)*x;
        t[i][p].tag+=x;
        return ;
    }
    pushdown(i,p);
    int mid=(t[i][p].l+t[i][p].r)/2;
    if(l<=mid) add(i,p<<1,l,r,x);
    if(r>mid) add(i,p<<1|1,l,r,x);
    pushup(i,p);
}
int ask(int i,int p,int pos)
{
    if(t[i][p].l==t[i][p].r) return t[i][p].num;
    pushdown(i,p);
    int mid=(t[i][p].l+t[i][p].r)/2;
    if(pos<=mid) return ask(i,p<<1,pos);
    else return ask(i,p<<1|1,pos);
}
int main()
{
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    fread();
    n=fread(),H=fread(),W=fread();
    for(int i=1;i<=W;i++)
    {
        build(i,1,1,H);
    }
    for(int i=1;i<=n;i++)
    {
        che[i].x=fread(),che[i].y=fread(),che[i].xx=fread(),che[i].yy=fread();
        che[i].c=fread();
        int x=che[i].x,xx=che[i].xx,y=che[i].y,yy=che[i].yy;
        add(y,1,x,xx,1);
        if(yy+1<=W) add(yy+1,1,x,xx,-1);
    }
    int fl=0;
    for(int i=1;i<=W;i++)
    {
        for(int j=1;j<=H;j++)
        {
            vis[j][i]=vis[j][i-1]+ask(i,1,j);
            if(vis[j][i]==0)
            {
                // cout<<j<<' '<<i<<endl;
                fl=1;
                break;
            }
        }
    }
    if(fl)
    {
        int sum=0;
        for(int i=1;i<=n;i++) sum+=che[i].c;
        ll ans=(ll)sum*(1ll*sum-1)/2;
        cout<<ans;
        return 0;
    }
    ll ans1=0,ans2=0,ans3=0,ans4=0;
    int sum=0;
    for(int i=1;i<=n;i++) sum+=che[i].c;
    int ca1=0;
    for(int i=1;i<=n;i++)
    {
        if(che[i].x>1||che[i].y>1) ca1+=che[i].c;
    }
    ans1=(ll)(ca1-1)*(ll)ca1/2+(ll)(sum-ca1)*(ll)(sum-ca1-1)/2;
    ca1=0;
    for(int i=1;i<=n;i++)
    {
        if(che[i].xx<H||che[i].yy<W) ca1+=che[i].c;
    }
    ans2=(ll)(ca1-1)*(ll)ca1/2+(ll)(sum-ca1)*(ll)(sum-ca1-1)/2;
    ca1=0;
    for(int i=1;i<=n;i++)
    {
        if(che[i].x>1||che[i].yy<W) ca1+=che[i].c;
    }
    ans3=(ll)(ca1-1)*(ll)ca1/2+(ll)(sum-ca1)*(ll)(sum-ca1-1)/2;
    ca1=0;
    for(int i=1;i<=n;i++)
    {
        if(che[i].xx<H||che[i].y>1) ca1+=che[i].c;
    }
    ans4=(ll)(ca1-1)*(ll)ca1/2+(ll)(sum-ca1)*(ll)(sum-ca1-1)/2;
    ca1=0;
    ll tans=max(ans1,max(ans2,ans3));
    tans=max(tans,ans4);
    cout<<tans;
    return 0;
}