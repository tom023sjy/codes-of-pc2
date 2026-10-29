#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using u64=unsigned long long;
using db=double;
using pii=pair<int,int>;
using vi=vector<int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch-'0'),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back

const int N=1e6+10;
const i64 INFl=0x3f3f3f3f3f3f3f3f;

struct SGT{
    #define lson (now<<1)
    #define rson (now<<1|1)
    #define mid ((l+r)>>1)
private: 
    void apply(int now,i64 v) {mi[now]+=v,ad[now]+=v;}
    void pushup(int now) {mi[now]=min(mi[lson],mi[rson]);}
    void pushdown(int now){
        if(ad[now]) apply(lson,ad[now]),apply(rson,ad[now]),ad[now]=0;
    }
    i64 mi[N*4],ad[N*4];

public:
    void ckmin(int now,int l,int r,int x,i64 n_v){
        if(l==r) {mi[now]=n_v;return;}
        pushdown(now);
        if(x<=mid) ckmin(lson,l,mid,x,n_v);
        else ckmin(rson,mid+1,r,x,n_v);
        pushup(now);
    }
    void add(int now,int l,int r,int x,int y,i64 v){
        if(x<=l&&r<=y) {apply(now,v);return;}
        pushdown(now);
        if(x<=mid) add(lson,l,mid,x,y,v);
        if(y>mid) add(rson,mid+1,r,x,y,v);
        pushup(now);
    }
    i64 query(int now,int l,int r,int x,int y){
        if(x<=l&&r<=y) return mi[now];
        pushdown(now);
        i64 ret=INFl;
        if(x<=mid) ret=min(ret,query(lson,l,mid,x,y));
        if(y>mid) ret=min(ret,query(rson,mid+1,r,x,y));
        return ret;
    }
    #undef lson
    #undef rson
    #undef mid
}t1,t2;
// t1: f(i,j)+p_j t2: f(i,j)-p_j

int n,p[N];

int raw[N],r_tot;
void discrete(){
    for(int i=0;i<=n;i++) raw[++r_tot]=p[i];
    sort(raw+1,raw+r_tot+1);r_tot=unique(raw+1,raw+r_tot+1)-raw-1;
    for(int i=0;i<=n;i++) p[i]=lower_bound(raw+1,raw+r_tot+1,p[i])-raw;
}

int main(){
    freopen("express.in","r",stdin);
    freopen("express.out","w",stdout);
    n=rdi();
    for(int i=1;i<=n;i++) p[i]=rdi();
    discrete();

    t1.add(1,1,r_tot,1,r_tot,INFl),t2.add(1,1,r_tot,1,r_tot,INFl);
    t1.ckmin(1,1,r_tot,p[0],raw[p[0]]),t2.ckmin(1,1,r_tot,p[0],-raw[p[0]]);
    for(int i=1;i<=n;i++){
        i64 mi=min(t1.query(1,1,r_tot,p[i],r_tot)-raw[p[i]],t2.query(1,1,r_tot,1,p[i])+raw[p[i]]);
        i64 dis=abs(raw[p[i]]-raw[p[i-1]]);
        t1.add(1,1,r_tot,1,r_tot,dis),t2.add(1,1,r_tot,1,r_tot,dis);
        t1.ckmin(1,1,r_tot,p[i-1],mi+raw[p[i-1]]),t2.ckmin(1,1,r_tot,p[i-1],mi-raw[p[i-1]]);
    }
    i64 ans=INFl;
    for(int i=1;i<=r_tot;i++)
        ans=min(ans,t1.query(1,1,r_tot,i,i)-raw[i]);
    cout<<ans<<'\n';
    return 0;
}