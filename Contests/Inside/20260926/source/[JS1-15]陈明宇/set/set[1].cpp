#include <bits/stdc++.h>
#define ll unsigned __int128
#define mod 998244353

using namespace std;

ll f[40010], k[210], l[40010];
long long n;

ll qpow(ll a, ll b) {
	ll ans = 1;
	while (b != 0) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	freopen("set.in", "r", stdin);
	freopen("set.out", "w", stdout);
	
	cin >> n;
	
	ll len = 1;
	
	f[0] = f[1] = 1, k[1] = 1;
	
	for (ll i = 2; i <= n; i++) {
		k[i] = 1;
		for (ll j = 0; j <= len; j++) l[j] = f[j];
		for (ll j = 0; j <= len; j++) f[i + j] = (f[i + j] + l[j]) % (mod - 1);
		len += i;
		for (ll j = 1; j <= len; j++) k[i] = k[i] * qpow(j, f[j]) % mod;
	}
	
	
	cout << (long long) k[n];
	
	return 0;
}
 
