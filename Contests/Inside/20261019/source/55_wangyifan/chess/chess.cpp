#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

const int N=1e5+5,M=5005;
int cid,n,h,w,x1[N],x2[N],y[N],y2[N],c[N],s[4],f[N],p=0,q=0,ans=0,d[M][M],e[M][M],sum=0,res=0,g[M][M][10];
vector <int > b[4];

signed main()
{
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    cin>>cid;
    cin>>n>>h>>w;
    for (int i=1;i<=n;i++)
    {
        cin>>x1[i]>>y[i]>>x2[i]>>y2[i]>>c[i];
        sum+=c[i];
        d[x1[i]][y[i]]+=c[i];
        d[x2[i]+1][y[i]]-=c[i];
        d[x1[i]][y2[i]+1]-=c[i];
        d[x2[i]+1][y2[i]+1]+=c[i];
        e[x1[i]][y[i]]+=c[i]*(c[i]-1)/2;
        e[x2[i]+1][y[i]]-=c[i]*(c[i]-1)/2;
        e[x1[i]][y2[i]+1]-=c[i]*(c[i]-1)/2;
        e[x2[i]+1][y2[i]+1]+=c[i]*(c[i]-1)/2;
        if (x1[i]>1||y[i]>1) b[0].push_back(i),s[0]+=c[i];
        if (x1[i]>1||y2[i]<w) b[1].push_back(i),s[1]+=c[i];
        if (x2[i]<h||y[i]>1) b[2].push_back(i),s[2]+=c[i];
        if (x2[i]<h||y2[i]<w) b[3].push_back(i),s[3]+=c[i];
    }
    for (int i=1;i<=h;i++)
        for (int j=1;j<=w;j++) d[i][j]+=d[i][j-1]+d[i-1][j]-d[i-1][j-1],e[i][j]+=e[i][j-1]+e[i-1][j]-e[i-1][j-1];
    for (int i=1;i<=h;i++)
		for (int j=1;j<=w;j++) res=max(res,(sum-d[i][j])*(sum-d[i][j]-1)/2+e[i][j]);
    if (s[1]>s[p]) p=1;
    if (s[3]>s[p]) p=3;
    if (s[2]>s[p]) p=2;
    ans+=s[p]*(s[p]-1)/2;
    for (int i:b[p])
    {
        if (f[i]) continue ;
        f[i]=1;
        if (x1[i]>1||y[i]>1) s[0]-=c[i];
        if (x1[i]>1||y2[i]<w) s[1]-=c[i];
        if (x2[i]<h||y[i]>1) s[2]-=c[i];
        if (x2[i]<h||y2[i]<w) s[3]-=c[i];
    }
    if (s[0]>s[p]) p=0;
    if (s[1]>s[p]) p=1;
    if (s[3]>s[p]) p=3;
    if (s[2]>s[p]) p=2;
    ans+=s[p]*(s[p]-1)/2;
    cout<<max(res,ans);
    return 0;
}
