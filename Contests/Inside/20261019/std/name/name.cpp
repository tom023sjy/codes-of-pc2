#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6+10,M = 1e6+100;

int m,cid;
int a[N];

struct SGT
{
#define ls (p<<1)
#define rs (ls|1)
#define mid ((l+r)>>1)
ll t[M<<2],cnt[M<<2],f[M<<2],tp[M<<2][2],tag[M<<2];

void add(int p,int x)
{
    cnt[p] += x;
    tag[p] += x;
    if(x&1) swap(tp[p][0],tp[p][1]);
}
void pushdown(int p)
{
    if(!tag[p]) return;
    add(ls,tag[p]);
    add(rs,tag[p]);
    tag[p] = 0;
}
void pushup(int p)
{
    tp[p][0] = tp[ls][0] + tp[rs][0];
    tp[p][1] = tp[ls][1] + tp[rs][1];
    t[p] = t[ls] + t[rs];
    f[p] = f[ls] + f[rs];
    cnt[p] = cnt[rs];
}
void build(int p,int l,int r)
{
    if(l == r)
    {
        t[p] = cnt[p] = f[p] = tag[p] = 0;
        tp[p][0] = 1,tp[p][1] = 0;
        return;
    }
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
}
void modify(int p,int l,int r,int id,ll &x)
{
    if(!x) return;
    if(l == r)
    {
        if(id == l) t[p] += x;
        ll nxt=((cnt[p]+x)/2) - (cnt[p]/2);
        tp[p][cnt[p]&1] = 0;
        cnt[p] += x;
        f[p] = (cnt[p]+1)/2 * (l-1);
        tp[p][cnt[p]&1] = 1;
        x = nxt;
        // cerr << l << " cnt = " << cnt[p] << '\n';
        // cerr << nxt << '\n';
        return;
    }
    if(id < l && x == 1 && !tp[p][0]) {add(p,x);return;}
    if(id < l && x == -1 && !tp[p][1]) {add(p,x);return;}
    pushdown(p);
    if(id <= mid) modify(ls,l,mid,id,x);
    modify(rs,mid+1,r,id,x);
    pushup(p);
}
int query(int p,int l,int r,ll k)
{
    // cerr << l << ',' << r << ' ' << k << '\n';
    if(l == r) return l;
    pushdown(p);
    if(t[ls] - cnt[ls]/2 <= k) return query(rs,mid+1,r,k-t[ls]);
    else return query(ls,l,mid,k);
}
ll queryf(int p,int l,int r,int L,int R)
{
    // cerr << p << ' ' << l << ' ' << r << ' ' << L << ' ' << R << ' ' << f[p] << ',' << tp[p][1] << '\n';
    if(L <= l && r <= R) return f[p] + tp[p][1];
    pushdown(p);
    ll ret=0;
    if(L <= mid) ret += queryf(ls,l,mid,L,R);
    if(R > mid) ret += queryf(rs,mid+1,r,L,R);
    return ret;
}
ll queryg(int p,int l,int r,int id)
{
    // cerr << l << ',' << r << ' ' << id << "   " << t[p]-cnt[p]/2 << '\n';
    if(l == r) return t[p] - cnt[p]/2;
    pushdown(p);
    if(id <= mid) return queryg(ls,l,mid,id);
    else return t[ls] + queryg(rs,mid+1,r,id);
}
}t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
    cin >> cid >> m;
    t.build(1,1,M);
    for(ll i=1,tp,x,y;i<=m;i++)
    {
        cin >> tp;
        if(tp == 1)
        {
            cin >> x >> y;
            if(x == 1) a[1] = y;
            else y -= a[x],a[x] += y,t.modify(1,1,M,x,y);
        }
        else
        {
            cin >> x;
            if(x <= a[1]) {cout << x << '\n';continue;}
            x -= a[1];
            int k = t.query(1,1,M,x) - 1;
            cout << a[1] + t.queryf(1,1,M,1,k) + (x - t.queryg(1,1,M,k)) * k << '\n';
            // cout << t.queryf(1,1,M,1,k) << ' ' << t.queryg(1,1,M,k) << '\n';
        }
    }
}