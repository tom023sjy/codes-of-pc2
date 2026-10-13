#include <bits/stdc++.h>
using namespace std;

const int N = 5010;

int n,a[N],b[N];
bool f[N][N],nf[N][N];
int ans[N];
int main()
{
    freopen("maxmin.in","r",stdin);
    freopen("maxmin.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> b[i];
    }
    f[a[1]][b[1]] = 1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(!f[j][k]) continue;
                nf[min(j,a[i])][min(k,b[i])] = 1;
                nf[max(j,a[i])][max(k,b[i])] = 1;
            }
        }
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                f[j][k] = nf[j][k];
                nf[j][k] = 0;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(f[i][j]) ans[abs(i-j)]++;
        }
    }
    for(int i=0;i<n;i++) cout << ans[i] << ' ';
}