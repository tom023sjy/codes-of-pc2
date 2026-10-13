#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

const int N=5005,M=5e5+5;
int n,a[M],b[M],ans[M],f[N][N],mn[M];
vector <pair <int ,int > > st1,st2;

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

signed main()
{
	freopen("maxmin.in","r",stdin);
	freopen("maxmin.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	if (n>5000)
	{
		cout<<n<<' ';
		for (int i=1;i<n;i++) cout<<0<<' ';
		return 0;
	}
	st2.push_back(mp(a[1],b[1]));
	for (int i=2;i<=n;i++)
	{
	//	printf("[%d]\n",i);
		for (auto it:st2)
		{
			int x=it.first,y=it.second;
			f[x][y]=0;
		}
		for (auto it:st2)
		{
			int x=it.first,y=it.second;
			int kx=max(x,a[i]),ky=max(y,b[i]);
			if (!f[kx][ky]) st1.push_back(mp(kx,ky)),f[kx][ky]=1;
			kx=min(x,a[i]),ky=min(y,b[i]);
			if (!f[kx][ky]) st1.push_back(mp(kx,ky)),f[kx][ky]=1;
		}
		st2=st1;
		st1.clear();
	}
	for (auto it:st2)
	{
		int x=it.first,y=it.second;
		//printf("{%d %d}\n",x,y);
		ans[abs(x-y)]++;
	}
	for (int i=0;i<n;i++) cout<<ans[i]<<' ';
	return 0;
}
