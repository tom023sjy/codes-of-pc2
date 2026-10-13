#include<bits/stdc++.h>
using namespace std;
int n,m,tc,a[500005],b[500005];
void solve()
{
    cin>>n>>m;
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= m; i++) cin>>b[i];
    int p=1;
    for(int i = 1; i <= n; i++)
    {
        if(a[i]==b[p]) p++;
        if(p>m)
        {
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
    return;
}
signed main()
{
    freopen("minmax.in","r",stdin);
    freopen("minmax.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>tc;
    while(tc--) solve();
    return 0;
}