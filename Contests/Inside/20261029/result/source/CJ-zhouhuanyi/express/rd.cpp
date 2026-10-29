#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<random>
using namespace std;
mt19937 RAND(time(0));
int n;
int main()
{
	freopen("express.in","w",stdout);
	n=RAND()%10+1;
	cout<<n<<endl;
	for (int i=1;i<=n;++i) cout<<RAND()%1000000000+1<<' ';
	cout<<endl;
	return 0;
}
