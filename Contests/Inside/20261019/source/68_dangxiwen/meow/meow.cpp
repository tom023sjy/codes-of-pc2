#include<bits/stdc++.h>

using namespace std;

struct SplitMix64 {
    uint64_t x;
    explicit SplitMix64(uint64_t seed = 0) : x(seed) {}
    uint64_t next() {
        uint64_t z = (x += 0x9e3779b97f4a7c15ULL);
        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
        z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
        return z ^ (z >> 31);
    }
    uint64_t bounded(uint64_t mod) {
        uint64_t threshold = -mod % mod;
        uint64_t r;
        do {
            r = next();
        } while (r < threshold);
        return r % mod;
    }
};
uint64_t seed;
vector<int> generate_cards(int n, uint64_t seed) {
    assert(n > 0);
    size_t m = static_cast<size_t>(n) * 2;
    uint64_t mix = seed ^ (static_cast<uint64_t>(n) * 0x9e3779b97f4a7c15ULL) ^ 0x123456789abcdef0ULL;
    SplitMix64 rng(mix);
    vector<int> a(m);
    for (int i = 0; i < n; ++i) {
        a[2 * i] = a[2 * i + 1] = i + 1;
    }
    for (size_t i = m - 1; i > 0; --i) {
        size_t j = static_cast<size_t>(rng.bounded(static_cast<uint64_t>(i) + 1));
        swap(a[i], a[j]);
    }
    return a;
}
const int mx=5e5+100;
int n;
int cnt;
int vis[mx];
struct tree
{
    int l,r,num;
}t[4*mx];
void pushup(int p)
{
    t[p].num=t[p<<1].num+t[p<<1|1].num;
}
void build(int p,int l,int r)
{
    t[p].l=l,t[p].r=r;
    if(l==r) return ;
    int mid=(l+r)/2;
    build(p<<1,l,mid),build(p<<1|1,mid+1,r);
}
int ask(int p,int l,int r)
{
    if(t[p].l>=l&&t[p].r<=r) return t[p].num;
    int ans=0;
    int mid=(t[p].l+t[p].r)/2;
    if(l<=mid) ans+=ask(p<<1,l,r);
    if(r>mid) ans+=ask(p<<1|1,l,r);
    return ans;
}
int ans[mx];
void add(int p,int pos,int x)
{
    if(t[p].l==t[p].r) 
    {
        t[p].num+=x;
        return ;
    }
    int mid=(t[p].l+t[p].r)/2;
    if(pos<=mid) add(p<<1,pos,x);
    else add(p<<1|1,pos,x);
    pushup(p);
}
int pos[mx];
stack<int> stk;
int main()
{
    freopen("meow.in","r",stdin);
    freopen("meow.out","w",stdout);
    cin >> n >> seed;
    vector<int> a = generate_cards(n, seed);
    // for (size_t i = 0; i < a.size(); ++i) {
    //     if (i) cout << ' ';
    //     cout << a[i];
    // }
    // cout << '\n';
    build(1,1,n+1);
    // cout<<"DEBUG\n";
    cnt=2;
    for(int i=0;i<2*n;i++)
    {
        int x=i;
        if(vis[a[i]]==1)
        {
            if(ask(1,2,cnt)==(cnt-2+1))
            {
                ans[x]=++cnt;
                pos[a[i]]=cnt;
                add(1,cnt,1);
                // cout<<i<<' '<<endl;
            }
            else
            {
                int l=2,r=cnt;
                int aa=r;
                while(l<=r)
                {
                    int mid=(l+r)/2;
                    if(ask(1,2,mid)<(mid-2+1)) aa=mid,r=mid-1;
                    else l=mid+1; 
                }
                ans[x]=aa;
                pos[a[i]]=ans[x];
                add(1,pos[a[i]],1);
            }
        }
        else
        {
            ans[i]=1;
            stk.push(a[i]);
        }
        vis[a[i]]++;
        while(stk.size()&&vis[stk.top()]==2)
        {
            int u=stk.top();
            stk.pop();
            add(1,pos[u],-1);
        }
    }
    for(int i=0;i<2*n;i++) cout<<ans[i]<<' '; 
    return 0;
}