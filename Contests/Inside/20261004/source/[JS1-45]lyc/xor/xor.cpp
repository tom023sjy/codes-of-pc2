#include<bits/stdc++.h>
using namespace std;
#define int long long
#define I return
#define am 0
#define gay ; 
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int _;
	cin>>_;	
	while(_--)
	{
		int n;	
		cin>>n;
		n--;
		string s1;
		cin>>s1;
		bool f0=0,f1=0;
		int i=0,j=0;
		for(i=0;i<n;i++)
		{
			
			if(s1[i]=='1'&&!f1)j=i;
			if(s1[i]=='1')f1=1;
			if(f1&&s1[i]=='0'){f0=1;break;}
		}
		string s2=s1;
		for(int i2=i;i2<=n;i2++)
		{
			s1[i2]=(s2[i2]-'0')^(s2[j+i2-i]-'0')+'0';
			//cout<<i2<<" "<<j+i2-i<<" "<<s1[i2]<<" "<<s2[i2]<<" "<<s2[i2+j-i]<<endl;
		}
		f0=0;
		for(i=0;i<=n;i++)
		{
			if(s1[i]=='0'&&s1[i+1]=='5')break;
			if(f0)cout<<s1[i];
			if(!f0&&s1[i]=='1')
			{
				cout<<1;f0=1;
			}
		}
		if(!f0)cout<<0;
		cout<<"\n";
	}
	I am gay 
}

