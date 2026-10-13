#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int n,m,a[N],b[N];

void solve()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=m;i++) cin >> b[i];
    int now = 1;
    for(int i=1;i<=n;i++)
    {
        if(a[i] == b[now]) now++;
    }
    if(now > m) cout << "Yes\n";
    else cout << "No\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("minmax.in","r",stdin);
    freopen("minmax.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
}