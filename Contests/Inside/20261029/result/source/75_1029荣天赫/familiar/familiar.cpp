#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int a[N][N];
int n,m,q;
int read(){
    int x=0;
    char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return x;
}
int check(int pos,int v){
    int l=0,r=m+1;
    while(l<r){
        int mid=l+r>>1;
        if(a[pos][mid]<v) l=mid+1;
        else r=mid;
    }
    return m-l+1;
}
int solve(int x,int y,int k){
    int l=0,r=m+1;
    while(l<r){
        int mid=l+r+1>>1;
        if(check(y,a[x][mid])+m-mid+1>=k) l=mid;
        else r=mid-1;
    }
    if(check(y,a[x][l])+m-l+1==k) return a[x][l];
    swap(x,y);
    l=0,r=m+1;
    while(l<r){
        int mid=l+r+1>>1;
        if(check(y,a[x][mid])+m-mid+1>=k) l=mid;
        else r=mid-1;
    }
    if(check(y,a[x][l])+m-l+1==k) return a[x][l];
}
void update(int x,int v){
    int l=1,r=m;
    while(l<r){
        int mid=l+r+1>>1;
        if(a[x][mid]<=v) l=mid;
        else r=mid-1;
    }
    if(a[x][l]<=v) a[x][l]=v;
    return ;
}
int main(){
    freopen("familiar.in","r",stdin);
    freopen("familiar.out","w",stdout);
    n=read(),m=read(),q=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) a[i][j]=read();
        a[i][m+1]=1e9+5;
    }
    while(q--){
        int op;
        op=read();
        if(op==1){
            int x,y,k;
            x=read(),y=read(),k=read();
            cout<<solve(x,y,k)<<'\n';
        }
        else{
            int x,y;
            x=read(),y=read();
            update(x,y);
        }
    }
    return 0;
}