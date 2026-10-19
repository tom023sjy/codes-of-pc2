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

const int N = 500005;
int n;
vector<int> ca, ans;
int stt, stk[N], tot = 191;
int pa[N], pb[N];
bool vis[N];

int main(){
    freopen("meow.in","r",stdin);
    freopen("meow.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    cin >> n >> seed;
    ca = generate_cards(n, seed);
    //for (int i = 0; i < ca.size(); i++)
        //cout << ca[i] << ' ';

    /*for (int i = 1; i <= 2*n; i++){
        int x; cin >> x;
        ca.push_back(x);
    }*/
    if (n <= 95){
        for (int i = 1; i <= 2*n; i++){
            cout << i << " ";
        }
        return 0;
    }
    for (int i = 1; i <= 190; i++){
        stk[++stt] = i;
    }
    memset(pa,-1,sizeof(pa));
    for (int i = 0; i < 2*n; i++){
        if (pa[ca[i]] == -1) pa[ca[i]] = i;
        else pb[ca[i]] = i;
    }

    ans.resize(2*n,0);
    int now = 0;
    for (int i = (int)ca.size()-1; i >= 0; i--){
        int v = ca[i];
        if (!vis[v]){
            if (now){
                ans[i] = now;
            }
            else{
                if (stt == 0){
                    stk[++stt] = tot; tot++;
                }
                ans[i] = stk[stt--];
                now = ans[i];
            }
            vis[v] = true;
            if (stt == 0){
                stk[++stt] = tot; tot++;
            }
            ans[pa[v]] = stk[stt--];
        }
        else{
            stk[++stt] = ans[i];
            vis[v] = false;
        }
    }
    for (int i = 0; i < ca.size(); i++)
        cout << ans[i] << ' ';
    return 0;
}
