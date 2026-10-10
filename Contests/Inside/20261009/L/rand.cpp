#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	auto sd = chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count();
    mt19937 rnd(sd);
	int T = 6;
    cout << T << endl;
    while (T --) {
        int K = 6;
        cout << rnd() % K + 1 << " " << rnd() % K + 1 << endl;
    }
	return 0;
}