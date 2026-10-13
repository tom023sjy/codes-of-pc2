#include<bits/stdc++.h>
using namespace std;
bool f[505][505][505];
int n,a[505],b[505],ans[505];
signed main()
{
    freopen("maxmin.in","r",stdin);
    freopen("maxmin.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++) cin>>b[i];
    f[1][a[1]][b[1]]=1;
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int k = 1; k <= n; k++)
            {
                f[i][min(j,a[i])][min(k,b[i])]|=f[i-1][j][k];
                f[i][max(j,a[i])][max(k,b[i])]|=f[i-1][j][k];
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(f[n][i][j]) ans[abs(i-j)]++;
        }
    }
    for(int i = 0; i < n; i++) cout<<ans[i]<<' ';
    return 0;
}