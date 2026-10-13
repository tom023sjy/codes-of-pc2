#include <bits/stdc++.h>
using namespace std;
inline void read(int &a)
{
	int s=0,w=1;
	char ch=getchar();
	while (ch > '9' or ch < '0')
	{
		if (ch == '-')
		{
			w=-1;
		}
		ch=getchar();
	}
	while (ch >= '0' and ch <= '9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	a=s*w;
}
void write(int x)
{
	if (x < 0)
	{
		putchar('-');
		x=-x;
	}
	if (x > 9)
	{
		write(x/10);
	}
	putchar(x%10+'0');
	return;
}
bool dp[2][5005][5005];
int ans[5005],a[5005],b[5005];
int main()
{
	freopen("maxmin.in","r",stdin);
	freopen("maxmin.out","w",stdout);
	int n;
	read(n);
	bool ta=1;
	for (int i = 1;i <= n;i++)
	{
		read(a[i]);
	}
	for (int i = 1;i <= n;i++)
	{
		read(b[i]);
		if (b[i] != a[i])
		{
			ta=0;
		}
	}
	if (ta)
	{
		write(n);
		putchar(' ');
		for (int i = 1;i <= n-1;i++)
		{
			write(0);
			putchar(' ');
		}
		return 0;
	}
	int c=1;
	dp[1][a[1]][b[1]]=1;
	for (int i = 2;i <= n;i++)
	{
		c=!c;
		for (int x = 1;x <= n;x++)
		{
			for (int y = 1;y <= n;y++)
			{
				if (a[i] > x and b[i] > y)
				{
					dp[c][x][y]=dp[!c][x][y];
				}
				else if (a[i] < x and b[i] < y)
				{
					dp[c][x][y]=dp[!c][x][y];
				}
				else if ((a[i] < x and b[i] > y) or (a[i] > x and b[i] < y))
				{
					dp[c][x][y]=0;
				}
				else if (a[i] == x and b[i] > y)
				{
					for (int f = a[i];f <= n;f++)
					{
						dp[c][x][y]|=dp[!c][f][y];
					}
				}
				else if (a[i] == x and b[i] < y)
				{
					for (int f = 1;f <= a[i];f++)
					{
						dp[c][x][y]|=dp[!c][f][y];
					}
				}
				else if (a[i] < x and b[i] == y)
				{
					for (int f = 1;f <= b[i];f++)
					{
						dp[c][x][y]|=dp[!c][x][f];
					}
				}
				else if (a[i] > x and b[i] == y)
				{
					for (int f = b[i];f <= n;f++)
					{
						dp[c][x][y]|=dp[!c][x][f];
					}
				}
				else
				{
					for (int fx=1;fx <= a[i];fx++)
					{
						for (int fy=1;fy <= b[i];fy++)
						{
							dp[c][x][y]|=dp[!c][fx][fy];
						}
					}
					for (int fx=a[i];fx <= n;fx++)
					{
						for (int fy=b[i];fy <= n;fy++)
						{
							dp[c][x][y]|=dp[!c][fx][fy];
						}
					}
				}
			}
		}
	}
	for (int x=1;x <= n;x++)
	{
		for (int y = 1;y <= n;y++)
		{
			ans[abs(x-y)]+=dp[c][x][y];
		}
	}
	for (int i = 0;i <= n-1;i++)
	{
		write(ans[i]);
		putchar(' ');
	}
	return 0;
}
