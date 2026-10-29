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

const int N=1010;

int n,m,T;
int a[N][N];

int main(){
    freopen("familiar.in","r",stdin);
    freopen("familiar.out","w",stdout);
    n=rdi(),m=rdi(),T=rdi();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) a[i][j]=rdi();
        a[i][m+1]=INT_MAX;
    }
    while(T--){
        int op=rdi();
        if(op==1){
            int x=rdi(),y=rdi(),k=rdi();
            int l=max(0,k-m),r=min(k,m);
            while(l<r){
                int mid=(l+r)/2;
                if(a[x][m-mid+1]<=a[y][m-(k-mid)+1]) r=mid;
                else l=mid+1;
            }
            int res=min(a[x][m-l+1],a[y][m-(k-l)+1]);
            if(l&&k-l+1<=m) res=max(res,min(a[x][m-(l-1)+1],a[y][m-(k-(l-1))+1]));
            cout<<res<<'\n';
        }
        else{
            int x=rdi(),y=rdi();
            int pos=upper_bound(a[x]+1,a[x]+m+1,y)-a[x]-1;
            if(pos) a[x][pos]=y;
        }
    }
    return 0;
}