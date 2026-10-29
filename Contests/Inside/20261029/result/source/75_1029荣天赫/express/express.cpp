#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
ll k[N];
// ll f[N][N];
struct nd{
    ll v,id;
}tmp[N];
int rk[N];
bool cmp(nd a,nd b){
    return a.v<b.v;
}
int n;
struct TT{
struct node{
    int l,r;
    ll val,tag;
}t[N<<2];
void build(int p,int l,int r){
    t[p].l=l,t[p].r=r;
    t[p].val=1e15,t[p].tag=0;
    if(l==r) return ;
    int mid=l+r>>1;
    build(p<<1,l,mid),build(p<<1|1,mid+1,r);
    t[p].val=min(t[p<<1].val,t[p<<1|1].val);
    return ;
}
void pushdown(int p){
    if(t[p].tag==0) return ;
    t[p<<1].val+=t[p].tag,t[p<<1|1].val+=t[p].tag;
    t[p<<1].tag+=t[p].tag,t[p<<1|1].tag+=t[p].tag;
    t[p].tag=0;
    return ;
}
void update(int p,int l,int r,ll d){
    if(l>r) return ;
    if(t[p].l>=l&&t[p].r<=r){
        t[p].val+=d;
        t[p].tag+=d;
        return ;
    }
    pushdown(p);
    int mid=t[p].l+t[p].r>>1;
    if(l<=mid) update(p<<1,l,r,d);
    if(r>mid) update(p<<1|1,l,r,d);
    t[p].val=min(t[p<<1].val,t[p<<1|1].val);
    return ;
}
void modify(int p,int x,ll v){
    if(t[p].l==t[p].r){
        t[p].val=v;
        return ;
    }
    pushdown(p);
    int mid=t[p].l+t[p].r>>1;
    if(x<=mid) modify(p<<1,x,v);
    else modify(p<<1|1,x,v);
    t[p].val=min(t[p<<1].val,t[p<<1|1].val);
    return ;
}
ll query(int p,int l,int r){
    if(l>r) return 1e15;
    if(t[p].l>=l&&t[p].r<=r) return t[p].val;
    pushdown(p);
    int mid=t[p].l+t[p].r>>1;
    ll res=1e15;
    if(l<=mid) res=min(res,query(p<<1,l,r));
    if(r>mid) res=min(res,query(p<<1|1,l,r));
    return res;
}
}t1,t2;
int main(){
    freopen("express.in","r",stdin);
    freopen("express.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>k[i];
    for(int i=1;i<=n;i++) tmp[i].v=k[i],tmp[i].id=i;
    sort(tmp+1,tmp+n+1,cmp);
    for(int i=1;i<=n;i++) rk[tmp[i].id]=i;
    t1.build(1,0,n);
    t1.modify(1,0,0);
    t2.build(1,0,n);
    t2.modify(1,0,0);
    for(int i=0;i<n;i++){
        ll res1=t1.query(1,0,rk[i+1]-1);
        ll res2=t2.query(1,rk[i+1]+1,n);
        t1.update(1,0,n,abs(k[i+1]-k[i]));
        t2.update(1,0,n,abs(k[i+1]-k[i]));
        ll cur=min(res1+k[i+1],res2-k[i+1]);
        t1.modify(1,rk[i],cur-k[i]);
        t2.modify(1,rk[i],cur+k[i]);
    }
    ll ans=1e16;
    for(int i=0;i<=n;i++) ans=min(ans,t1.query(1,rk[i],rk[i])+k[i]);
    cout<<ans<<endl;
    return 0;
}