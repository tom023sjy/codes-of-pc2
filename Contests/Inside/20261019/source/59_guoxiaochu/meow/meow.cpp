#include <bits/stdc++.h>
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
int n;
int r[500005];
int pos[500005];
set<pair<int,int>> s;
int st[500005];
int d[500005];
int main()
{
    freopen("meow.in","r",stdin);
    freopen("meow.out","w",stdout);
    cin >> n >> seed;
    vector<int> a = generate_cards(n, seed);
    for(int i=0;i<n*2;i++)
    {
        if(!pos[a[i]])
        {
            cout<<a[i]<<" ";
            pos[a[i]]=a[i];
        }
        else
        {
            cout<<n+1<<" ";
        }
    }
    // int m=0;
    // for(int i=0;i<2*n;i++)
    // {
    //     if(!d[a[i]])
    //     {
    //         auto j=s.upper_bound(make_pair(r[i],0));
    //         if(!s.empty()) j=prev(j);
    //         if(j==s.begin())
    //         {
    //             d[a[i]]=++m;
    //         }
    //         else
    //         {
    //             d[a[i]]=d[(*j).second];
    //         }
    //         cout<<d[a[i]]<<' ';
    //         s.insert(make_pair(r[i],i));
    //     }
    //     else
    //     {
    //         if(d[a[i]]==1) cout<<2<<" ";
    //         else cout<<d[a[i]]-1<<" ";
    //     }
    // }
    return 0;
}