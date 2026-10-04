#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("three.in", "r", stdin);
	freopen("three.out", "w", stdout);
	int a[4];
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	sort(a + 1, a + 3);
	if (a[1] == a[2] && a[2] == a[3]) cout << 1;
	else if (a[2] - a[1] == 1 && a[3] - a[2] == 1) cout << 1;
	else cout << 0;
	return 0;
}
