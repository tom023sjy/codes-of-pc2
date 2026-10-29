#include<bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
int n,h[2010],pre[2010],nxt[2010],tot=0;
set<int> s;
int calc()
{
    int res=-tot;
    pre[0]=0;
    for(int i=1;i<=n;i++) pre[i]=max(pre[i-1],h[i]);
    nxt[n+1]=0;
    for(int i=n;i>=1;i--) nxt[i]=max(nxt[i+1],h[i]);
    for(int i=1;i<=n;i++) res+=min(pre[i],nxt[i]);
    return res;
}
int main()
{
    freopen("cup.in","r",stdin);
    freopen("cup.out","w",stdout);
    clock_t start=clock();
    cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i],tot+=h[i];
    while(1)
    {
        shuffle(h+1,h+n+1,rng);
        s.insert(calc());
        clock_t end=clock();
        if(1.0*(end-start)/CLOCKS_PER_SEC>=0.900) break;
    }
    set<int>::iterator it;
    for(it=s.begin();it!=s.end();it++) cout<<*it<<" ";
}