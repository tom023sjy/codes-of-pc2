#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int t,n,m,a[N],b[N];

inline int read ()
{
	int x=0,f=1;
	char c=getchar();
	while (c<'0'||c>'9')
	{
		if (c=='-') f=-f;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}

inline void write (int x)
{
	if (x>=10) write(x/10);
	putchar(char(x%10+'0'));
}

void solve ()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=m;i++) b[i]=read();
	int r=1;
	for (int i=1;i<=m;i++)
	{
		while (r<=n&&a[r]!=b[i]) r++;
		if (r>n) {cout<<"No\n";return ;}
		r++;
	}
	cout<<"Yes\n"; 
}

signed main()
{
	freopen("minmax.in","r",stdin);
	freopen("minmax.out","w",stdout);
	t=read();
	while (t--) solve();
	return 0;
}
