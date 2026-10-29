#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int a[1010][1010];
int find_leq_k(int x,int k){
    if(k<a[x][1]){
        return 0;
    }
    if(k>=a[x][m]){
        return m;
    }
    int L=1,R=m,res=1;
    while(L<=R){
        int mid=(L+R)>>1;
        if(a[x][mid]<=k){
            res=mid;
            L=mid+1;
        }else{
            R=mid-1;
        }
    }
    return res;
}
signed main(){
    freopen("familiar.in","r",stdin);
    freopen("familiar.out","w",stdout);
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=q;i++){
        int opt,x,y,k;
        scanf("%d%d%d",&opt,&x,&y);
        if(opt==1){
            scanf("%d",&k);
            k=2*m+1-k;
            int L=1,R=1000000000,res=-1;
            while(L<=R){
                int mid=(L+R)>>1;
                int resx=find_leq_k(x,mid)+find_leq_k(y,mid);
                // printf("mid=%d res=%d case:%d\n",mid,resx,resx<k);
                if(resx<k){
                    L=mid+1;
                }else{
                    res=mid;
                    R=mid-1;
                }
            }
            printf("%d\n",res);
        }else{
            int res=find_leq_k(x,y);
            a[x][res]=y;
        }
    }
    return 0;
}