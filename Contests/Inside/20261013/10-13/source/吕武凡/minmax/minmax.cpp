#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int a[200010],b[200010];
int main()
{
    freopen("minmax.in","r",stdin);
    freopen("minmax.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=m;i++) cin>>b[i];
        if(n<m)
        {
            cout<<"No"<<'\n';
            continue;
        }
        int p=1;
        for(int i=1;i<=m;i++)
        {
            while(a[p]!=b[i]&&p<=n) p++;
            if(p>n)
            {
                cout<<"No"<<'\n';
                goto mn;
            }
        }
        cout<<"Yes"<<'\n';
        mn:;
    }
}