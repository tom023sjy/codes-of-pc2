#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n;
string st;
string xr(string s)
{
	int l=s.size();
	int k=0,sm=0,sm2=0,b=0;
	string s1;
	while(s[k]=='0'&&k<l) k++;
	if(k==l) return "0";
	for(int i=k;i<l;i++)
	{
		if(s[i]=='0') b=1,sm2++;
		else
		{
			if(b==0) sm++;
			else break;
		}
	}
	if(sm==l-k) 
	{
		for(int i=1;i<=l-k-1;i++) s1=s1+'1';
		if(k==0) s1=s1+'0';
		else s1=s1+'1';
	}
	else if(sm<=sm2)
	{
		for(int i=k;i<l;i++)
		{
			if(i-sm>=k)
			{
				if(s[i]==s[i-sm]) s1+='0';
				else s1+='1';
			}
			else s1+=s[i];
		}
	}
	else 
	{
		for(int i=k;i<l;i++)
		{
			if(i-sm>=k)
			{
				if(s[i]==s[i-sm2]) s1+='0';
				else s1+='1';
			}
			else s1+=s[i];
		}
	}
	return s1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>st;
		cout<<xr(st)<<'\n';
	}
	return 0;
}
