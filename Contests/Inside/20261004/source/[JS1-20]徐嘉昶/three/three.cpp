#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1e9+7;
int n,m;
int xxkan[5005];
signed main()
{
	freopen("three.in","r",stdin);
	freopen("three.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		xxkan[x]++;
	}
	if(m==1)
	{
		cout<<"1";
		return 0;
	}
	else if(m==2)
	{
		if(xxkan[1]%3==0)
		{
			cout<<"1";
			return 0;
		}
		else cout<<"0";
	}
	else if(m==3)
	{
		int ans=0;
		if(xxkan[1]%3==xxkan[2]%3&&xxkan[2]%3==xxkan[3]%3)
		{
			ans=min(xxkan[1]/3,min(xxkan[2]/3,xxkan[3]/3));
			cout<<ans;
			return 0;
		}
		else
		{
			cout<<"0";
			return 0;
		}
	}
	else if(m==4)
	{
		int ans=0;
		if(xxkan[2]%3==xxkan[3]%3&&(xxkan[1]+xxkan[4])%3==xxkan[2]%3)
		{
			xxkan[2]-=xxkan[1]%3+xxkan[4]%3;
			xxkan[3]-=xxkan[1]%3+xxkan[4]%3;
			xxkan[1]-=xxkan[1]%3;
			xxkan[4]-=xxkan[4]%3;
			for(int i=0;i<=xxkan[1]/3;i++)
			{
				if(xxkan[1]-i*3==0&&xxkan[2]-i*3==0&&xxkan[3]-i*3==0) ans++;
				ans+=max(0ll,min(min(xxkan[2]-i*3,xxkan[3]-i*3),xxkan[4])/3ll);
			}
			for(int i=0;i<=xxkan[4]/3;i++)
			{
				if(xxkan[2]-i*3==0&&xxkan[3]-i*3==0&&xxkan[4]-i*3==0) ans++;
				ans+=max(0ll,min(min(xxkan[2]-i*3,xxkan[3]-i*3),xxkan[1])/3ll);
			}
			cout<<ans;
		}
		else 
		{
			cout<<"0";
			return 0;
		}
	}
	else
	{
		bool f=1;
		for(int i=1;i<=n;i++)
		{
			if(xxkan[i]>2)
			{
				f=0;
				break;
			}
		}
		if(f)
		{
			for(int i=3;i<=m;i++)
			{
				int minn=min(xxkan[i],min(xxkan[i-1],xxkan[i-2]));
				xxkan[i]-=minn,xxkan[i-1]-=minn,xxkan[i-2]-=minn;
			}
			for(int i=1;i<=m;i++)
			{
				if(xxkan[i]!=0)
				{
					cout<<"0";
					return 0;
				}
			}
			cout<<"1";
			return 0;
		}
		else 
		{
			int ans=1;
			int xx=m%4;
			if(xx==0||xx==3)
			{
				for(int i=3;i<=m;i+=4)
				{
					if(xxkan[i]%3==xxkan[i-1]%3&&xxkan[i-1]%3==xxkan[i-2]%3)
					{
						ans*=min(xxkan[i]/3,min(xxkan[i-1]/3,xxkan[i-2]/3)),ans%=MOD;
					}
					else
					{
						ans=0;
						break;
					}
				}
			}
			else if(xx==1)
			{
				if(xxkan[m]%3!=0)
				{
					ans=0;
				}
				else 
				{
					for(int i=3;i<=m;i+=4)
					{
						if(xxkan[i]%3==xxkan[i-1]%3&&xxkan[i-1]%3==xxkan[i-2]%3)
						{
							ans*=min(xxkan[i]/3,min(xxkan[i-1]/3,xxkan[i-2]/3)),ans%=MOD;
						}
						else
						{
							ans=0;
							break;
						}
					}
				}
			}
			else if(xx==2)
			{
				if(xxkan[m]%3!=0||xxkan[m-1]%3!=0)
				{
					ans=0;
				}
				else 
				{
					for(int i=3;i<=m;i+=4)
					{
						if(xxkan[i]%3==xxkan[i-1]%3&&xxkan[i-1]%3==xxkan[i-2]%3)
						{
							ans*=min(xxkan[i]/3,min(xxkan[i-1]/3,xxkan[i-2]/3)),ans%=MOD;
						}
						else
						{
							ans=0;
							break;
						}
					}
				}
			}
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
