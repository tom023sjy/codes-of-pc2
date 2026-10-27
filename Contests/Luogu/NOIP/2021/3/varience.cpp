#include <bits/stdc++.h>
using namespace std;
const int N=10001,INF=1e9;
typedef long long ll;
int n,a[N];

ll calc()
{
	ll s1=0,s2=0;
	for(int i=1;i<=n;i++)
	{
		s1+=a[i];
		s2+=a[i]*a[i];
	}
	return n*s2-s1*s1;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	ll ans=calc();
	for(int c=0;n*c<1e8;c++)
	{
		int k=rand()%(n-2)+2;
		a[k]=a[k-1]+a[k+1]-a[k];
		ans=min(ans,calc());
	}
	cout<<ans;
}



int n,a[N],d[N],f[50*N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<n;i++) d[i]=a[i+1]-a[i];
    sort(d+1,d+n);
    int m=n*a[n],s=0;
    for(int j=1;j<=m;j++) f[j]=INF;
    for(int i=1;i<n;i++)
    {
        if(!d[i]) continue;
        s+=d[i];//当前数 
        for(int j=m;j>=0;j--)
        {
            if(f[j]==INF) continue;
            f[j+s]=min(f[j+s],f[j]+s*s);
            f[j+i*d[i]]=min(f[j+i*d[i]],f[j]+d[i]*(2*j+i*d[i]));
            f[j]=INF;
        }
    }
    long long ans=2e18;
    for(int j=0;j<=m;j++) if(f[j]<INF) ans=min(ans,1ll*n*f[j]-1ll*j*j);
    printf("%lld\n",ans);
    return 0;
}
