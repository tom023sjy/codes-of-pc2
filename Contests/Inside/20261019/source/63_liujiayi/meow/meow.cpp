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
const int N=5e5+5;
int n;
queue<int>q;
int tot;
int p[N];
int New(){
    if(q.size()){
        int x=q.front();q.pop();
        return x;
    }return ++tot;
}
vector<int>ans;
mt19937 rd(19302794);
vector<int>id;
int pos[N];
int val[N];
int siz[N];
int main(){
    freopen("meow.in","r",stdin);
    freopen("meow.out","w",stdout);
    cin>>n>>seed;
    vector<int>a=generate_cards(n,seed);
    reverse(a.begin(),a.end());
    int nw=0;
    for(int i:a){
        if(p[i])val[i]=++nw,p[i]=0;
        else p[i]=1;
    }
    for(int i:a){
        if(p[i]){
            int x=New();ans.push_back(x);
            q.push(x);
            siz[p[i]]--;
            if(!siz[p[i]]){
                q.push(p[i]);
                for(int j=0;j<id.size();j++)if(id[j]==p[i]){
                    id.erase(id.begin()+j,id.begin()+j+1);
                    break;
                }
            }
        }else{
            p[i]=-1;
            for(int j:id)if(val[pos[j]]<val[i])if(p[i]==-1||val[pos[j]]>val[pos[p[i]]])p[i]=j;
            if(p[i]==-1)p[i]=New(),id.push_back(p[i]);
            ans.push_back(p[i]);pos[p[i]]=i;
            siz[p[i]]++;
        }
    }
    reverse(ans.begin(),ans.end());
    for(int i:ans)printf("%d ",i);puts("");
    return 0;
}