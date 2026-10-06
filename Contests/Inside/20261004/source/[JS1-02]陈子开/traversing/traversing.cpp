#include<bits/stdc++.h>
#define mid (pl+pr>>1)
#define ls (p<<1)
#define rs (ls|1)
using namespace std;
const int N=1e5+5;
int n,q;
int l[N],r[N];
int tp[N];
int id[N],cnt;
int tag[N<<2];
vector<int> Q;

void dfs(int u) {
    if(tp[u]==1) {
        id[u]=++cnt;
        if(l[u]!=0) dfs(l[u]);
        if(r[u]!=0) dfs(r[u]);
    }
    else if(tp[u]==2) {
        if(l[u]!=0) dfs(l[u]);
        id[u]=++cnt;
        if(r[u]!=0) dfs(r[u]);
    }
    else {
        if(l[u]!=0) dfs(l[u]);
        if(r[u]!=0) dfs(r[u]);
        id[u]=++cnt;
    }
    return ;
}

void pushdown(int p) {
    if(tag[p]==0) return ; 
    tag[ls]=tag[rs]=tag[p];
    tag[p]=0;
    return ;
}

void update(int L,int R,int p,int pl,int pr,int k) {
    if(L<=pl&&pr<=R) {
        tag[p]=k;
        return ;
    }
    pushdown(p);
    if(mid>=L) update(L,R,ls,pl,mid,k);
    if(mid<R) update(L,R,rs,mid+1,pr,k);
    return ;
}

void clear(int p,int pl,int pr) {
    if(pl==pr) {
        tp[pl]=tag[p];
        return ;
    }
    pushdown(p);
    clear(ls,pl,mid);
    clear(rs,mid+1,pr);
    return ;
}

void solve() {
    cin>>n>>q;
    for(int i=1;i<=n;i++) {
        cin>>l[i]>>r[i];
    }
    tag[1]=1;
    while(q--) {
        int op;
        cin>>op;
        if(op==1) {
            int L,R,k;
            cin>>L>>R>>k;
            update(L,R,1,1,n,k+2);
        }
        else {
            int k;
            cin>>k;
            Q.push_back(k);
        }
    }
    dfs(1);
    clear(1,1,n);
    for(int query:Q) {
        cout<<id[query]<<'\n';
    }
    return ;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("traversing.in","r",stdin);
    freopen("traversing.out","w",stdout);
    solve();
    return 0;
}