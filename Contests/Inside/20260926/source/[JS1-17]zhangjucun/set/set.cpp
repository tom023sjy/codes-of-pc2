#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll p=998244353;
int n;
ll ans=1;
__int128 s[20200];
ll qp(int a,__int128 b)
{
	if(b==0) return 1ll;
	if(b==1) return a*1ll;
	ll s=qp(a,b/2);
	if(b%2==0) return s*s%p;
	else return s*s%p*a%p;
}
void w(__int128 x)
{
	if(x>9)
	{
		w(x/10);
		putchar(x%10+'0');
	}
	else putchar(x%10+'0');
}
int main()
{
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	s[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i*(i-1)/2;j>=0;j--) 
		{
			s[j+i]+=s[j];
			s[j+i]%=(p-1);
		}
	}
	for(int i=1;i<=n*(n+1)/2;i++)
	{
		ans=ans*qp(i,s[i])%p;
	}
	cout<<ans;
	return 0;
}
