#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,q,a[1005][1005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("familiar.in","r",stdin);
    freopen("familiar.out","w",stdout);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for (int j=1;j<=m;j++) cin>>a[i][j];
        a[i][m+1]=0x3f3f3f3f3f3f3f3f;
    }
    while(q--){
        int op,x,y;
        cin>>op>>x>>y;
        if (op==1){
            int k;
            cin>>k;
            k=m*2-k+1;
            int l=max(0ll,k-m),r=min(m,k);
            while(l<=r){
                int mid=(l+r)/2;
                int p1=mid;
                int p2=(k-mid);
                //cout<<l<<" "<<r<<" "<<k<<" "<<p1<<" "<<p2<<" \n";
                if (a[x][p1]>a[y][p2+1]) r=mid-1;
                else if (a[y][p2]>a[x][p1+1]) l=mid+1;
                else {
                    cout<<max(a[x][p1],a[y][p2])<<"\n";
                    break;
                }
            }

        }else {
            int l=1,r=m,pos=0;
            while(l<=r){
                int mid=(l+r)/2;
                if (a[x][mid]<=y) l=mid+1,pos=mid;
                else r=mid-1;
            }
            a[x][pos]=y;
        }
    }
    return 0;
}
/*
3 3 5
2 6 7
1 4 9
3 5 8
1 1 2 3
1 2 3 1
2 3 12
1 2 3 1
1 1 3 5




*/
