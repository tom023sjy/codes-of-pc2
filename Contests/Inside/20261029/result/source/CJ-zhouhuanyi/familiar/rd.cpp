#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<random>
using namespace std;
mt19937 RAND(time(0));
int n=1000,m=1000,T=1000000,maxn=1000000000;
int main()
{
	freopen("familiar.in","w",stdout);
	int x,y;
	cout<<n<<' '<<m<<' '<<T<<endl;
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=m;++j) cout<<RAND()%maxn+1<<' ';
		cout<<endl;
	}
	while (T--)
	{
		x=y=1;
		if (x==y) x=RAND()%n+1,y=RAND()%n+1;
		cout<<1<<' '<<x<<' '<<y<<' '<<RAND()%(m<<1)+1<<endl;
	}
	return 0;
}
