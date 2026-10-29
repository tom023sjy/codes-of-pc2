#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<random>
using namespace std;
mt19937 RAND(time(0));
int n;
int main()
{
	freopen("cup.in","w",stdout);
	n=RAND()%6+2;
	cout<<n<<endl;
	for (int i=1;i<=n;++i) cout<<RAND()%50+1<<' ';
	cout<<endl;
	return 0;
}
