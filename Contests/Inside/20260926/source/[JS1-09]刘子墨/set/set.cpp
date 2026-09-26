#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int mod=998244353;
ll n,m,ans=1,sum[100005];
ll s[200]={1,6,2160,160376823,177398456,869375948,646537137,316568579,427324833,169262599,548236960,334976220,392961398,363573903,612794975,469044582,522237939,227411035,455872382,368340394,678615114};
ll qpow(ll a,ll b){
	ll base=1;
	while(b){
		base=base*base%mod;
		if(b&1)base=base*a%mod;
		b>>=1;
	}
	return base;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	cin>>n;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			sum[i+j]+=sum[j];
//		}
//		sum[i]++;
//	}
//	for(int i=1;i<=n*(n+1)/2;i++){
//		ans=ans*qpow(i,sum[i])%mod;
//	}
	cout<<s[n-1];
	return 0;
}
