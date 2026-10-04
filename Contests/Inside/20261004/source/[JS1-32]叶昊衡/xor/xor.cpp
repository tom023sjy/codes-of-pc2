#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
string s;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		int idx=-1,None=s.find("@");
		bool all1=1;
		string now="",want,S="",ans="";
		for(int i=0;i<n;i++)
			if(s[i]=='1') {idx=i;break;}
		if(idx==-1) {cout<<0<<'\n';continue;}
		if(idx==n-1) {cout<<1<<'\n';continue;}
		for(int i=0;i<n;i++)
			if(s[i]!='1') {all1=0;break;}
		if(all1)
		{
			for(int i=1;i<n;i++) cout<<1;
			cout<<0<<'\n';
			continue;
		}
		for(int i=idx;i<n;i++)
		{
			char need='0'+!(s[i]-'0');
			if(now==""&&need=='0') continue;
			want=now+need;
			int Now=s.find(want);
			if(Now!=None&&Now<=i) now=want;
			else now+=s[i];
		}
		for(int i=idx;i<n;i++) S+=s[i];
		while(now.size()<S.size()) now='0'+now;
		for(int i=0;i<S.size();i++)
		{
			if(S[i]!=now[i]) ans+='1';
			else ans+='0';
		}
		cout<<ans<<'\n';
	}
}
