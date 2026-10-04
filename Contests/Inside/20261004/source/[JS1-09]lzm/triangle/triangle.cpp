#include<bits/stdc++.h>
using namespace std;
const int maxn =1e5+5;
int n,a[12][12],b[12][12],c[12][12],a2[12][12],a3[12][12],minx=55;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("triangle.in","r",stdin);
    freopen("triangle.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>a[i][j];
            c[i][i-j+1]=a[i][j];
            a2[n-i+j][n-i+1]=a[i][j];
            //a3[2*n-2*i+1][i+1-j]=a[i][j];
        }
    }//a3逆时针旋转不正确,干脆旋转两轮(第一轮顺时针转到a2,第二轮顺时针旋转到a3)
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            a3[n-i+j][n-i+1]=a2[i][j];
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=i;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=i;j++){
    //         cout<<a2[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=i;j++){
    //         cout<<a3[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    int min1,min2,min3,min4,min5,min6;
    min1=min2=min3=min4=min5=min6=minx=(n*(n+1)/2);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>b[i][j];
            if(a[i][j]==b[i][j]){
                min1--;
            }
            if(a[i][i-j+1]==b[i][j]){
                min4--;
            }
            if(a2[i][j]==b[i][j]){
                min2--;
            }
            if(a2[i][i-j+1]==b[i][j]){
                min5--;
            }
            if(a3[i][j]==b[i][j]){
                min3--;
            }
            if(a3[i][i-j+1]==b[i][j]){
                min6--;
            }
        }
    }
    minx=min(min(min1,min(min2,min3)),min(min4,min(min5,min6)));
    cout<<minx;
    return 0;
}