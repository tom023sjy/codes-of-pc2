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
const int M=55;
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
int maxh,sumh,cnt[N],n,mn;
bitset<MN> dp[N];
int main(){
    freopen("cup.in","r",stdin);
    freopen("cup.out","w",stdout);
    n=read<int>();
    for(int i=1;i<=n;i++){
        int h=read<int>();
        sumh+=h,maxh=max(maxh,h),cnt[h]++;
    }
    for(int i=maxh;i>=1;i--) cnt[i]+=cnt[i+1];
    for(int l=1;l<=n;l++) dp[l].reset();
    if(cnt[maxh]==1) dp[1][maxh]=1;
    else for(int l=2;l<=n;l++) dp[l][maxh*l]=1;
    for(int h=maxh-1;h>=1;h--){
        if(cnt[h]==cnt[h+1]) continue ;
        for(int l=2;l<=n;l++) dp[l]|=(dp[l-1]<<h);
        for(int l=1;l<cnt[h];l++) dp[l].reset();
    }
    for(int i=0;i<MN;i++) if(dp[n][i]&&i>=sumh){write<int>(i-sumh);putchar(' ');}hh
    return 0;
}
/*
g++ cup.cpp -o C -O2 -std=c++14 -Wall
./C

*/