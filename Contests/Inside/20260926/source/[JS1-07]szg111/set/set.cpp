#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=20205;
const int mod=998244353;
int ans[N],ans2[N];
int n,cnt=1;
int qpow(int x,int m){
	int res=1;
	while(m){
		if(m&1)res=x*res%mod;
		x*=x;
		x%=mod;
		res%=mod;
		m>>=1;
	}return res;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	cin>>n;
	ans[1]=1,ans[2]=0;
	if(n==1){
		cout<<1;
		exit(0);
	}
	for(int i=2;i<=n;i++){
		for(int k=1;k<=n*(n+1)/2;k++){
			ans2[k]=ans[k];
		}
		for(int j=1;j<=(i-1)*i/2;j++){
			if(ans[j]!=0)
				ans2[j+i]=ans[j+i]+ans[j];
		}
		for(int k=1;k<=n*(n+1)/2;k++){
			ans[k]=ans2[k]%(mod-1);
		}
		ans[i]++;
	}
	for(int i=1;i<=n*(n+1)/2;i++){
		if(ans[i]!=0)cnt=cnt*qpow(i,ans[i])%mod;
	//	cout<<i<<" "<<ans[i]<<"\n";
	}cout<<cnt%mod;
	return 0;
} 
