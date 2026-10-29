#include<bits/stdc++.h>
using namespace std;
const int maxn = 2010;
int n;
int h[maxn];
bitset <30010> dp, temp;
int main() {
	freopen("cup.in", "r", stdin);
	freopen("cup.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
	if (n <= 2) {
		cout << "0" << endl; return 0;
	}
	sort(h + 1, h + n + 1);
	dp.reset();
	dp.set(0, 1);
	for (int i = n; i >= 1; i--) {
		for (int j = i + 1; j < n; j++) {
			temp = temp | (dp << (h[j] - h[i]));
		}
		dp = dp | temp;
	}
	for (int i = 0; i <= 25000; i++) {
		if (dp[i]) printf("%d ", i);
	}
	printf("\n");
	return 0;
}
