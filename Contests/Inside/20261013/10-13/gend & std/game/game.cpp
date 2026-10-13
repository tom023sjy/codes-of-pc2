#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,mod=1e9+7;
unsigned down(const unsigned&x){
    if(x>=mod)return x-mod;
    return x;
}
struct Modint{
    unsigned v;
    Modint(unsigned x=0){v=x;}
    Modint operator+(const Modint&x)const{return down(v+x.v);}
    Modint operator-(const Modint&x)const{return down(v+mod-x.v);}
    Modint operator*(const Modint&x)const{return 1ll*v*x.v%mod;}
    Modint operator=(const Modint&x){return v=x.v;}
    void operator+=(const Modint&x){v=down(v+x.v);}
    void operator-=(const Modint&x){v=down(v+mod-x.v);}
    void operator*=(const Modint&x){v=1ll*v*x.v%mod;}
    bool operator==(const Modint&x){return v==x.v;}
    bool operator!=(const Modint&x){return v!=x.v;}
};
typedef Modint mint;
struct Node{
    int ls,rs;
    mint val,tag;
}t[N*25];
#define l(p) t[p].ls
#define r(p) t[p].rs
#define v(p) t[p].val
#define tag(p) t[p].tag
int cnt,rt[N];
int New(){
    cnt++;
    l(cnt)=r(cnt)=0;v(cnt)=0;
    tag(cnt)=1;
    return cnt;
}
void pushup(int p){
    v(p)=v(l(p))+v(r(p));
}
void upd(int p,mint v){
    v(p)=v(p)*v;
    tag(p)=tag(p)*v;
}
void pushdown(int p){
    if(tag(p)!=1){
        if(l(p))upd(l(p),tag(p));
        if(r(p))upd(r(p),tag(p));
        tag(p)=1;
    }
}
void change(int&p,int l,int r,int k){
    p=New();
    if(l==r){
        v(p)=1;
        return;
    }int mid=l+r>>1;
    if(k<=mid)change(l(p),l,mid,k);
    else change(r(p),mid+1,r,k);
    pushup(p);
}
int merge(int x,int y,int l,int r,mint&sumx,mint&sumy){
    if(!x&&!y)return 0;
    if(!y){
        sumx+=v(x);
        upd(x,sumy);
        return x;
    }
    if(!x){
        sumy+=v(y);
        upd(y,sumx);
        return y;
    }
    if(l==r){
        sumx+=v(x);
        v(x)=v(x)*sumy+sumx*v(y);
        sumy+=v(y);
        return x;
    }int mid=l+r>>1;pushdown(x);pushdown(y);
    l(x)=merge(l(x),l(y),l,mid,sumx,sumy);
    r(x)=merge(r(x),r(y),mid+1,r,sumx,sumy);
    pushup(x);
    return x;
}
mint ans;
mint sum[N],tag[N];
void mul(int pos,mint v){
    sum[pos]*=v;
    tag[pos]*=v;
}
void push_down(int pos){
    if(tag[pos]!=1){
        mul(pos+1,tag[pos]);
        tag[pos]=1;
    }
}
int Merge(int&x,int y,int l,int r,mint&sumx,mint&sumy){
    if(!x&&!y)return 0;
    if(!y){
        sumx+=v(x);
        upd(x,sumy);
        return x;
    }
    if(!x)x=New();
    if(l==r){
        push_down(l);
        sum[l]*=sumy;
        sum[l]+=sumx*v(y);
        sumx+=v(x);
        v(x)=v(x)*sumy+sumx*v(y);
        sumy+=v(y);
        return x;
    }int mid=l+r>>1;pushdown(x);pushdown(y);
    l(x)=Merge(l(x),l(y),l,mid,sumx,sumy);
    r(x)=Merge(r(x),r(y),mid+1,r,sumx,sumy);
    pushup(x);
    return x;
}
int d[N],dep[N],n;
int h[N],e[N<<1],ne[N<<1],tot;
void add(int a,int b){
    e[++tot]=b;ne[tot]=h[a];h[a]=tot;
}
void dfs(int x,int fa){
    d[x]=d[fa]+1;dep[x]=d[x];
    for(int i=h[x];i;i=ne[i])if(e[i]!=fa)
        dfs(e[i],x),dep[x]=max(dep[x],dep[e[i]]);
}
void solve(int x,int fa){
    change(rt[x],1,n,d[x]);
    for(int i=h[x];i;i=ne[i])if(e[i]!=fa){
        solve(e[i],x);
        if(x==1){
            mint sumx=0,sumy=1;
            rt[x]=Merge(rt[x],rt[e[i]],1,n,sumx,sumy);
            mul(dep[e[i]]+1,sumy);
        }else{
            mint sumx=0,sumy=1;
            rt[x]=merge(rt[x],rt[e[i]],1,n,sumx,sumy);
        }
    }
//    printf("SOLVE:%d %u\n",x,v(rt[x]).v);
}
int solve(){
    memset(h,0,sizeof(h));tot=0;
    memset(rt,0,sizeof(rt));cnt=0;ans=0;
    scanf("%d",&n);
    for(int i=1,a,b;i<n;i++)scanf("%d%d",&a,&b),add(a,b),add(b,a);
    for(int i=1;i<=n;i++)tag[i].v=1,sum[i].v=0;
    dfs(1,0);solve(1,0);
    for(int i=1;i<=n;i++){
        push_down(i);
        ans+=sum[i];
        //printf("%u ",sum[i].v);
    }//puts("");
    ans=v(rt[1])-ans;
    printf("%u\n",ans.v);
    return 0;
}
int main(){
//	freopen("data.in","r",stdin);
//	freopen("sb.out","w",stdout);
    int t=1;
    while(t--)solve();
    return 0;
}
/*
设dp[x][i]表示以x为根节点,最深深度为i的连通块个数
设g为前缀和
dp[x][i]=g[x][i]*dp[y][i]+dp[x][i]*(g[y][i-1]+1)
设f[i]表示该子树前选连通块深度=i的方案数
w[i]表示已经选了最大子树且其深度为i的方案数
*/