#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,d;
int ren[500005];
signed main()
{
    freopen("hire.in","r",stdin);
    freopen("hire.out","w",stdout);
    cin>>n>>m>>k>>d;
    while(m--)
    {
        int x,y,cnt=0;
        bool f=1;
        cin>>x>>y;
        ren[x]+=y;
        for(int i=1;i<=n-d;i++)
        {
            cnt+=ren[i];
            if(cnt>(d+1)*k)
            {
                cout<<"NO\n";
                f=0;
            }
            cnt=max(cnt-k,0ll);
        }
        if(f) cout<<"YES\n";
    }
    return 0;
}