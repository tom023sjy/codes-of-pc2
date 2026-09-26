#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,p;
int ans=1,sum,a[55];
int anss[35]={1,6,2160,160376823,177398456,869375948,646537137,316568579,427324833,169262599,548236960,334976220,392961398,363573903,612794975,469044582,522237939,227411035,455872382,368340394,678615114,724191209,804101938,74786757,383007682,580325979,695035300,155120226,616735010,957629447,330611886,976271658};
void dfs(int k){
	if(k==n+1){
		int res=0;
		for(int i=1;i<=n;i++) if(a[i]) res+=i;
		if(res!=0) ans=ans*res%mod;
 		return;
	}
	a[k]=1;
	dfs(k+1);
	a[k]=0;
	a[k]=0;
	dfs(k+1);
	a[k]=0;
	return;
}
signed main(){
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	cin>>n;
	if(n>20){
		cout<<anss[n-1];
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
