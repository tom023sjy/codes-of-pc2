#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
int n,m,k,d,x,y;
ll cnt[N],mx;
bool check()
{
	ll tmp=0;
	for(int i=1;i<=n;i++)
	{
		tmp+=cnt[i];
		tmp=max(0ll,tmp-k);
		if(tmp>mx)return 0;
	}
	return 1;
}
int main()
{
	freopen("hire.in","r",stdin);
	freopen("hire.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&k,&d);
	mx=(ll)k*d;
	while(m--)
	{
		scanf("%d%d",&x,&y);
		cnt[x]+=y;
		if(check())printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
