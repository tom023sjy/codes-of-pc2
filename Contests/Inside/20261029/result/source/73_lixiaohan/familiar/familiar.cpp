#include<bits/stdc++.h>
using namespace std;
int x[1005][1005],n,m;
int solve(int a,int b,int t){
    int l=max(0,t-m),r=min(m,t);
    while(l<=r){
        int i=(l+r)/2,j=t-i;
        if(i>0&&j<m&&x[a][i]>x[b][j+1]){
            r=i-1;
        }
        else if(j>0&&i<m&&x[b][j]>x[a][i+1]){
            l=i+1;
        }
        else{
            if(i==0){
                return x[b][j];
            }
            if(j==0){
                return x[a][i];
            }
            return max(x[a][i],x[b][j]);
        }
    }
}
void update(int a,int b){
    int* p=upper_bound(x[a]+1,x[a]+m+1,b);
    if(p!=x[a]+1){
        *(p-1)=b;
    }
}
int main(){
    freopen("familiar.in","r",stdin);
    freopen("familiar.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>x[i][j];
        }
    }
    while(t--){
        int op;
        cin>>op;
        if(op==1){
            int a,b,k;
            cin>>a>>b>>k;
            k=2*m-k+1;
            cout<<solve(a,b,k)<<"\n";
        }
        else{
            int a,b;
            cin>>a>>b;
            update(a,b);
        }
    }
    return 0;
}
