#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans=1;
vector<int>v;
const int mod=998244353;
signed main()
{
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int sum=1,siz=v.size();
		for(int j=0,x;j<siz;j++)
		{
			x=(v[j]+i)%mod,sum=(sum*x)%mod;
			v.push_back(x);
		}
		v.push_back(i);
		sum=(sum*i)%mod,ans=(ans*sum)%mod;
	}
	cout<<ans;
}
