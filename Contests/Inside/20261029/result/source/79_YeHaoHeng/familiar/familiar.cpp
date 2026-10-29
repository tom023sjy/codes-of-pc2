#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1005;
int n,m,t,a[N][N];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("familiar.in","r",stdin);
    freopen("familiar.out","w",stdout);
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++) a[i][m+1]=1e18;
    while(t--)
    {
        int o,x,y,k;
        cin>>o>>x>>y;
        if(o==1)
        {
            cin>>k;
            k=2*m-k+1;
            int l=max(0LL,k-m),r=min(m,k),i,j,ans=-1;
            while(l<=r)
            {
                i=(l+r)/2,j=k-i;
                if(a[x][i]>a[y][j+1]) r=i-1;
                else if(a[y][j]>a[x][i+1]) l=i+1;
                else
                {
                    ans=i;
                    break;
                }
            }
            cout<<max(a[x][ans],a[y][k-ans])<<'\n';
        }
        else
        {
            int l=1,r=m,mid,ans=-1;
            while(l<=r)
            {
                mid=(l+r)/2;
                if(a[x][mid]<=y) l=mid+1,ans=mid;
                else r=mid-1;
            }
            if(ans!=-1) a[x][ans]=y;
        }
    }
}
