#include<iostream>
#include<cstdio>
#include<cassert>
using namespace std;
int x,cnt=2;
int main()
{
	freopen("guess.out","r",stdin);
	while (cin>>x) assert(x==(++cnt));
	return 0;
}
