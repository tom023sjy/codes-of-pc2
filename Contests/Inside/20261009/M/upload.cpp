#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes return puts("YES"), 0
#define no return puts("NO"), 0
int a[4][4], x[4], y[4], z[4];
int solve() {
	for (int i = 1; i <= 3; i ++)
		for (int j = 1; j <= 3; j ++)
			cin >> a[i][j];
	memcpy(x, a[1], sizeof a[1]);
	memcpy(y, a[2], sizeof a[2]);
	memcpy(z, a[3], sizeof a[3]);
	do {
		do {
			do {
				if (x[1] == y[1] && x[2] == z[2] && x[3] == y[3] + z[3])
					yes;
			} while (next_permutation(z + 1, z + 4));
		} while (next_permutation(y + 1, y + 4));
	} while (next_permutation(x + 1, x + 4));

	memcpy(x, a[1], sizeof a[1]);
	memcpy(y, a[2], sizeof a[2]);
	memcpy(z, a[2], sizeof a[2]);
	do {
		do {
			do {
				if (x[1] == y[1] && x[2] == z[2] && x[3] == y[3] + z[3])
					yes;
			} while (next_permutation(z + 1, z + 4));
		} while (next_permutation(y + 1, y + 4));
	} while (next_permutation(x + 1, x + 4));
	memcpy(x, a[1], sizeof a[1]);
	memcpy(y, a[3], sizeof a[3]);
	memcpy(z, a[3], sizeof a[3]);
	do {
		do {
			do {
				if (x[1] == y[1] && x[2] == z[2] && x[3] == y[3] + z[3])
					yes;
			} while (next_permutation(z + 1, z + 4));
		} while (next_permutation(y + 1, y + 4));
	} while (next_permutation(x + 1, x + 4));
	
	no;
}

signed main() {
	int T;
	cin >> T;
	while (T --) 
		solve();
	return 0;
}
