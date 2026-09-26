#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
int n;
map<int,int>mp[205];
int qpow(int a,int b){
	int ret=1;
	while(b){
		if(b&1){
			ret*=a%MOD;
			ret%=MOD;
		}
		a*=a%MOD;
		a%=MOD;
		b>>=1;
	}
	return ret;
}
signed main(){
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	mp[1][1]=1;
	cin>>n;
	for(int i=2;i<=n;i++){
		mp[i][i]++;
		for(auto j:mp[i-1]){
			mp[i][j.first]+=j.second;
			mp[i][i+j.first]+=j.second;
		}
	}
	int ans=1;
	for(auto i:mp[n]){
		ans*=qpow(i.first,i.second)%MOD;
		ans%=MOD;
	}
	cout<<ans;
	return 0;
}
