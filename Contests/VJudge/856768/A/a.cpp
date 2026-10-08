#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100;
int a[N + 5];
signed main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			if (a[i] - a[j] == k)
				return puts("Yes"), 0;
	return puts("No"), 0;	
} 
