#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int m, n;
int a[50010];

void input(int &n)
{
	cin >> n;
}

void output(int n, char c)
{
	cout << n << c;
}

void output(char c)
{
	cout << c;
}

int main()
{
	freopen("three.in", "r", stdin);
	freopen("three.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0ll), cout.tie(0ll);
	input(n), input(m);
	for (int i = 1; i <= n; i++)
	{
		int x;
		input(x);
		a[x]++;
	}
	int ans = 1;
	for (int i = 1; i <= m; i += 4)
	{
		int x = a[i], y = a[i+1], z = a[i+2], cnt = 0;
		for (int j = 1; j <= min(x, min(y, z)); j++)
		{
			if ((x - j) % 3 == 0 && (y - j) % 3 == 0 && (z - j) % 3 == 0)
			{
				cnt++;
			}
		}
		ans *= cnt;
	}
	output(ans, '\n');
	return 0;
}
