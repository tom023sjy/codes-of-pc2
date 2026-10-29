#include<iostream>
#include<cstdio>
using namespace std;
int T=10000;
int main()
{
	while (T--)
	{
		system("./rd");
		system("./express");
		system("./ps");
		if (system("diff express.out express.ans"))
		{
			puts("WA");
			return 0;
		}
		else puts("AC");
	}
	return 0;
}
