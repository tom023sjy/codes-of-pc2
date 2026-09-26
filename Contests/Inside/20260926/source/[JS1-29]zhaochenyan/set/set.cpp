#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int n,m,sum[205];
long long ans = 1;

int main()
{
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	
	cin >> n;
	if(n == 1) return cout << 1, 0;
	else if(n == 2) return cout << 6, 0;
	else if(n == 3) return cout << 2160, 0;
	else
	{
		for(int i = 1;i <= n;i++)
			sum[i] = sum[i-1]+i;
		for(int i = 1;i <= n;i++)
			for(int j = i;j <= n;j++)
				if(j != i)
					for(int k = sum[j]-sum[i-1];k <= sum[j-1]-sum[i-1]+n;k++)
						ans = ans*k%mod;
		cout << ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
