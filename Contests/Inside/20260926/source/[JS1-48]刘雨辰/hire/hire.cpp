#include<bits/stdc++.h>
using namespace std;
#define int long long
int cnt[2010];
signed main()
{
	freopen("hire.in","r",stdin);
	freopen("hire.out","w",stdout);
	int n,m,k,d;
	cin>>n>>m>>k>>d;
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		cnt[x]+=y;
		bool f=1;
		int sum=k*d;
		for(int i=1;i<=n-d;i++)
		{
			sum-=cnt[i];
			sum+=k;
			if(sum<0)f=0;
		}
		if(!f)cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}


