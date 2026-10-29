#include <iostream>
using namespace std;
int a[1005][1005],m,n,T,MX=1e9+1;
int ck(int x,int y,int V)
{
    return lower_bound(a[x]+1,a[x]+1+m,V)-1-a[x]+lower_bound(a[y]+1,a[y]+1+m,V)-a[y]-1;
}
int main()
{
    freopen("familiar.in","r",stdin);
    freopen("familiar.out","w",stdout);
    //freopen("express.out","w",stdout);
    scanf("%d%d%d",&n,&m,&T);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    //cout<<ck(1,2,7);
    //return 0;
    while(T--)
    {
        int opt,x,y,K;
        scanf("%d%d%d",&opt,&x,&y);
        if(opt==1)
        {
            scanf("%d",&K);
            int l=1,r=MX;
            K=2*m-K+1;
            while(l!=r)
            {
                int mid=(l+r)/2;
                if(ck(x,y,mid)>=K)r=mid;
                else l=mid+1;
            }
            printf("%d\n",l-1);
        }
        else
        {
            int l=lower_bound(a[x]+1,a[x]+1+m,y+1)-a[x]-1;
            a[x][l]=y;
        }

    }
    return 0;
}
/*
g++ b.cpp -g -o b -std=c++14
gdb -q -tui ./b
b 20 
r
disp a[1][0]@5
disp a[2][0]@5
disp a[3][0]@5
diff ex_familiar4.out familiar.out
*/