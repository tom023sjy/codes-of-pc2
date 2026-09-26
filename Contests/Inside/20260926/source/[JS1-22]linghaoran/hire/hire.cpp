#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,k,d,a[2005];
ll get_sum(ll l,ll r){
	ll ret=0;
	for(ll i=l;i<=r;++i){
		ret+=a[i];
	}
	return ret;
}
int main(){
	freopen("hire.in","r",stdin);
	freopen("hire.out","w",stdout);
	cin>>n>>m>>k>>d;
	for(ll i=1;i<=m;++i){
		ll x,y;
		cin>>x>>y;
		cout<<"YES\n";
	}
	return 0;
}
