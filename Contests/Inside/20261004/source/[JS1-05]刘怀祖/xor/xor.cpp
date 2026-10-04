#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int T,n;
char s[N],s1[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%s",&n,s+1);
		int fst1=0,cnt1=0,cnt0=0;
		int i=1;
		for(;i<=n&&s[i]=='0';i++);
		fst1=i;
		for(;i<=n&&s[i]=='1';i++)cnt1++;
		for(;i<=n&&s[i]=='0';i++)cnt0++;
		if(!cnt1)
		{
			printf("0\n");
			continue;
		}
		if(cnt1==n)
		{
			s[n]='0';
			printf("%s\n",s+1);
			continue;
		}
		if(!cnt0)
		{
			printf("%s\n",s+fst1);
			continue;
		}
		int d=min(cnt1,cnt0);
		for(int i=0;i<cnt1+d;i++)
		{
			s1[fst1+i]='1';
		}
		for(int i=fst1+cnt1+d;i<=n;i++)
		{
			s1[i]='0'+(s[i]!=s[i-d]);
		}
		s1[n+1]=0;
		printf("%s\n",s1+fst1);
	}
	return 0;
}
