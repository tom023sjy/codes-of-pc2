#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int num[5010];
int dp[5010];
const int mod=998244353;
signed main()
{
	freopen("three.in","r",stdin);
	freopen("three.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		num[x]++;
	}
	dp[0]=1;
	int sum=0;
	/*for(int i=1;i<=m;i++)
	{
		cout<<num[i]<<" ";
	}*/
	if(num[1]%3==0)dp[1]=1;
	if(num[2]%3==0&&dp[1])dp[2]=1;
	for(int i=3;i<=m;i++)
	{
		sum+=num[i];
		if(sum%3!=0)
		{
			dp[i]=0;continue;
		}
		dp[i]=0;
		if(i>=3&&num[i-2]+num[i-1]+num[i]>=0)
		{
			if(num[i]%3==num[i-1]%3&&num[i-2]%3==num[i-1]%3)
			{
				int h=min(num[i],min(num[i-1],num[i-2]))/3;
				dp[i]+=dp[i-3]*(h+1);
				dp[i]%=mod;
			}
			else
			{
				dp[i]=dp[i-1];
			}
			continue;
		}
		if(i>=2&&num[i-1]%3+num[i]%3==0)
		{
			dp[i]+=dp[i-2];continue;
		}
		dp[i]=dp[i-1];
	}
	cout<<dp[m];
	return 0;
}
