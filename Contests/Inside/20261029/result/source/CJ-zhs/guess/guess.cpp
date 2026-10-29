#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using u64=unsigned long long;
using i128=__int128_t;
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

i128 m;

namespace BF{
    bool check(){
        return m<=INT_MAX;
    }
    inline int phi(int n){
        int ret=n;
        for(int i=2;i<=n/i;i++){
            if(n%i) continue;
            while(n%i==0) n/=i;
            ret=ret/i*(i-1);
        }
        if(n>1) ret=ret/n*(n-1);
        return ret;
    }
    void solve(){
        int m=::m;
        for(int i=1;i<=m/i;i++){
            if(m%i) continue;
            int x=i,y=m/i;
            if(phi(y)==x) {cout<<y<<endl;return;}
        }
    }
}

namespace PRIME{
    void solve(){
        i64 l=0,r=2e18;
        while(l<r){
            i64 mid=(l+r)/2;
            if((i128)mid*(mid-1)<m) l=mid+1;
            else r=mid;
        }
        cout<<l<<'\n';
    }
}

void solve(){
    m=read<i128>()*2;
    if(BF::check()) BF::solve();
    else PRIME::solve();
}

int main(){
    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);
    int T=rdi();
    while(T--) solve();
    return 0;
}