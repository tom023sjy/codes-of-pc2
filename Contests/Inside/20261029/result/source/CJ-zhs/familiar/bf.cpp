#include <bits/stdc++.h>
#include <iterator>

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
    freopen("familiar.ans","w",stdout);
    n=rdi(),m=rdi(),T=rdi();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) a[i][j]=rdi();
        a[i][m+1]=INT_MAX;
    }
    while(T--){
        int op=rdi();
        if(op==1){
            int x=rdi(),y=rdi(),k=rdi();
            vi tmp;
            merge(a[x]+1,a[x]+m+1,a[y]+1,a[y]+m+1,back_inserter(tmp));
            cout<<tmp[2*m-k]<<'\n';
        }
        else{
            int x=rdi(),y=rdi();
            int pos=upper_bound(a[x]+1,a[x]+m+1,y)-a[x]-1;
            if(pos) a[x][pos]=y;
        }
    }
    return 0;
}