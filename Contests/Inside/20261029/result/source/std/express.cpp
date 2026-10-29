#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define inf 1e15
#define LL long long
#define endl '\n'
using namespace std;
long long read(){
  long long q=0,w=1;
  char ch=getchar();
  while(ch>'9' || ch<'0'){if(ch=='-')w=-1;ch=getchar();}
  while(ch>='0'&&ch<='9'){q=q*10+(ch-'0');ch=getchar();}
  return q*w;
}
void write(LL x){
  if(x<0){putchar('-');x=(-x);}
  if(x>9)write(x/10);
  putchar('0'+x%10);
}
void writeln(LL x){write(x);puts("");}
void writecs(LL x){write(x);putchar(' ');}
LL myabs(LL x){return (x<0?(-x):x);}
namespace H{
  const long long N = 1e6+95;
  long long h[N],top;
  void ins(LL x){h[++top]=x;}
  bool cmp(LL x,LL y){return x<y;}
  void init(){
    sort(h+1,h+top+1,cmp);
    LL len=unique(h+1,h+top+1)-h-1;
    top=len;return ;
  }
  LL find(LL x){return (lower_bound(h+1,h+top+1,x)-h);}
  LL ask(LL x){return h[x];}
}
const long long N = 1e6+95;
long long n,a[N],rk[N],lim,s[N],dp[N],ans;
struct SGT{
  struct Node{LL l,r,d,t;}s[N<<2];
  void Build(LL p,LL l=1,LL r=lim){
    s[p].l=l;s[p].r=r;
    s[p].d=s[p].t=inf;
    if(l==r)return ;
    LL mid=(l+r)>>1;
    Build(p*2,l,mid);
    Build(p*2+1,mid+1,r);
    return ;
  }
  void Pushup(LL p){s[p].d=min(s[p].t,min(s[p*2].d,s[p*2+1].d));}
  void Change(LL p,LL x){s[p].d=min(s[p].d,x);s[p].t=min(s[p].t,x);return ;}
  void Update(LL p,LL l,LL r,LL x){
    if(l<=s[p].l&&s[p].r<=r){Change(p,x);return ;}
    if(r<s[p].l || s[p].r<l)return ;
    LL mid=(s[p].l+s[p].r)>>1;
    if(l<=mid)Update(p*2,l,r,x);
    if(mid<r)Update(p*2+1,l,r,x);
    Pushup(p);return ;
  }
  LL Query(LL p,LL l,LL r){
    if(l<=s[p].l&&s[p].r<=r)return s[p].d;
    if(r<s[p].l || s[p].r<l)return inf;
    LL mid=(s[p].l+s[p].r)>>1,res=s[p].t;
    if(l<=mid)res=min(res,Query(p*2,l,r));
    if(mid<r)res=min(res,Query(p*2+1,l,r));
    return res;
  }
}T1,T2;
int main(){
	freopen("express.in","r",stdin);
	freopen("express.out","w",stdout);
  n=read();
  for(LL i=1;i<=n;i++)a[i]=read();
  for(LL i=1;i<=n;i++)H::ins(a[i]);
  H::init();lim=H::top;
  for(LL i=1;i<=n;i++)rk[i]=H::find(a[i]);
  for(LL i=1;i<=n;i++)s[i]=s[i-1]+myabs(a[i]-a[i-1]);
  T1.Build(1);T2.Build(1);
  for(LL i=1;i<=n;i++)dp[i]=inf;
  ans=s[n];dp[1]=a[1];
  for(LL i=1;i<=n;i++){
    LL v1=T1.Query(1,rk[i],lim);
    LL v2=T2.Query(1,1,rk[i]);
    dp[i]=min(dp[i],v1+s[i-1]-a[i]);
    dp[i]=min(dp[i],v2+s[i-1]+a[i]);
    T1.Update(1,1,rk[i-1],dp[i]-s[i]+a[i-1]);
    T2.Update(1,rk[i-1],lim,dp[i]-s[i]-a[i-1]);
    ans=min(ans,dp[i]+(s[n]-s[i]));
  }
  writeln(ans);
  return 0;
}

