#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define lc(k) st[k].lc
#define rc(k) st[k].rc
#define mids (nl+nr)>>1
#define hh putchar(10);
#define LLM (ll)1e17
#define IM (int)1e9
#define mp(x,y) make_pair(x,y)
#define set_it set<int>::iterator
const int N=5005;
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
int n,c,H,W;
ll ans=0,s[3][N][N],ans1=0,ans2=0,sum=0;
ll C2(ll x){return x*(x-1)/2;}
int main(){
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    c=read<int>();
    n=read<int>();H=read<int>();W=read<int>();
    for(int i=1;i<=n;i++){
        int x,y,x_,y_,c;
        x=read<int>();
        y=read<int>();
        x_=read<int>();
        y_=read<int>();
        c=read<int>();
        s[0][1][1]+=c;
        s[0][x][y]-=c;
        s[0][x_+1][y]+=c;
        s[0][x][y_+1]+=c;
        s[0][x_+1][y_+1]-=c;    
        bool flag1=(x!=1||y!=1),flag2=(x_!=H||y_!=W);
        if(flag1&&!flag2){
            s[1][x][y]+=c;
            s[1][x_+1][y]-=c;
            s[1][x][y_+1]-=c;
            s[1][x_+1][y_+1]+=c;
        }
        if(flag2&&!flag1){
            s[2][x][y]+=c;
            s[2][x_+1][y]-=c;
            s[2][x][y_+1]-=c;
            s[2][x_+1][y_+1]+=c;
        }
        if(flag1) ans1+=c;
        if(flag2) ans2+=c;
        sum+=c;
    }
    for(int d=0;d<=2;d++) for(int i=1;i<=H;i++) for(int j=1;j<=W;j++) s[d][i][j]+=s[d][i-1][j]+s[d][i][j-1]-s[d][i-1][j-1];
    for(int i=1;i<=H;i++) for(int j=1;j<=W;j++){
        if(i==1&&j==1) continue ;
        if(i==H&&j==W) continue ;
        ans=max(ans,C2(s[0][i][j])+C2(s[1][i][j])+C2(sum-s[0][i][j]-s[1][i][j]));
        ans=max(ans,C2(s[0][i][j])+C2(s[2][i][j])+C2(sum-s[0][i][j]-s[2][i][j]));
    }
    ans=max(ans,C2(ans1)+C2(sum-ans1));
    ans=max(ans,C2(ans2)+C2(sum-ans2));
    write<ll>(ans);hh
    return 0;
}
//g++ chess.cpp -o C -O2 -std=c++14 -Wall