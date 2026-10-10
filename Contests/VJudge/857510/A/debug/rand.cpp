#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	auto sd = chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count();
	mt19937 rnd(sd);
	printf("0\n");
	const int t = 5;
	int T = rnd() % t + 1;
	cout << T << endl;
	const int N = 100;
	while (T --) {
		int sz = rnd() % N + 1;
		while (sz --)
			printf("%lld", rnd() % 9 + 1);
		printf("\n");
		for (int i = 1; i <= 9; i ++)
			printf("%lld ", rnd() % N + 1);
		printf("\n");
	}
	return 0;
} 
