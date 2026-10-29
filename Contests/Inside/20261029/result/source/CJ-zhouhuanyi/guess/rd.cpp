#include<iostream>
#include<cstdio>
#include<cassert>
#define N 5000
using namespace std;
int gcd(int x,int y)
{
	if (y==0) return x;
	return gcd(y,x%y);
}
int n,s[N+1],F[N+1];
int main()
{
	freopen("guess.in","w",stdout);
	for (int i=1;i<=N;++i)
		for (int j=1;j<=i;++j)
			if (gcd(i,j)==1)
				s[i]+=j;
	cout<<N-2<<endl;
	for (int i=3;i<=N;++i) cout<<s[i]<<endl;
	return 0;
}
