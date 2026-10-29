#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6+10;

int n;
int x[N],pos[N],m;

struct SGT
{
    #define ls (p<<1)
    #define rs (ls|1)
    #define mid ((l+r)>>1)
    ll t[N<<2],t1[N<<2],t2[N<<2],tag[N<<2];
    void pushdown(int p)
    {
        if(!tag[p]) return;
        t[ls] += tag[p];
        t[rs] += tag[p];
        t1[ls] += tag[p];
        t1[rs] += tag[p];
        t2[ls] += tag[p];
        t2[rs] += tag[p];
        tag[ls] += tag[p];
        tag[rs] += tag[p];
        tag[p] = 0;
    }
    void build(int p,int l,int r)
    {
        t[p] = t1[p] = t2[p] = 1e18;
        if(l == r) return;
        build(ls,l,mid);
        build(rs,mid+1,r);
    }
    void modify(int p,int l,int r,int id,ll x)
    {
        t[p] = min(t[p],x);
        t1[p] = min(t1[p],x-pos[id]);
        t2[p] = min(t2[p],x+pos[id]);
        if(l == r) return;
        pushdown(p);
        if(id <= mid) modify(ls,l,mid,id,x);
        else modify(rs,mid+1,r,id,x);
    }
    void add(ll x)
    {
        t[1] += x;
        t1[1] += x;
        t2[1] += x;
        tag[1] += x;
    }
    ll query()
    {
        return t[1];
    }
    ll query1(int p,int l,int r,int L,int R)
    {
        if(L > R) return 1e18;
        if(L <= l && r <= R) return t1[p];
        pushdown(p);
        ll ret=1e18;
        if(L <= mid) ret = min(ret,query1(ls,l,mid,L,R));
        if(R > mid) ret = min(ret,query1(rs,mid+1,r,L,R));
        return ret;
    }
    ll query2(int p,int l,int r,int L,int R)
    {
        if(L > R) return 1e18;
        if(L <= l && r <= R) return t2[p];
        pushdown(p);
        ll ret=1e18;
        if(L <= mid) ret = min(ret,query2(ls,l,mid,L,R));
        if(R > mid) ret = min(ret,query2(rs,mid+1,r,L,R));
        return ret;
    }
}t;

int main()
{
    freopen("express.in","r",stdin);
    freopen("express.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> x[i];pos[i] = x[i];
    }
    sort(pos+1,pos+n+1);
    m = unique(pos+1,pos+n+1) - pos - 1;
    for(int i=1;i<=n;i++)
    {
        x[i] = lower_bound(pos+1,pos+m+1,x[i]) - pos;
    }
    t.build(1,0,m);
    t.modify(1,0,m,0,0);
    for(int i=1;i<=n;i++)
    {
        ll mn = min(t.query1(1,0,m,0,x[i]) + pos[x[i]],t.query2(1,0,m,x[i]+1,m) - pos[x[i]]);
        t.add(abs(pos[x[i]]-pos[x[i-1]]));
        t.modify(1,0,m,x[i-1],mn);
    }
    cout << t.query();
}