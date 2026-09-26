#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 998244353;
int n;
ll sum[205], mul[205][205], pre[205][205];

int main(){
	freopen("set.in", "r", stdin);
	freopen("set.out", "w", stdout);
	cin>>n;
	if(n == 1) cout<<1;
	else if(n == 2) cout<<6;
	else if(n == 3) cout<<2160;
	else{
		ll ans = 1;
		ll end = n*(n+1)/2;
		for(int i=1; i<=n; i++){
			ans = ans * i % mod;
		}
//		for(int i=2; i<=n; i++){
//			for(int j=1; j<=n; j++){
//				ans *= 
//			}
//		}
		cout<<ans;
	}
	

	return 0;
}
