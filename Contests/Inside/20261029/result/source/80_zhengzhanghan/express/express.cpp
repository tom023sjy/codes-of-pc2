#include<bits/stdc++.h>
using namespace std;
int n,a[1000010],Vcnt;
long long nw[1000010];
struct Node{
    long long val;
    int id;
}p[1000010];
long long INF=100000000000000000;
struct Seg{
    long long tr[4000010],tag[4000010];
    void pushdown(int u){
        if(tag[u]){
            tr[u<<1]+=tag[u];
            tr[u<<1|1]+=tag[u];
            tag[u<<1]+=tag[u];
            tag[u<<1|1]+=tag[u];
            tag[u]=0;
        }
    }
    void pushup(int u){
        tr[u]=min(tr[u<<1],tr[u<<1|1]);
    }
    void build(int u,int l,int r){
        if(l==r){
            tr[u]=INF;
            tag[u]=0;
            return;
        }
        int mid=(l+r)>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
    void update(int u,int l,int r,int ql,int qr,long long qk){
        if(ql<=l&&r<=qr){
            tag[u]+=qk;
            tr[u]+=qk;
            return;
        }
        pushdown(u);
        int mid=(l+r)>>1;
        if(ql<=mid){
            update(u<<1,l,mid,ql,qr,qk);
        }
        if(mid+1<=qr){
            update(u<<1|1,mid+1,r,ql,qr,qk);
        }
        pushup(u);
    }
    void updateEQ(int u,int l,int r,int pos,long long qk){
        if(l==r){
            tag[u]=0;
            tr[u]=min(tr[u],qk);
            return;
        }
        pushdown(u);
        int mid=(l+r)>>1;
        if(pos<=mid){
            updateEQ(u<<1,l,mid,pos,qk);
        }
        if(mid+1<=pos){
            updateEQ(u<<1|1,mid+1,r,pos,qk);
        }
        pushup(u);
    }
    long long query(int u,int l,int r,int ql,int qr){
        if(ql<=l&&r<=qr){
            return tr[u];
        }
        pushdown(u);
        int mid=(l+r)>>1;
        long long res=INF;
        if(ql<=mid){
            res=min(res,query(u<<1,l,mid,ql,qr));
        }
        if(mid+1<=qr){
            res=min(res,query(u<<1|1,mid+1,r,ql,qr));
        }
        return res;
    }
}seg1,seg2;
signed main(){
    freopen("express.in","r",stdin);
    freopen("express.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&p[i].val);
        p[i].id=i;
    }
    sort(p+1,p+n+1,[](Node xx,Node yy){
        return xx.val<yy.val;
    });
    nw[++Vcnt]=0;
    for(int i=1;i<=n;i++){
        if(p[i].val!=nw[Vcnt]){
            nw[++Vcnt]=p[i].val;
        }
        a[p[i].id]=Vcnt;
    }
    seg1.build(1,1,Vcnt);
    seg2.build(1,1,Vcnt);
    seg1.updateEQ(1,1,Vcnt,1,nw[a[1]]);
    seg2.updateEQ(1,1,Vcnt,1,nw[a[1]]);
    // for(int i=1;i<=n;i++){
        // printf("%d %d\n",a[i],nw[a[i]]);
    // }
    for(int i=2;i<=n;i++){
        // printf("i=%lld\n",i);
        long long tmp=min(seg2.query(1,1,Vcnt,1,a[i])+nw[a[i]],seg1.query(1,1,Vcnt,a[i],Vcnt)-nw[a[i]]);
        // printf("tmp=min(%lld(2) %lld(1))\n",seg2.query(1,1,n,1,a[i])+nw[a[i]],seg1.query(1,1,n,a[i],Vcnt)-nw[a[i]]);
        seg1.update(1,1,Vcnt,1,Vcnt,abs(nw[a[i-1]]-nw[a[i]]));
        // printf("UPD1:[%d %d]+%d\n",1,Vcnt,abs(nw[a[i-1]]-nw[a[i]]));
        seg2.update(1,1,Vcnt,1,Vcnt,abs(nw[a[i-1]]-nw[a[i]]));
        // printf("UPD2:[%d %d]+%d\n",1,Vcnt,abs(nw[a[i-1]]-nw[a[i]]));
        seg1.updateEQ(1,1,Vcnt,a[i-1],tmp+nw[a[i-1]]);
        // printf("UPD1:[%d]=min(%d)\n",a[i-1],tmp+nw[a[i-1]]);
        seg2.updateEQ(1,1,Vcnt,a[i-1],tmp-nw[a[i-1]]);
        // printf("UPD2:[%d]=min(%d)\n",a[i-1],tmp-nw[a[i-1]]);
    }
    long long ans=INF;
    for(int i=1;i<=Vcnt;i++){
        ans=min(ans,seg1.query(1,1,Vcnt,i,i)-nw[i]);
    }
    printf("%lld\n",ans);
    return 0;
}