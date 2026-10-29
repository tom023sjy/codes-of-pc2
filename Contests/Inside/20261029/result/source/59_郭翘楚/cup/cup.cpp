#include <bits/stdc++.h>
using namespace std;
int h[2005];
vector<int> v[2005];
bitset<2005*50> f[2];
int main()
{
    freopen("cup.in","r",stdin);
    freopen("cup.out","w",stdout);
    int n;
    cin>>n;
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
    }
    sort(h+1,h+n+1);
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(h[j]!=h[i]) v[i].push_back(h[j]-h[i]);

        }
        sort(v[i].begin(),v[i].end());
        v[i].erase(unique(v[i].begin(),v[i].end));
    }
    f[0][0]=1;
    for(int i=1;i<n;i++)
    {
        int now=i&1;
        int pre=now^1;
        f[now]=f[pre];
        for(int j:v[i])
        {
            f[now]|=f[pre]<<j;
        }
    }
    for(int i=0;i<=n*50;i++)
    {
        if(f[(n-1)&1][i]==1)
        {
            cout<<i<<' ';
        }
    }
}