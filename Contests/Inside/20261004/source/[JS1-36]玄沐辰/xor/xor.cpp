#include <bits/stdc++.h>
using namespace std;
int t, n, sz;
int trie[9000010][2];
bitset<9000010> ed;
bitset<3010> s, ans;

void input(int &n)
{
	cin >> n;
}

void input(bitset<3010> b, int lenth)
{
	for (int i = 1; i <= lenth; i++)
	{
		char c;
		cin >> c;
		b[i] = c - '0';
	}
}

void output(int n, char c)
{
	cout << n << c;
}

void output(char c)
{
	cout << c;
}

void into_trie(bitset<3010> b, int len)
{
	int x = 0;
	for (int i = len; i > 0; i--)
	{
		if (trie[x][b[i]] == -1)
		{
			trie[x][b[i]] = ++sz;
		}
		x = trie[x][b[i]];
	}
	ed[x] = 1;
}

bitset<3010> sum (bitset<3010> b, int len)
{
	int x = 0;
	bitset<3010> ans;
	for (int i = len; i > 0; i--)
	{
		if (trie[x][!b[i]] == -1)
		{
			x = trie[x][b[i]];
		}
		else
		{
			ans[i] = 1;
			x = trie[x][!b[i]];
		}
	}
	return ans;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0ll), cout.tie(0ll);
	srand((unsigned) time (NULL));
	input(t);
	for (int i = 1; i <= t; i++)
	{
		input(n);
		memset(trie, -1, sizeof trie);
		ed ^= ed;
		ans ^= ans;
		input(s, n);
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j++)
			{
				bitset<3010> b = s << (3010-j-1) >> (3010-j-1+i-1);
				into_trie(b, n);
				bitset<3010> now = sum(b, n);
				for (int i = n; i > 0; i--)
				{
					if (now[i] > ans[i])
					{
						swap(now, ans);
						break;
					}
					if (now[i] < ans[i])
					{
						break;
					}
				}
			}
		}
		bool flag = 0;
		for (int i = n; i > 0; i--)
		{
			if (ans[i])
			{
				flag = 1;
			}
			if (flag)
			{
				cout << ans[i];
			}
		}
		output('\n');
	}
	return 0;
}
