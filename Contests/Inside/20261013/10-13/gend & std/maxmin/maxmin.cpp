#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,inf=1e9;
int n,a[N],b[N];
typedef pair<int,int>pii;
#define fi first
#define se second
vector<pii>ans;
struct Node{
    int a,b;//对a取max,对b取min
    int calc(int x)const{
        return ~b?min(max(a,x),b):a;
    }
    Node operator+(const Node&o)const{
        if(o.b==-1)return o;
        if(b==-1)return{o.calc(a),-1};
        if(b<o.a)return{o.a,-1};
        if(a>o.b)return{o.b,-1};
        return{max(a,o.a),min(b,o.b)};
    }
}C[N];
struct Sgt{
    Node t[N<<2];
    void pushup(int p){
        t[p]=t[p<<1]+t[p<<1|1];
    }
    void change(int p,int l,int r,int k,Node v){
        if(l==r){
            t[p]=v;
            return;
        }int mid=l+r>>1;
        if(k<=mid)change(p<<1,l,mid,k,v);
        else change(p<<1|1,mid+1,r,k,v);
        pushup(p);
    }
    Node query(int p,int l,int r,int l1,int r1){
        if(l1<=l&&r<=r1)return t[p];
        int mid=l+r>>1;
        if(r1<=mid)return query(p<<1,l,mid,l1,r1);
        if(l1>mid)return query(p<<1|1,mid+1,r,l1,r1);
        return query(p<<1,l,mid,l1,r1)+query(p<<1|1,mid+1,r,l1,r1);
    }
}t1;
pii operator+(pii x,pii y){
    return{min(x.fi,y.fi),max(x.se,y.se)};
}
struct Seg{
    pii t[N<<2];Node tag[N<<2];
    void pushup(int p){
        t[p]=t[p<<1]+t[p<<1|1];
    }
    void upd(int p,Node v){
        if(t[p].fi==inf)return;
        tag[p]=tag[p]+v;
        t[p]={v.calc(t[p].fi),v.calc(t[p].se)};
    }
    void pushdown(int p){
        if(tag[p].a!=-inf||tag[p].b!=inf){
            upd(p<<1,tag[p]),upd(p<<1|1,tag[p]);
            tag[p]={-inf,inf};
        }
    }
    void change(int p,int l,int r,int k,pii v){
        if(l==r){
            t[p]=t[p]+v;
            return;
        }int mid=l+r>>1;pushdown(p);
        if(k<=mid)change(p<<1,l,mid,k,v);
        else change(p<<1|1,mid+1,r,k,v);
        pushup(p);
    }
    void change(int p,int l,int r,int l1,int r1,Node v){
        if(l1>r1)return;
        if(l1<=l&&r<=r1)return upd(p,v);
        int mid=l+r>>1;pushdown(p);
        if(l1<=mid)change(p<<1,l,mid,l1,r1,v);
        if(r1>mid)change(p<<1|1,mid+1,r,l1,r1,v);
        pushup(p);
    }
    pii query(int p,int l,int r,int l1,int r1){
        if(l1>r1)return{inf,-inf};
        if(l1<=l&&r<=r1)return t[p];
        int mid=l+r>>1;pushdown(p);
        if(r1<=mid)return query(p<<1,l,mid,l1,r1);
        if(l1>mid)return query(p<<1|1,mid+1,r,l1,r1);
        return query(p<<1,l,mid,l1,r1)+query(p<<1|1,mid+1,r,l1,r1);
    }
    void build(int p,int l,int r){
        t[p]={inf,-inf};tag[p]={-inf,inf};
        if(l==r)return;
        int mid=l+r>>1;
        build(p<<1,l,mid);build(p<<1|1,mid+1,r);
    }
}t2;
int pos[N];
void solve(int*a,int*b){
    for(int i=1;i<=n;i++)pos[a[i]]=i;
    for(int i=1;i<=n;i++)t1.change(1,1,n,i,{-inf,b[i]});
    for(int i=1;i<=n;i++){
        int x=pos[i];
        C[x]=(x<n?t1.query(1,1,n,x+1,n):Node{-inf,inf});
        t1.change(1,1,n,x,{b[x],inf});
    }
    t2.build(1,1,n);t2.change(1,1,n,a[1],{b[1],b[1]});
    for(int i=1;i<=n;i++){
        if(i>1){
            auto it=t2.query(1,1,n,a[i]+1,n);
            if(it.fi!=inf){
                it.fi=min(it.fi,b[i]);it.se=min(it.se,b[i]);
                t2.change(1,1,n,a[i],it);
            }
            it=t2.query(1,1,n,1,a[i]-1);
            if(it.fi!=inf){
                it.fi=max(it.fi,b[i]);it.se=max(it.se,b[i]);
                t2.change(1,1,n,a[i],it);
            }
        }
        t2.change(1,1,n,1,a[i]-1,{-inf,b[i]});t2.change(1,1,n,a[i]+1,n,{b[i],inf});
        auto it=t2.query(1,1,n,a[i],a[i]);
        ans.push_back({a[i],C[i].calc(it.fi)});
        ans.push_back({a[i],C[i].calc(it.se)});
        // cerr<<a[i]<<' '<<C[i].calc(it.fi)<<' '<<C[i].calc(it.se)<<endl;
    }
}
int solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++)scanf("%d",b+i);
    ans.clear();
    solve(a,b);
    for(auto&it:ans)swap(it.fi,it.se);
    solve(b,a);
    static int res[N];
    for(int i=0;i<n;i++)res[i]=0;
    sort(ans.begin(),ans.end());ans.erase(unique(ans.begin(),ans.end()),ans.end());
    for(auto it:ans)res[abs(it.fi-it.se)]++;//,cerr<<it.se<<' '<<it.fi<<endl;
    for(int i=0;i<n;i++)printf("%d%c",res[i]," \n"[i==n-1]);
    return 0;
}
int main(){
    int t=1;
    while(t--)solve();
    return 0;
}