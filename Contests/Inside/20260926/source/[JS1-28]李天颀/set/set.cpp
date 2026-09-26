#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
int ans=1;
map<int,int> mp;
int qpow(int a,int b){
	int res = 1;
	while(b){
		if(b&1){
			res *= a%MOD;
			res %= MOD;
		}
		a *= a%MOD;
		a %= MOD;
		b >>= 1;
	}
	return res%MOD;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	int n;
	cin>>n;
	if(n==1){
		cout<<1;
		return 0;
	}
	else if(n==2){
		cout<<6;
		return 0;
	}
	mp[1]++;
	mp[2]++;
	mp[3]++;
	for(int i=3;i<=n;i++){
		map<int,int> mpp;
		for(auto j:mp){
			mpp[j.first+i] = j.second;
		}
		for(auto j:mpp){
			mp[j.first] += j.second;
		}
		mp[i]++;
	}
//	for(auto i:mp) cout<<i.first<<" "<<i.second<<endl;
	for(auto i:mp){
		ans *= qpow(i.first,i.second)%MOD;
		ans %= MOD;
	}
	cout<<ans;
	return 0;
}
/*
1 1
2 1
3 1
4 1
5 1

														1
									       1     2   (1+2)
									1   2 (1+2) 3 (1+3) (2+3) (1+2+3)
1 2 (1+2) 3 (1+3) (2+3) (1+2+3) 4 (1+4) (2+4) (3+4)  (1+2+4) (1+3+4) (2+3+4) (1+2+3+4)
*/
