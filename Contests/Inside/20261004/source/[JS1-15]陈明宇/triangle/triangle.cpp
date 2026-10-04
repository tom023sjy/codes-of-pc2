#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<ll> > a, b;
ll n, ans = LLONG_MAX;

void rev(vector<vector<ll> > & m) {
	for (ll i = 1; i <= n; i++) {
		vector<ll> p = m[i];
		for (ll j = 1; j <= i; j++) m[i][j] = p[i - j + 1];
	}
}

void rot60(vector<vector<ll> > & m) {
	vector<vector<ll> > p = m;
	rev(p);
	for (ll j = n; j >= 1; j--)
		for (ll i = n; i >= j; i--)
			m[n - j + 1][n - i + 1] = p[i][j];
}

void checkAns(vector<vector<ll> > x, vector<vector<ll> > y) {
	ll cnt = 0;
	for (ll i = 1; i <= n; i++)
		for (ll j = 1; j <= i; j++) cnt += (x[i][j] ^ y[i][j]);
		
	ans = min(ans, cnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	freopen("triangle.in", "r", stdin);
	freopen("triangle.out", "w", stdout);

	cin >> n;
	
	a.assign(n + 1, vector<ll>()), b.assign(n + 1, vector<ll>());;
	
	for (ll i = 1; i <= n; i++) a[i].assign(n + 1, 0), b[i].assign(n + 1, 0);
	
	for (ll i = 1; i <= n; i++) 
		for (ll j = 1; j <= i; j++) cin >> a[i][j];
	
	for (ll i = 1; i <= n; i++) 
		for (ll j = 1; j <= i; j++) cin >> b[i][j];	
	
	checkAns(a, b);
	rot60(a);
	checkAns(a, b);
	rot60(a);
	checkAns(a, b);
	rot60(a);
	rev(a);
	checkAns(a, b);
	rot60(a);
	checkAns(a, b);
	rot60(a);
	checkAns(a, b);
	
	cout << ans;
	
	return 0;
}


