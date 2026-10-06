#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5;
int T, n;
string s;

int main () {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	
	cin >> T;
	while (T --) {
		cin >> n;
		cin >> s;
		int fir1 = -1, fir2 = -1;
		if (s[0] == '1') fir1 = 0;
		for (int i = 1; i < n; i ++) {
			if (fir1 < 0 && s[i] == '1') fir1 = i;
			if (s[i] == '0' && s[i - 1] == '1') {
				fir2 = i;
				break;
			}
		}
		if (fir1 == -1) {
			cout << "0\n";
			continue;
		}
		if (fir2 == -1 && fir1 != 0) {
			for (int i = 0; i < n; i ++)
				if (s[i] == '1') cout << "1";
			cout << "\n";
			continue;
		}
		if (fir2 == -1 && fir1 == 0) {
			for (int i = 0; i < n - 1; i ++)
				cout << s[i];
			cout << "0\n";
			continue;
		}
		int _1 = fir2 - fir1;
		int _0 = 0;
		for (int i = fir2; i < n; i ++)
			if (s[i] == '1') break;
			else _0 ++;
		string ss = s;
		if (_0 >= _1) {
			for (int i = fir2; i < n; i ++)
				if (ss[i] == ss[fir1 + i - fir2]) s[i] = '0';
				else s[i] = '1';
			int f = 0;
			for (int i = 0; i < n; i ++) {
				if (s[i] == '1') f = 1;
				if (f) cout << s[i];
			}
			cout << "\n";
		}
		else {
			int k = fir2 - _0;
			for (int i = fir2; i < n; i ++)
				if (ss[i] == ss[k + i - fir2]) s[i] = '0';
				else s[i] = '1';
			int f = 0;
			for (int i = 0; i < n; i ++) {
				if (s[i] == '1') f = 1;
				if (f) cout << s[i];
			}
			cout << "\n";
		}
	}
	return 0;
}
