#include<bits/stdc++.h>
#define i8 __int128
using namespace std;
i8 read(){
    i8 p=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
    return p;
}
void write(i8 x){
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
i8 m; 
int len;
i8 b[100000001];
void solve(i8 x){
    i8 t=x;len=0;
    for(i8 i=2;i*i<=x;i++){
        if(t%i==0){
            b[++len]=i;
            while(t%i==0) t/=i;
        }
    }
    if(t>1) b[++len]=t; 
    i8 res=1;
    for(int i=len;i;i--){
        if(x%b[i]==0){
            x/=(b[i]-1);
            int cnt=0;
            while(x%b[i]==0) x/=b[i],cnt++;
            cnt++;
            cnt>>=1;
            while(cnt--) res*=b[i];
        }
    } 
    write(res);
    putchar('\n');
}
void solve1(){
    i8 l=2,r=20000000000,ans=0;
    while(l<=r){
        i8 mid=(l+r)/2;
        i8 op=mid*(mid-1); 
        if(op<=m) ans=mid,l=mid+1;
        else r=mid-1;
    }
    write(ans);
    putchar('\n');
}
int main(){
    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);  
    int T;scanf("%d",&T);
    while(T--){
        m=read();
        m=m*2;
        if(m>2000000000){
            solve1();
        }
        else solve(m);
    }
    return 0;
}