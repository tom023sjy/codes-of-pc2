#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[1000005];
unordered_map<int,int> ans;
signed main()
{
    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);
    f[1]=1;
    ans[1]=1;
    vector<int> p;
    for(int i=2;i<=1000000;i++)
    {
        if(!f[i])
        {
            f[i]=i-1;
            p.push_back(i);
            for(int j=0;j<p.size()&&i*p[j]<=1000000;j++)
            {
                if(i%p[j]==0)
                {
                    f[i*p[j]]=f[i]*p[j];
                    break;
                }
                else
                {
                    f[i*p[j]]=f[i]*(p[j]-1);
                }
            }
        
        }
        ans[i*f[i]]=i;
    }
    int T;
    cin>>T;
    while(T--)
    {
        long long m;
        cin>>m;
        m*=2;
        cout<<ans[m]<<'\n';
    }
}