#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int p=500000;
int ans[500005];
int a[500005];
int b[500005];
unordered_set<long long> f[500005];
signed main()
{
    freopen("maxmin.in","r",stdin);
    freopen("maxmin.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    bool flagA=true;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        if(a[i]!=b[i]) flagA=false;
    }
    if(flagA)
    {
        cout<<n<<' ';
        for(int i=1;i<n;i++)
        {
            cout<<0<<' ';
        }
        cout<<'\n';
        return 0;
    }
    f[1].insert(a[1]*p+b[1]);
    for(int i=1;i<n;i++)
    {
        for(auto j:f[i])
        {
            int x=j/p,y=j%p;
            f[i+1].insert(1ll*min(a[i+1],x)*p+1ll*min(b[i+1],y));
            f[i+1].insert(1ll*max(a[i+1],x)*p+1ll*max(b[i+1],y));
        }
    }
    for(auto i:f[n])
    {
        ans[abs(i/p-(i%p))]++;
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<' ';
    }
}