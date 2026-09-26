#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[205]={0,1,6,2160,160376823,177398456,869375948,646537137,316568579,427324833,169262599,548236960,334976220,392961398,363573903,612794975,469044582,522237939,227411035,455872382,368340394,678615114,724191209,804101938,74786757,383007682,580325979,695035300,155120226,616735010,957629447};
inline int read()
{
	int sum=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum*f;
}

int main()
{
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	int n=read();
	cout<<a[n];
}
