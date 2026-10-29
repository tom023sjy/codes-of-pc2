#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e7 + 10;
int t;
ll phi[maxn];
int v[maxn], prime[maxn], tot;
void init() {
	phi[1] = 1;
	for (int i = 2; i <= 1e7; i++) {
		if (!v[i]) prime[++tot] = i, phi[i] = i - 1;
		for (int j = 1; j <= tot; j++) {
			if ((ll)i * (ll)prime[j] > 1e7) break;
			v[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j]; break;
			}else {
				phi[i * prime[j]] = phi[i] * phi[prime[j]];
			}
		}
	} 
}
int main() {
	freopen("guess.in", "r", stdin);
	freopen("guess.out", "w", stdout);
	init();
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		ll x; scanf("%lld", &x);
		if (x == 1)  {
			cout << "1" << endl;	continue;
		}
		for (ll j = 2; j <= 1e7; j++) {
			ll t = phi[j] * j / 2;
			if (x == t) {
				printf("%d\n", j); break;
			}
		}
	}
	return 0;
}
