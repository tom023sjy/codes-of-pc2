#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int a[N][N];
int n,m,T;
inline int get(int x,int y){
    int pos = lower_bound(a[x]+1,a[x]+m+1,y)-a[x];
    return m-pos+1;
}
signed main(){
    freopen("familiar.in","r",stdin);
    freopen("familiar.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>T;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    while(T--){
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1){
            int k;
            cin>>k;
            int l = 1,r = m,ans = 0;
            if(a[x][1]>a[y][1])swap(x,y);
            while(l<=r){
                int mid = (l+r)>>1;
                if(m-mid+1+(m-(lower_bound(a[y]+1,a[y]+m+1,a[x][mid])-a[y])+1)<=k)ans = mid,r = mid-1;
                else l = mid+1;
            }
            if(ans==0){
                cout<<a[y][m-k+1]<<"\n";
                continue;
            }
            int o = get(y,a[x][ans]);
            int tmp = m-ans+1+o;
            if(tmp==k)cout<<a[x][ans]<<"\n";
            else{
                o = -o+m+1;
                cout<<a[y][o-(k-tmp)]<<"\n";
            }
        }
        else{
            int pos = upper_bound(a[x]+1,a[x]+m+1,y)-a[x]-1;
            if(pos!=0)a[x][pos] = y;
        }
    }

    return 0;
}