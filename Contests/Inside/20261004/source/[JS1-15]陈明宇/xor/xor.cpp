#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll t, n, maxx, maxi;
string s, s1, p;

int nxt[10000010];

string rev(string x) {
	string v;
	for (char c : x) v += (c == '0' ? '1' : '0');
	return v;
}

void getNext(string x, ll sz) {
	for (ll i = 0; i < sz; i++) nxt[i] = 0;
	for (ll i = 1; i < sz; i++) {
		int j = nxt[i];
		while (j != 0 && x[j] != x[i]) j = nxt[j];
		if (x[i] == x[j]) nxt[i + 1] = j + 1;
		else nxt[i + 1] = 0;
	}
}

void kmp(string x, string y) {
	ll a = x.size(), b = y.size();
	getNext(y, b);
	int j = 0;
	for (ll i = 0; i < a; i++) {
		while (j != 0 && x[i] != y[j]) j = nxt[j];
		if (x[i] == y[j]) {
			if (j + 1 > maxx && i - j + b <= a) maxx = j + 1, maxi = i - j;
			j++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	cin >> t;
	
	while (t--) {
		cin >> n >> s1;
		s = "";
		maxx = -1, maxi = n - 1;
		bool flag = false;
		for (ll i = 0; i < s1.size(); i++) {
			char c = s1[i];
			if (c == '0') {
				if (flag) s += c;
			} else s += c, flag = true;
		}
		if (s == "") s = "0";
		n = s.size();
		string p1 = rev(s);
		flag = false;
		p = "";
		for (char c : p1) {
			if (c == '0') {
				if (flag) p += c;
			} else p += c, flag = true;
		}
		if (p == "") p = "0";
		kmp(s1, p);
		string ans = s, pp;
		if (maxx == -1) maxx = 1;
		for (ll i = maxi; i < maxi + p.size(); i++) pp += s1[i];
		reverse(ans.begin(), ans.end());
		reverse(pp.begin(), pp.end());
		for (ll i = 0; i < pp.size(); i++) ans[i] = (ans[i] == pp[i] ? '0' : '1');
		reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}
	
	return 0;
}


