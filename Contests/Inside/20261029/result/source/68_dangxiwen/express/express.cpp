#include<bits/stdc++.h>
using namespace std;
const int mx=1e6+100;
int k[mx];
int n;
unordered_map<int,int> X;
int b[mx];
int fread()
{
    int x=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*w;
}
void fwrite(int x)
{
    if(x>=10) fwrite(x/10);
    putchar(x%10+'0');
    return ;
}
struct tree
{
    int l,r,maxn,pos;
}t[4*mx];
void pushup(int p)
{
    t[p].maxn=max(t[p<<1].maxn,t[p<<1|1].maxn);
    if(t[p].maxn==t[p<<1|1].maxn) t[p].pos=t[p<<1|1].pos;
    else t[p].pos=t[p<<1].pos;
}
void build(int p,int l,int r)
{
    t[p].l=l,t[p].r=r;
    if(l==r)
    {
        t[p].pos=0;
        t[p].maxn=0;
        return ;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid),build(p<<1|1,mid+1,r);
    pushup(p);
}
int dp[mx];
int vis[mx];
int lst[mx];
int getmax(int p,int l,int r,int &pos)
{
    if(t[p].l>=l&&t[p].r<=r)
    {
        pos=t[p].pos;
        return t[p].maxn;
    }
    int mid=(t[p].l+t[p].r)>>1;
    int ans=0;
    if(l<=mid) ans=getmax(p<<1,l,r,pos);
    int pos1=0;
    if(r>mid)
    {
        int ans1=getmax(p<<1|1,l,r,pos1);
        if(ans<=ans1) ans=ans1,pos=pos1;
    }
    return ans;
}
void change(int p,int pos,int x,int id)
{
    if(t[p].l==t[p].r)
    {
        t[p].maxn=x;
        t[p].pos=id;
        return ;
    }
    int mid=t[p].l+t[p].r>>1;
    if(pos<=mid) change(p<<1,pos,x,id);
    else change(p<<1|1,pos,x,id);
    pushup(p);
    return ;
}
vector<int> g1,g2;
long long f[1100][1100];
int main()
{
    freopen("express.in","r",stdin);
    freopen("express.out","w",stdout);
    n=fread();
    for(int i=1;i<=n;i++) k[i]=fread(),b[i]=k[i];
    if(n<=1000)
    {
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++) f[i][j]=2e18;
    }
    f[1][0]=k[1];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            f[i+1][j]=min(f[i+1][j],f[i][j]+abs(k[i+1]-k[i]));
            f[i+1][i]=min(f[i+1][i],f[i][j]+abs(k[i+1]-k[j]));
        }
    }
    long long ans1=2e18;
    for(int i=0;i<=n-1;i++ ) ans1=min(ans1,f[n][i]);
    cout<<ans1;
    return 0;
    }
    if(n>1000)
    {
    sort(b+1,b+n+1);
    int cnt=unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=cnt;i++) X[b[i]]=i;
    build(1,1,cnt);
    for(int i=1;i<=n;i++)
    {
        int fr=0;
        dp[i]=getmax(1,1,X[k[i]],fr)+1;
        lst[i]=fr;
        change(1,X[k[i]],dp[i],i);
    }
    int wz=0,maxn=0;
    for(int i=1;i<=n;i++)
    {
        if(dp[i]>=maxn) maxn=dp[i],wz=i;
    }
    while(wz!=0)
    {
        vis[wz]=1;
        g1.push_back(wz);
        wz=lst[wz];
    }
    build(1,1,cnt);
    for(int i=1;i<=n;i++)
    {
        if(vis[i])
        {
            dp[i]=0;
            continue;
        }
        int fr=0;
        dp[i]=getmax(1,1,X[k[i]],fr)+1;
        lst[i]=fr;
        change(1,X[k[i]],dp[i],i);
    }
    wz=0,maxn=0;
    for(int i=1;i<=n;i++)
    {
        if(dp[i]>=maxn) maxn=dp[i],wz=i;
    }
    while(wz!=0)
    {
        vis[wz]=1;
        g2.push_back(wz);
        wz=lst[wz];
    }
    reverse(g1.begin(),g1.end());
    reverse(g2.begin(),g2.end());
    long long ans=0;
    ans+=k[g1[g1.size()-1]]+k[g2[g2.size()-1]];
    int pp1=0,pp2=0;
    int now1=k[g1[0]],now2=k[g2[0]];
    int len1=g1.size(),len2=g2.size();
    int mw=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==1) continue;
        while(pp1+1<len1&&g1[pp1+1]<i) pp1++,now1=k[g1[pp1]];
        while(pp2+1<len2&&g2[pp2+1]<i) pp2++,now2=k[g2[pp2]];
        if(pp1+1==len1&&pp2==len2)
        {
            mw=i;
            break;
        }
        int pos=k[i];
        if(now1<=pos&&now2<=pos)
        {
            if(now1<=now2) now2=pos;
            else now1=pos;
            continue;
        }
        if(now1<=pos) {now1=pos;continue;}
        if(now2<=pos) {now2=pos;continue;}
        if(now1<=now2)
        {
            ans+=2*(now1-pos);
            now1=pos;
        }
        else ans+=2*(now2-pos),now2=pos;
    }
    if(mw==0)
    {
        cout<<ans;
        return 0;
    }
    for(int i=mw;i<=n;i++)
    {
        ans+=abs(now2-k[i]);
        now2=k[i];
    }
    cout<<ans;
    }
    return 0;
}