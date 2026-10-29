#include<iostream>
#include<cstdio>
#include<cassert>
#define N 400
using namespace std;
int gcd(int x,int y)
{
	if (y==0) return x;
	return gcd(y,x%y);
}
int n,s[N+1],F[N+1];
int main()
{
	for (int i=1;i<=N;++i)
		for (int j=1;j<=i;++j)
			if (gcd(i,j)==1)
				s[i]+=j;
	cout<<s[14]<<endl;
	return 0;
}
