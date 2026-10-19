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
int n,f[500010],stk[500010],len=0;
int t1[500010],t2[500010],ans[500010];
int find(int x)
{
    if(f[x]==x) return x;
    else return f[x]=find(f[x]);
}
void merge(int x,int y)
{
    int xx=find(x),yy=find(y);
    if(xx==yy) return;
    f[xx]=yy;
    return;
}
int main()
{
    freopen("meow.in","r",stdin);
    freopen("meow.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>seed;
    vector<int> a = generate_cards(n, seed);
    for(int i=1;i<=n;i++) f[i]=i,t1[i]=-1;
    for(int i=0;i<2*n;i++)
    {
        if(t1[a[i]]==-1) t1[a[i]]=i;
        else t2[a[i]]=i;
    }
    for(int i=0;i<2*n;i++)
    {
        if(i==t1[a[i]])
        {
            if(len!=0) merge(stk[len],a[i]),stk[len]=a[i];
            else stk[++len]=a[i];
            ans[a[i]]=len;
            cout<<len<<" ";
        }
        else
        {
            int p=0;
            for(int j=1;j<=len;j++)
            {
                if(j==ans[a[i]]) continue;
                if(find(stk[j])!=find(a[i]))
                {
                    p=j;
                    break;
                }
                else if(t1[stk[j]]<t1[a[i]])
                {
                    p=j;
                    break;
                }
            }
            if(p!=0) merge(stk[p],a[i]),stk[p]=a[i],cout<<p<<" ";
            else stk[++len]=a[i],cout<<len<<" ";
        }
    }
    return 0;
}