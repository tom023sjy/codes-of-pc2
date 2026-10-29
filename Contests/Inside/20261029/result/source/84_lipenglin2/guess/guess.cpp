#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ill __int128
#define ld long double
#define lc(k) st[k].lc
#define rc(k) st[k].rc
#define mids (nl+nr)>>1
#define hh putchar(10);
#define LLM (ll)1e18
#define IM (int)1e9
#define mp(x,y) make_pair(x,y)
#define Re(x) qpow(x,mod-2)
const int N=2050;
const int MN=6e4+50;
template<class T>
inline T read(){
    T x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}
template<class T>
inline void write(T ans){
    if(ans<0){putchar('-');write<T>(-ans);}
    else if(ans<10) putchar(ans+'0');
    else{write<T>(ans/10);putchar(ans%10+'0');}
    return ;
}
ll gcd(ll a,ll b){return (!b?a:gcd(b,a%b));}
int main(){
    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);
    int T=read<int>();
    while(T--){
        ll m=read<ll>();
        int ans=-1;
        for(int i=1;i<=400;i++){
            ll tans=0;
            for(int j=1;j<=i;j++) if(gcd(i,j)==1) tans+=j;
            if(tans==m){ans=i;break ;}
        }
        if(ans==-1){write<}
        write<int>(ans);hh
    }
    return 0;
}
/*
g++ guess.cpp -o G -O2 -std=c++14 -Wall
./G

*/