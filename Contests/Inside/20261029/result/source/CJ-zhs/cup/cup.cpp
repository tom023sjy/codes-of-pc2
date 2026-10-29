#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using u64=unsigned long long;
using db=double;
using pii=pair<int,int>;
using vi=vector<int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch-'0'),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back

const int N=505,W=52;

int n,h[N];

namespace SUB12{
    const int N=52;
    bitset<N*W> f[N][N][N];
    void solve(){
        f[0][0][0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=i;j>=0;j--){
                for(int k=i-j;k>=0;k--){
                    auto &nw=f[i][j][k];
                    //if(nw.none()) continue;
                    if(j) f[i][j-1][k]|=(nw<<h[i]);
                    if(k) f[i][j][k-1]|=(nw<<h[i]);
                    for(int i1=i+1;i1<n;i1++){
                        f[i1][j+i1-i-1][k]|=(nw<<h[i1]);
                        f[i1][i1-i-1][j+k]|=(nw<<h[i1]);
                    }
                }
            }
        }
        int sum=accumulate(h+1,h+n,0);
        for(int i=0;i<N*W;i++)
            if(f[n-1][0][0][i]) cout<<(i-sum)<<' ';
    }
}

namespace TEST{
    bitset<N*W> f[W][N];
    int cnt[N],sum[N];
    void solve(){
        int mx=h[n-1];
        for(int i=1;i<n;i++) cnt[h[i]]++;
        for(int i=1;i<=mx;i++) sum[i]=sum[i-1]+cnt[i];
        f[0][0][0]=1;
        for(int i=0;i<=mx;i++){
            for(int j=sum[i];j>=0;j--){
                auto &nw=f[i][j];
                if(j) f[i][j-1]|=(nw<<i);
                for(int i1=i+1;i1<=mx;i1++){
                    if(!cnt[i1]) continue;
                    f[i1][j+sum[i1]-sum[i]-1]|=(nw<<i1);
                }
            }
        }
        int sum=accumulate(h+1,h+n,0);
        for(int i=0;i<N*W;i++)
            if(f[mx][0][i]) cout<<(i-sum)<<' ';
    }
}

int main(){
    freopen("cup.in","r",stdin);
    freopen("cup.out","w",stdout);
    n=rdi();
    for(int i=1;i<=n;i++) h[i]=rdi();
    sort(h+1,h+n+1);
    if(n<=50) SUB12::solve();
    else TEST::solve();
    return 0;
}