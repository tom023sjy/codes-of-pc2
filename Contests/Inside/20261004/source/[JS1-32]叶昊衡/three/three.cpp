#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005,Mod=1e9+7;
int n,m,num[5],f[N];
signed main()
{
	freopen("three.in","r",stdin);
	freopen("three.out","w",stdout);
	cin>>n>>m;
	for(int i=1,x;i<=n;i++)
		cin>>x,num[x]++;
	f[0]=1;
	if(num[1]!=num[2]||num[1]!=num[3]||num[2]!=num[3])
	{
		cout<<0;
		return 0;
	}
	int x=num[1]%3;
	num[1]-=x,num[2]-=x,num[3]-=x;
	for(int i=1;i<=num[1];i++)
	{
		if(i-1>=0) f[i]=(f[i]+f[i-1])%Mod;
		if(i-3>=0) f[i]=(f[i]+f[i-3])%Mod;
	}
	cout<<f[num[1]];
}
