// xor Auther T_cat
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e7 + 7;
const int MAXM = 3e1 + 7;
int t, n, a, b, Max;
char op;
bitset<MAXN> bit;
void print(int x) {
	int pos = 0;
	int out[MAXM];
	bool flag = 1;
	while (x) {
		pos++;
		out[pos] = x % 2;
 	    x /= 2;
	}
	for (int i = pos; i >= 1; i--) cout << out[i];
	if (pos == 0) cout << 0;
	cout << endl;
	return;
}
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> t;
	while (t--) {
		bit.reset();
		Max = -1;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> op;
			if (op - '0' == 1) bit.set(i);
		}
		for (int i = 1; i <= n; i++) {
			a = 0;
			for (int j = i; j >= 1; j--) {
				if (bit[j]) a += (1 << (i - j));
				for (int l = 1; l <= n; l++) {
					b = 0;
					for (int r = l; r >= 1; r--) {
						if (bit[r]) b += (1 << (l - r));
						int tmp = a ^ b;
						Max = max(Max, tmp);
					}
				}
			}
		}
		print(Max);
	}
	return 0;
}
