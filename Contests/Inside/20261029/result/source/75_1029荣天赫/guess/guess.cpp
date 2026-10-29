#include<bits/stdc++.h>
using namespace std;
#define int __int128_t
int read(){
    int x=0;
    char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return x;
}
int gcd(int x,int y){
    if(x%y==0) return y;
    return gcd(y,x%y);
}
void print(int x){
    if(x<10){
        putchar(x+'0');
        return ;
    }
    print(x/10);
    putchar(x%10+'0');
    return ;
}
signed main(){
    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);
    int T;
    T=read();
    while(T--){
        int m;
        m=read();
        int l=1,r=4e18;
        while(l<r){
            int mid=l+r+1>>1;
            if(mid*(mid-1)>2*m) r=mid-1;
            else l=mid;
        }
        if(l*(l-1)==2*m){
            print(l);
            putchar('\n');
            continue;
        }
        for(int n=1;n;n++){
            int sum=0;
            for(int i=1;i<=n;i++){
                if(gcd(i,n)==1) sum+=i;
            }
            if(sum==m){
                print(n);
                putchar('\n');
                break;
            }
        }
    }
    return 0;
}