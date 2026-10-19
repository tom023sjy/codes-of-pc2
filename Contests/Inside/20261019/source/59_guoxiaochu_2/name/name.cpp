#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
    freopen("name.in","r",stdin);
    freopen("name.out","w",stdout);
    int cid,q;
    cin>>cid>>q;
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x,y;
            cin>>x>>y;
            a[x]=y;
        }
        else
        {
            int k;
            cin>>k;
            int ans=0;
            for(int i=1;;i++)
            {
                if(k>a[i])
                {
                    ans+=a[i]*i;
                    k=k-a[i];
                }
                else
                {
                    ans+=i*k;
                    break;
                }
            }
            cout<<ans<<'\n';
        }
    }
}