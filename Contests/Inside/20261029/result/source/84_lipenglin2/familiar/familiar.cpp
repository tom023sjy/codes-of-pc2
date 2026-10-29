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
const int N=1050;
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
int a[N][N],n,m,T;
inline int find(int id,int val){
    int l=1,r=m,mid,ans=0;
    while(l<=r){
        mid=(l+r)>>1;
        if(a[id][mid]<=val) ans=mid,l=mid+1;
        else r=mid-1;
    }
    return ans;
}
int main(){
    freopen("familiar.in","r",stdin);
    freopen("familiar.out","w",stdout);
    n=read<int>(),m=read<int>(),T=read<int>();
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=read<int>();
    while(T--){
        int op=read<int>();
        if(op==1){
            int x=read<int>(),y=read<int>(),k=read<int>(),l=1,r=m,mid,ans=IM;
            while(l<=r){
                mid=(l+r)>>1;
                if(m-mid+1+m-find(y,a[x][mid])<=k) ans=a[x][mid],r=mid-1;
                else l=mid+1;
            }
            l=1,r=m;
            while(l<=r){
                mid=(l+r)>>1;
                if(m-mid+1+m-find(x,a[y][mid])<=k) ans=min(ans,a[y][mid]),r=mid-1;
                else l=mid+1;
            }
            write<int>(ans);hh
        }
        else{
            int x=read<int>(),y=read<int>();
            a[x][find(x,y)]=y;
        }
    }
    return 0;
}
/*
g++ familiar.cpp -o F -O2 -std=c++14 -Wall
./F
*/