#include<iostream>
#include<cstdio>
using namespace std;
int T=10000;
int main()
{
	while (T--)
	{
		system("./rd");
		system("./cup");
		system("./ps");
		if (system("diff cup.out cup.ans"))
		{
			puts("WA");
			return 0;
		}
		else puts("AC");
	}
	return 0;
}
