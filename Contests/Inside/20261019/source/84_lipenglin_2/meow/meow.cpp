#include <vector>
#include <cassert>
#include <cstddef>
#include <utility>
#include <cstdint>
#include <iostream>

using namespace std;
const int N=1e6+50;
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
bool vis[N];
int main()
{
    freopen("meow.in","r",stdin);
    freopen("meow.out","w",stdout);
    cin >> n >> seed;
    vector<int> a = generate_cards(n, seed);
    for (size_t i = 0; i < a.size(); ++i) {
        if(!vis[a[i]]){
            vis[a[i]]=1;
            cout<<1<<" ";
        }
        else{
            cout<<1+a[i]<<" ";
        }
    }
    cout << '\n';
    return 0;
}