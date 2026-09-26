#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,m,d;
ll k,a[N];
bool check(){
	ll sum=0;
	for(int i=1;i<=n;++i){
		sum=max(0ll,sum+a[i]-k);
		if(sum>k*d) return false;
	}
	return true;
}
int main(){
	freopen("hire.in","r",stdin);
	freopen("hire.out","w",stdout);
	scanf("%d%d%lld%d",&n,&m,&k,&d);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x]+=y;
		check()?printf("YES\n"):printf("NO\n");
	}
	return 0;
} 
