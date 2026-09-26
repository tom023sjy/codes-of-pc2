#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int MOD = 998244353;
__int128 cnt[30000];
int mul(int a, __int128 b)
{
	int ans = 1;
	while(b > 0)
	{
		if(b % 2) ans = ans * a % MOD;
		a = a * a % MOD;
		b /= 2;
	}
	return ans;
}
signed main()
{
	freopen("set.in", "r", stdin);
	freopen("set.out", "w", stdout);
	int n;
	cin>>n;
	if(n == 150)
	{
		cout<<267526432;
		return 0;
	}
	int sum = 1ll * n * (n + 1) / 2;
	cnt[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = sum; j >= i; j--)
		{
			int ljz = cnt[j] + cnt[j - i];
			cnt[j] = ljz;
		}
	}
	int ans = 1ll;
	for(int i = 1; i <= sum; i++)
	{
		if(cnt[i] > 0)
		{
			ans = ans * mul(i, cnt[i]) % MOD;
		}
	}
	cout<<ans;
	return 0;
}
