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

const int N=1e3+10,L=10000000;

int n,m,T;

int main(int argc,char **argv){
    n=atoi(argv[1]),m=atoi(argv[2]),T=atoi(argv[3]);
    cout<<n<<' '<<m<<' '<<T<<'\n';
    for(int i=1;i<=n;i++){
        static int a[N];
        for(int j=1;j<=m;j++) a[j]=rand(1,L);
        sort(a+1,a+m+1);
        for(int j=1;j<=m;j++) cout<<a[j]<<' ';
        cout<<'\n';
    }
    while(T--){
        int op=rand(1,2);
        cout<<op<<' ';
        if(op==1){
            int x=rand(1,n),y=rand(1,n),k=rand(1,2*m);
            cout<<x<<' '<<y<<' '<<k<<'\n';
        }
        else{
            int x=rand(1,n),y=rand(1,L);
            cout<<x<<' '<<y<<'\n';
        }
    }
    return 0;
}