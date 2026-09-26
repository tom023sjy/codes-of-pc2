#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, m, k, d;

map<ll, ll> mp;

bool check() {
	ll l = 0, lst = 0;
	for (auto p : mp) {
		ll x = p.first, y = p.second;
		if (y == 0) continue;
		if (l >= x) {
			if (y >= lst) y -= k - lst, lst = k;
			else {
				y = 0, lst += y;
				continue;
			}
		}
		ll lou = ceil(1.0 * y / k);
		l = (l >= x ? l + lou : x + lou - 1);
		if (l > x + d) return false;
		lst = (y % k == 0 ? k : y % k);
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	freopen("hire.in", "r", stdin);
	freopen("hire.out", "w", stdout);

	cin >> n >> m >> k >> d;

	while (m--) {
		ll x, y;
		cin >> x >> y;
		mp[x] += y;
		if (check()) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}


