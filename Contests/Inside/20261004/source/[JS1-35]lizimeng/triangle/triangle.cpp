#include<bits/stdc++.h>
using namespace std;
int n;
int a[15][15],b[15][15];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("triangle.in","r",stdin);
    freopen("triangle.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>b[i][j];
        }
    }
    int ans=INT_MAX;
    for(int i=1;i<=3;i++){
        int res[15][15]={0},tot=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                res[i][j]=a[n+1-j][i-j+1];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                a[i][j]=res[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                tot+=(a[i][j]!=b[i][j]);
            }
        }
        ans=min(ans,tot);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                res[i][j]=a[i][i-j+1];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                a[i][j]=res[i][j];
            }
        }
        tot=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                tot+=(a[i][j]!=b[i][j]);
            }
        }
        ans=min(ans,tot);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                res[i][j]=a[i][i-j+1];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                a[i][j]=res[i][j];
            }
        }
    }
    cout<<ans;
    return 0;
}