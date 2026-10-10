#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	auto sd = chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count();
	mt19937 rnd(sd);
	const int N = 10;
	int T = 1;
	printf("%lld\n", T);
	while (T --) {
		int n = rnd() % (N - 1) + 2;
		int m = rnd() % n + 1;
		printf("%lld %lld\n", n, m);
	}
	return 0;
} 
