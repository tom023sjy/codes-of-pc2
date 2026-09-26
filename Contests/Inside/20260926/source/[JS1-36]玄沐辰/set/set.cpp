#include <bits/stdc++.h>
#define itn int //这样就不怕写错啦。 
using namespace std;
const long long MOD = 998244353;
long long n, ans = 1;

itn main()
{
	cin >> n;
	for (long long ii = 1; ii < (1 << n); ii++)
	{
		long long sum = 0, i = ii;
		for (long long j = 1; j <= n; j++)
		{
			if (i & 1)
			{
				sum += j;
			}
			i >>= 1;
		}
		ans = ans * sum % MOD;
	}
	cout << ans;
	return 0;
}
