#include<bits/stdc++.h>
using namespace std;
#define homo_number 114514
#define mod 998244353
//#define mod 1000000007
//#define int long long
int n,m,q,a[1005][1005],op,x,y,z;
int solve1(int x,int y,int z)
{
    int nl=max(0,z-m),nr=min(z,m),mid,ans=m,now;
    // cout<<nl<<' '<<nr<<endl;
    while(nl<=nr)
    {
        mid=(nl+nr)>>1;
        // cout<<nl<<' '<<nr<<' '<<mid<<'\n';
        // cout<<m+1-mid<<' '<<m+1-z+mid<<'\n';
        // now=m-(lower_bound(a[x]+1,a[x]+m+1,mid)-a[x])+1+m-(lower_bound(a[y]+1,a[y]+m+1,mid)-a[y])+1;
        if(a[x][m+1-mid]<a[y][m+1-(z-mid)])
        {
            ans=mid;
            nr=mid-1;
        }
        else
        {
            nl=mid+1;
        }
    }
    // cout<<ans<<endl;
    return max(min(a[x][m+1-ans],a[y][m+1-(z-ans)]),min(a[x][m+1-ans+1],a[y][max(0,m+1-(z-ans)-1)]));
}
signed main()
{
    freopen("familiar.in","r",stdin);
    freopen("familiar.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>q;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin>>a[i][j];
        }
        a[i][m+1]=1145141919;
    }
    while(q--)
    {
        cin>>op;
        if(op==1)
        {
            cin>>x>>y>>z;
            a[x][0]=a[y][0]=0;
            cout<<solve1(x,y,z)<<'\n';
        }
        else
        {
            cin>>x>>y;
            int npos=upper_bound(a[x]+1,a[x]+m+1,y)-a[x]-1;
            a[x][npos]=y;
        }
    }
    return 0;
}