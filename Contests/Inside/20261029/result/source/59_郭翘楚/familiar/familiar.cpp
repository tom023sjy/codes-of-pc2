#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int mx[1005];
int n,m,T;
inline int check(int x,int i,int j)
{
    int pos1=x;
    int pos2=upper_bound(a[j]+1,a[j]+m+1,a[i][x])-a[j]-1;
    // cout<<x<<" "<<i<<" "<<j<<" "<<pos1+pos2<<'\n';
    return pos1+pos2;
}
int main()
{
    freopen("familiar.in","r",stdin);
    freopen("familiar.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>T;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            mx[i]=max(mx[i],a[i][j]);
        }
    }
    while(T--)
    {
        int op,x,y,k;
        cin>>op>>x>>y;
        if(op==1)
        {
            cin>>k;
            if(k==1)
            {
                cout<<max(mx[x],mx[y])<<'\n';
                continue;
            }
            k=2*m-k+1;
            int l=1,r=m,ans=0;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(check(mid,x,y)>=k)
                {
                    ans=mid;
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            if(check(ans,x,y)==k)
            {
                cout<<a[x][ans]<<'\n';
                continue;
            }
            l=1,r=m,ans=0;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(check(mid,y,x)>=k)
                {
                    ans=mid;
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            cout<<a[y][ans]<<'\n';
        }
        else
        {
            int pos=upper_bound(a[x]+1,a[x]+m+1,y)-a[x]-1;
            a[x][pos]=y;
            mx[x]=max(mx[x],y);
        }
    }
}