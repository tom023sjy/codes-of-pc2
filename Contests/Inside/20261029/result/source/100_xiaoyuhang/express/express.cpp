#include<bits/stdc++.h>
#define INF 1000000000000000000
#define ll long long
using namespace std;
const int N=1e6+5;
struct seg{
    ll q[N<<2];
    void build(int l,int r,int id){
        q[id]=INF;
        if(l==r) return;
        int mid=l+r>>1;
        build(l,mid,id<<1);
        build(mid+1,r,id<<1|1);
    }
    void add(int l,int r,int id,int to,ll v){
        if(l==r){
            q[id]=min(q[id],v);
            return;
        }
        int mid=l+r>>1;
        if(to<=mid) add(l,mid,id<<1,to,v);
        else add(mid+1,r,id<<1|1,to,v);
        q[id]=min(q[id],v);
    }
    ll query(int L,int R,int l,int r,int id){
        if(L>R) return INF;
        if(L<=l&&r<=R) return q[id];
        int mid=l+r>>1;ll res=INF;
        if(L<=mid) res=min(res,query(L,R,l,mid,id<<1));
        if(R>mid) res=min(res,query(L,R,mid+1,r,id<<1|1));
        return res;
    }
}t1,t2;
int n;
ll a[N],s[N],c[N];
ll b[N],f[N];
int m; 
int main(){
    freopen("express.in","r",stdin);
    freopen("express.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[++m]=a[i];
        c[i]=a[i];
    }
    for(int i=1;i<=n;i++) s[i]=s[i-1]+abs(a[i]-a[i-1]);
    b[++m]=0;
    sort(b+1,b+m+1);
    m=unique(b+1,b+m+1)-b-1;
    for(int i=0;i<=n;i++) a[i]=lower_bound(b+1,b+m+1,a[i])-b;
    t1.build(1,m,1);
    t2.build(1,m,1);
    f[1]=s[1];
    t1.add(1,m,1,a[0],f[1]-s[1]);
    t2.add(1,m,1,a[0],f[1]-s[1]);
    for(int i=2;i<=n;i++){
        f[i]=min(t1.query(1,a[i],1,m,1)+s[i-1]+c[i],t2.query(a[i],m,1,m,1)+s[i-1]-c[i]);
        t1.add(1,m,1,a[i-1],f[i]-s[i]-c[i-1]);
        t2.add(1,m,1,a[i-1],f[i]-s[i]+c[i-1]);
    }
    ll ans=INF;
    for(int i=1;i<=n;i++){
        // cerr<<f[i]<<" ";
        ans=min(ans,f[i]+s[n]-s[i]);
        // if(i==3){
        //     cerr<<s[n]-s[i]<<"\n";
        // }
    }
    cout<<ans;
    return 0;
}