#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+5;
int a[N],b[N];
int f[2][N][N],ans[N];
int mx[N],mi[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    freopen("maxmin.in","r",stdin);
    freopen("maxmin.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    f[1][a[1]][b[1]]=1;
    for(int i=2;i<=n;i++){
        for(int x=1;x<=n;x++){
            for(int y=1;y<=n;y++) f[i&1][x][y]=0;
        }
        for(int x=1;x<=n;x++){
            for(int y=1;y<=n;y++){
                f[i&1][max(x,a[i])][max(y,b[i])]|=f[(i-1)&1][x][y];
                f[i&1][min(x,a[i])][min(y,b[i])]|=f[(i-1)&1][x][y];
            }
        }
    }
    for(int x=1;x<=n;x++){
        for(int y=1;y<=n;y++){
            ans[abs(x-y)]+=f[n&1][x][y];
        }
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    return 0;
}