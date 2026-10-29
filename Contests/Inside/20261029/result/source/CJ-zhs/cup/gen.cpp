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

mt19937 rng(random_device {}());
template<typename T>
T rand(T l,T r){
    return uniform_int_distribution<T>(l,r)(rng);
}

int n,m;

int main(int argc,char **argv){
    n=atoi(argv[1]),m=atoi(argv[2]);
    cout<<n<<'\n';
    for(int i=1;i<=n;i++) cout<<rand(1,m)<<' ';
    cout<<'\n';
    return 0;
}