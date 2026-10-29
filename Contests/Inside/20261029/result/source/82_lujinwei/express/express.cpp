#include<iostream>
using namespace std;
long long f[1005][1005],a[1000005];
int main()
{
    freopen("express.in","r",stdin);
    freopen("express.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=0;j<=n;j++)
            f[i][j]=1e18;
    f[1][0]=a[1];
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
        {
            f[i+1][j]=min(f[i+1][j],f[i][j]+abs(a[i+1]-a[i]));
            f[i+1][i]=min(f[i+1][i],f[i][j]+abs(a[i+1]-a[j]));
        }
    long long ans=1e18;
    for(int i=0;i<n;i++)
        ans=min(ans,f[n][i]);
    cout<<ans;
    return 0;
}