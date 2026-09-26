#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, K, D;
int A[500005], B[500005];

bool Check() {
	for(int i = 1; i <= n; i++) B[i] = K;
	for(int i = 1; i <= n - D; i++) {
		int sum = 0;
		for(int j = i; j <= i + D; j++) {
			sum += B[j];  B[j] = 0;
			if(sum > A[i]) { B[j] += sum - A[i];  break; }
		}
		if(sum < A[i]) return false;
	}
	return true;
}

signed main() {
	freopen("hire.in", "r", stdin);
	freopen("hire.out", "w", stdout);
	
	scanf("%lld %lld %lld %lld", &n, &m, &K, &D);
	while(m--) {
		int x, y;  scanf("%lld %lld", &x, &y);  A[x] += y;
		if(Check()) printf("YES\n");
		else printf("NO\n"); 
	}
	return 0;
}
