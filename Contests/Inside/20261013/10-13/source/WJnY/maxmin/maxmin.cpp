#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000 + 5;
int n,a[MAXN],b[MAXN];
bitset<MAXN> f[MAXN],g[MAXN],pre[MAXN],suf[MAXN];
long long ans[MAXN];
int main()
{
    freopen("maxmin.in","r",stdin);
    freopen("maxmin.out","w",stdout);
    
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",a+i);
    for (int i=1;i<=n;i++) scanf("%d",b+i);
    for (int i=1;i<=n;i++)
        pre[i] = pre[i-1],pre[i][i] = 1;
    for (int i=n;i>=1;i--)
        suf[i] = suf[i+1],suf[i][i] = 1;
    f[a[1]][b[1]] = 1;
    for (int i=2;i<=n;i++)
    {
        for (int r=1;r<=n;r++) g[r].reset();
        int x=a[i],y=b[i];
        for (int r=1;r<=n;r++)
        {
            bitset<MAXN> cur = f[r];
            if ((cur&pre[y]).count()) cur[y] = 1; 
            g[max(r,x)] |= cur&suf[y];
        }
        for (int r=1;r<=n;r++)
        {
            bitset<MAXN> cur = f[r];
            if ((cur&suf[y]).count()) cur[y] = 1;
            g[min(r,x)] |= cur&pre[y];
        }
        for (int r=1;r<=n;r++)
            f[r] = g[r];
    }
    for (int x=1;x<=n;x++)
        for (int y=1;y<=n;y++)
            if (f[x][y]) ans[abs(x-y)] ++;
    for (int i=0;i<n;i++) printf("%lld ",ans[i]);
    return 0;
}
