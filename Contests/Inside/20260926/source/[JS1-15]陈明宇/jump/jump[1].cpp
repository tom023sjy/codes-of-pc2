#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

ll n, k, ans;
string s = " ", s1;

map<string, bool> mp;

void dfs(string x) {
	if (!mp[x]) ans++, ans %= mod, mp[x] = true;
	else return;
	for (ll i = 1; i <= n; i++) {
		if (x[i] != '1') continue;
		if (i > 2)
			if (x[i - 1] == '1' && x[i - 2] == '0') {
				string x1 = x;
				x1[i] = '0', x1[i - 2] = '1';
				dfs(x1);
			}
		if (i <= n - 2)
			if (x[i + 1] == '1' && x[i + 2] == '0') {
				string x1 = x;
				x1[i] = '0', x1[i + 2] = '1';
				dfs(x1);
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	freopen("jump.in", "r", stdin);
	freopen("jump.out", "w", stdout);

	cin >> n >> s1;
	
	s += s1;

	for (ll i = 1; i <= n; i++) if (s[i] == '?') k++;
	
	for (ll i = 0; i < (1ll << k); i++) {
		ll idx = 0;
		string ss = s;
		for (ll j = 1; j <= n; j++) {
			if (s[j] == '?') {
				if ((i >> idx) & 1) ss[j] = '1';
				else ss[j] = '0';
				idx++;
			}
		}
		mp.clear();
		dfs(ss);
	}

	cout << ans;

	return 0;
}


