#include<bits/stdc++.h>
using namespace std;
int n,s,p=1e9+7;
char c;
long long qp(int a,int b)
{
	if(b==0) return 1ll;
	if(b==1) return a*1ll;
	long long s=qp(a,b/2);
	if(b%2==0) return s*s%p;
	else return s*s%p*a%p;
}
long long cc(int a,int b)
{
	long long ans=1;
	for(int i=1;i<=b;i++) 
	{
		ans*=1ll*(a-i+1);
		ans%=p;
		ans*=qp(i,p-2);
		ans%=p;
	}
	return ans;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>c;
		if(c=='1') s++;
	}
	if(s==0) cout<<1;
	else if(s%2==0)
	{
		cout<<cc(n-s/2,(s+1)/2);
	}
	return 0;
}
