#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll p=1e9+7;
int n,m,a[5050],s[5050];
bool b=0;
int main()
{
	freopen("three.in","r",stdin);
	freopen("three.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		s[a[i]]++;
	}
	for(int i=1;i<=m;i++) if(s[i]>=3) b=1;
	if(b==0)
	{
		b=1;
		for(int i=1;i<=m-2;i++)
		{
			if(s[i]>s[i+1]||s[i]>s[i+2])
			{
				b=0;
				break;
			}
			s[i+1]-=s[i],s[i+2]-=s[i];
		}
		if(s[m-1]!=0||s[m]!=0) b=0;
		if(b==0) cout<<0;
		else cout<<1;
	}
	else
	{
		ll ans=1ll;
		for(int i=1;i<=m;i+=4)
		{
			if(s[i]%3!=s[i+1]%3||s[i]%3!=s[i+2]%3||s[i+2]%3!=s[i+1]%3) 
			{
				ans=0;
				break;
			}
			else 
			{
				ans*=1ll*min(s[i],min(s[i+1],s[i+2]))/3+1;
				ans%=p;
			}
		}
		cout<<ans;
	}
	return 0;
}
