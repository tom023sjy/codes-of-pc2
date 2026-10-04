#include <bits/stdc++.h>
using namespace std;

int t, n;
string s;

void dc() {
	string s2 = "";
	bool f = 1;
	for (char i: s) {
		if (f) {
			if (i == '1') {
				s2 += i;
				f = 0;
			} else n--;
		} else s2 += i;
	}
	int ocnt = 0, zcnt = 0;
	f = 1;
	for (char i: s2) {
		if (f) {
			if (i == '1') {
				ocnt++;
			} else {
				zcnt++;
				f = 0;
			}
		} else {
			if (i == '1') {
				break;
			} else {
				zcnt++;
			}
		}
	}
	int nuo = min(ocnt, n - 1), cai = min(n - 1, (ocnt > zcnt ? ocnt - zcnt: 0));
	string s3 = "";
	for (int i = 1; i <= nuo; i++) s3 += '0';
	for (int i = cai; i < n; i++) {
		s3 += s2[i];
		if (s3.size() == n) break;
	}
	string s4 = "";
	for (int i = 0; i < n; i++) {
		if (s2[i] == s3[i]) s4 += '0';
		else s4 += '1';
	}
	string s5 = "";
	f = 1;
	for (char i: s4) {
		if (f) {
			if (i == '1') {
				s5 += i;
				f = 0;
			}
		} else s5 += i;
	}
	if (s5.size() <= 0) s5 = "0";
	cout << s5 << '\n';
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		cin >> s;
		dc();
	}
	return 0;
}
