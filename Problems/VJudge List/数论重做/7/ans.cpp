#include<bits/stdc++.h>
#define MAXN 
#define reg register
#define inl inline
#define int long long
using namespace std;
int a,b,ans;
signed main()
{
	scanf("%lld %lld",&a,&b);
	if(a*a==4*b) return puts("inf"),0;
	reg int x=1,t=sqrt(b);
	if(t*t==b) ans++;
	while(1)
	{
		reg int A=x*2-a,B=b-x*x;
		if(((A>0 && B>0) || (A<0 && B<0)) && !(B%A)) ans++;
		if(A>0 && B<0) break;
		x++;
	}
	printf("%lld\n",ans);
	return 0;
}
