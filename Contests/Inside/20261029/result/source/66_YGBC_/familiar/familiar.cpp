#include<bits/stdc++.h>
using namespace std;
constexpr int X=1005;

int N,M,T,a[X][X];

inline int check(int l,int x)
{
    return upper_bound(a[l]+1,a[l]+M+1,x)-a[l]-1;
}

signed main()
{
    freopen("familiar.in","r",stdin);
    freopen("familiar.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M>>T;
    for(int i=1;i<=N;i++) 
        for(int j=1;j<=M;j++) cin>>a[i][j];

    while(T--){
        int op; cin>>op;
        if(op==1){
            int x,y,k; cin>>x>>y>>k;
            k=(M<<1)-k+1;

            int l=0, r=M;
            while(l<r){
                int mid=l+r+1>>1;
                if(check(y,a[x][mid])+mid<=k) l=mid;
                else r=mid-1;
            }

            // cerr<<l<<endl;

            if(check(y,a[x][l])+l==k) cout<<a[x][l]<<'\n';
            else cout<<a[y][k-l]<<'\n';
        }
        else{
            int x,y; cin>>x>>y;

            int p=check(x,y);
            if(p) a[x][p]=y;
        }
    }
}