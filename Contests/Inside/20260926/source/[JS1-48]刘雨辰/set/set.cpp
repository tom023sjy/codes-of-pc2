#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int num[20110];
int qp(int y,int x)
{
	int ans=1;
	y%=mod;
	while(x)
	{
		if(x&1)
		{
			ans*=y;
			x--;
			ans%=mod;
		}
		y*=y;
		x>>=1;
		y%=mod;
	}
	return ans;
}
signed main()
{
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
    int n;
    cin>>n;
    num[1]=1;
    for(int i=2;i<=n;i++)
    {
    	for(int j=20100;j>=i+1;j--)
    	{
    		num[j]+=num[j-i];
    		num[j]%=(mod-1);
		}
		num[i]++;
	}
	int ans;
	for(int i=1;i<=n*(n+1)/2;i++)
	{
		ans*=qp(i,num[i]);
		ans%=mod;
	}
	cout<<ans;
	return 0;
}

