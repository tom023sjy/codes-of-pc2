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

int n;
const int N=1e6+5;
int nxt[N],suf[N],ans[N];
struct node{
    int pos,mx;
    friend bool operator <(node a,node b){
        return a.mx<b.mx;
    }
};
set<node> st;
int tot=1;
int main()
{
    freopen("meow.in","r",stdin);
    freopen("meow.out","w",stdout);
    cin >> n >> seed;
    vector<int> a = generate_cards(n, seed);
    // for(int i=0;i<n-1;i++) cout<<a[i]<<" ";
    // cout<<endl;
    int n=a.size();
    for(int i=0;i<n;i++) suf[i]=-1;
    for(int i=n-1;i>=0;i--){
        nxt[i]=suf[a[i]];
        suf[a[i]]=i;
    }
    // for(int i=0;i<n;i++) cout<<nxt[i]<<" ";
    // cout<<endl;
    for(int i=n-1;i>=0;i--){
        if(nxt[i]==-1) ans[i]=1;
        else{
            if(st.size()){
                auto it=st.lower_bound({0,nxt[i]});
                // cout<<nxt[i]<<" "<<it->pos<<" "<<it->mx<<endl;
                if(it==st.end()){
                    ans[i]=++tot;
                    st.insert({tot,nxt[i]});
                }
                else{
                    ans[i]=it->pos;
                    st.erase(it);
                    st.insert({it->pos,nxt[i]});
                }
            }
            else{
                ans[i]=++tot;
                st.insert({tot,nxt[i]});
            }
        }
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}