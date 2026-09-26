#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;int c[510][510];
const int mod=1e9+7;
int work(int l,int r)
{
//	cout<<l<<" "<<r<<endl;
	int n0=0,n1=0;
	for(int i=l;i<=r;i++)
	{
		if(s[i]=='0')n0++;
		if(s[i]=='1')n1++;
	}
//	cout<<n0<<" "<<n1<<endl;
	n1/=2;
	if(n1==0)return 0;
	return c[n0+n1][n1];
}
signed main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n;
	cin>>n;
	cin>>s;
	int l=0,r=0,now0=0,nxl=0,ans=0;
	for(int i=1;i<=n;i++)c[i][0]=1,c[i][1]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=i;j++)
		{
			c[i][j]=c[i-1][j]+c[i-1][j-1];
			c[i][j]%=mod;
			//cout<<i<<" "<<j<<" "<<c[i][j]<<endl;
		}
	}
	s+='1';
	for(;r<=n;r++)
	{
		if(s[r]=='0'&&now0==1)
		{
//			cout<<"bs\n";
			now0=2;nxl=r;
		}
		if(s[r]=='1'&&now0==0)
		{
//			cout<<"sb\n";
			now0=1;
		}
		if(s[r]=='1'&&now0==2||r==n)
		{
//			cout<<"bssb\n";
			ans+=work(l,r-1);
			l=nxl;
			now0=0;
		}
		ans%=mod;
	}
	if(ans==0)ans++;
	cout<<ans;
	return 0;
}



