#include <bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int main()
{
    freopen("minmax.in","r",stdin);
    freopen("minmax.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>b[i];
        }
        int pos=1;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==b[pos]&&pos<=m)
            {
                pos++;
            }
        }
        // cout<<pos<<'\n';
        if(pos==m+1)
        {
            cout<<"Yes\n";
        }
        else cout<<"No\n";
    }
}