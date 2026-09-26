#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,d;
int cnt[2005];
signed main(){
	freopen("hire.in","r",stdin);
	freopen("hire.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
	int x,y;
	while(m--){
		scanf("%lld%lld",&x,&y);
		cnt[x]+=y;
		int sum=k*d,f=0;
		for(int i=1;i<=n-d;i++){
			sum=min(sum,k*d);
			sum+=k;
			sum-=cnt[i];
			if(sum<0){f=1;break;}
		}
		if(!f)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
