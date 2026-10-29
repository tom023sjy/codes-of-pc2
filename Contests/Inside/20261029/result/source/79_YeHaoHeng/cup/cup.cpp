#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2005,V=4000005;
int n,h[N],put[N],Top;
bool used[N],have[N];
int L[N],R[N];
void Put(int t)
{
    if(t==n+1)
    {
        int Sum=0;
        for(int i=1;i<=n;i++)
            L[put[i]]=max(L[put[i-1]],h[put[i]]);
        for(int i=n;i>=1;i--)
            R[put[i]]=max(R[put[i+1]],h[put[i]]);
        for(int i=1;i<=n;i++)
        {
            if(L[put[i-1]]<h[put[i]]) continue;
            if(R[put[i+1]]<h[put[i]]) continue;
            Sum+=min(L[put[i-1]],R[put[i+1]])-h[put[i]];
        }
        Top=max(Top,Sum);
        have[Sum]=1;
        return;
    }
    for(int i=1;i<=n;i++)
        if(!used[i])
        {
            used[i]=1,put[t]=i;
            Put(t+1);
            used[i]=0;
        }
}
signed main()
{
    freopen("cup.in","r",stdin);
    freopen("cup.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i];
    Put(1);
    for(int i=0;i<=Top;i++)
        if(have[i]) cout<<i<<' ';
}
