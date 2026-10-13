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
int a[100005],b[100005];
int main()
{
	freopen("minmax.in","r",stdin);
	freopen("minmax.out","w",stdout);
	int T,n,m;
	read(T);
	for (int chtholly = 1;chtholly <= T;chtholly++)
	{
		read(n),read(m);
		for (int i = 1;i <= n;i++)
		{
			read(a[i]);
		}
		for (int i = 1;i <= m;i++)
		{
			read(b[i]);
		}
		if (m > n)
		{
			puts("No");
			continue;
		}
		int posa=1,cnt=0;
		for (int i = 1;i <= m;i++)
		{
			while (a[posa] != b[i] and posa <= n)
			{
				posa++;
			}
			if (posa > n)
			{
				break;
			}
			cnt++;
			posa++;
		}
		if (posa > n and cnt < m)
		{
			puts("No");
		}
		else
		{
			puts("Yes");
		}
	}
	return 0;
}
