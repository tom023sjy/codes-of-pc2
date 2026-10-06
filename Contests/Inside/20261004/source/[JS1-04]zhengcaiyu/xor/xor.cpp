#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum*f;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int T=read();
	while(T--)
	{
		string s,ss;
		int n=read();
		cin>>s;
		int i=0,cnt=0;
		while(i<n&&s[i]=='0') ++i;
		if(i==n)
		{
			printf("0\n");
			continue;
		}
		for(;i<n-1&&s[i]=='1';++i,++cnt) ss+='1';
		if(i==n-1)
		{
			if(s[i-1]=='1')
			{
				if(s[i]=='0') ss+='1';
				else ss+='0';
			}
			else
			{
				if(s[i]=='0') ss+='0';
				else ss+='1';
			}
			cout<<ss<<'\n';
		}
		else
		{
			int j=1;
			for(;j<=cnt;++j)
			{
				if(s[j+i-1]!='0') break;
				ss+='1';
			}
			for(;j+i-1<n;++i) ss+=((s[j+i-1]-'0')^(s[i]-'0'))+'0';
			cout<<ss<<'\n';
		}
	}
}
