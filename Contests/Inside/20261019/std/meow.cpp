#include <bits/stdc++.h>
using namespace std;

uint64_t seed;
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

const int N = 5e5+10,B = 6400,M = 190;

int n;
int x[N],y[N];
int id[N],l[N],r[N];
int ans[N*2];
vector<int> L,R;

int Y[N];

int get(int X,int l,int r)
{
    int ret=0;
    while(l <= r)
    {
        int mid = (l+r)>>1;
        if(Y[mid] > X)
        {
            ret = mid;
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("meow.in","r",stdin);
    freopen("meow.out","w",stdout);
    cin >> n >> seed;
    L.push_back(0),R.push_back(0);
    vector<int> A = generate_cards(n,seed);
    for(int i=1,now;i<=n*2;i++)
    {
        // cin >> now;
        now = A[i-1];
        if(!x[now]) x[now] = i,L.push_back(now);
        else y[now] = i,R.push_back(now);
    }
    int tot=0;
    int now=n;
    for(int i=M;i>=1;i--)
    {
        while(tot > 0)
        {
            Y[tot--] = 0;
        }
        while(now >= 1)
        {
            int nowx = x[R[now]];
            int to = get(nowx,1,tot);
            if(!to) to = ++tot;
            if(to == i) break;
            Y[to] = nowx;
            ans[y[R[now]]] = to;
            ans[x[R[now]]] = i;
            now--;
        }
        // cerr << tot << '\n';
    }
    cerr << now << '\n';
    for(int i=1;i<=n*2;i++)
    {
        cout << ans[i] << ' ';
    }
}