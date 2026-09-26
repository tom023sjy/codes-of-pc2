#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,ans=1;
bool use[205];
void dfs(int x,int sum){
	ans=(ans*sum)%mod;
	for(int i=x+1;i<=n;i++){
		if(!use[i]){
			use[i]=1;
			dfs(i,sum+i);
			use[i]=0;
		}
	}
}
signed main(){
	//freopen("ans.out","w",stdout);
	for(int T=37;T<=40;T++){
		n=T;
		ans=1;
		for(int i=1;i<=n;i++){
			use[i]=1;
			dfs(i,i);
			use[i]=0;
		}
		cout<<ans<<',';
	}
		
	return 0;
}
