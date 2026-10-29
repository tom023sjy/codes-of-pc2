#include<bits/stdc++.h>
using namespace std;
#define homo_number 114514
#define mod 998244353
//#define mod 1000000007
//#define int long long
int n,h[2005];
bool isfind[55];
bitset<100005> f,g;
signed main()
{
    freopen("cup.in","r",stdin);
    freopen("cup.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>h[i];
    sort(h+1,h+n+1);
    f[0]=1;
    for(int i = n; i >= 1; i--)
    {
        g=0;
        for(int j = 1; j <= 50; j++)
        {
            if(isfind[j])
            {
                g|=(f<<(j-h[i]));
            }
        }
        f|=g;
        if(i!=n) isfind[h[i]]=1;
    }
    for(int i = 0; i <= 50*n; i++)
    {
        if(f[i]) cout<<i<<' ';
    }
    return 0;
}