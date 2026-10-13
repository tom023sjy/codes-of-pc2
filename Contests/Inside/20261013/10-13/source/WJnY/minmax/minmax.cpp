#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 12;
int n,m,a[MAXN],b[MAXN];
void work()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",a+i);
    for (int i=1;i<=m;i++) scanf("%d",b+i);
    int j = 1;
    for (int i=1;i<=n;i++)
    {
        if (j<=m&&a[i]==b[j]) j++;
    }
    if (j<=m) printf("No\n");
    else printf("Yes\n");
}
int main()
{
    freopen("minmax.in","r",stdin);
    freopen("minmax.out","w",stdout);
    int t;scanf("%d",&t);
    while (t--) work();
    return 0;
}