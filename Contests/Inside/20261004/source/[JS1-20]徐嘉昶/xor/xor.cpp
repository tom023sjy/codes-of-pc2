#include<bits/stdc++.h>
using namespace std;
const int N=1000007;
int n;
bitset<N> xxkan,xxkan2,chk;
string s;
bitset<N> jie(bitset<N> a,int l,int r)
{
	return (a<<(N-l-1))>>(N-(l-r+1));
}
bitset<N> maxbs(bitset<N> a,bitset<N> b)
{
	a^=b;
	if(jie(a,n,1).count()==0) return b;
	int l=n,r=1,mid=(l+r)>>1;
	while(l>r)
	{
		int kkkkk=jie(a,l,mid).count();
		if(kkkkk==0)
		{
			l=mid-1;
		}
		else if(kkkkk>=2)
		{
			r=mid+1;
		}
		else if(jie(a,mid,mid).count()==0)
		{
			r=mid+1;
		}
		else l=r=mid;
		mid=(l+r)>>1;
	}
	if(b[l])
	{
		return b;
	}
	else return a^b;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		cin>>s;
		int st1=0,st0=0;
		for(int i=0;i<n;i++)
		{
			xxkan[n-i]=(s[i]=='1');
		}
		for(int i=n;i>=1;i--)
		{
			if(xxkan[i]==1&&!st1) st1=i;
			if(xxkan[i]==0&&st1&&!st0)
			{
				st0=i;
				break;
			}
		}
		if(st1==0)
		{
			cout<<"0\n";
			continue;
		}
		if(st0==0&&st1==n)
		{
			for(int i=1;i<=n-1;i++) cout<<"1";
			cout<<"0\n";
			continue;
		}
		xxkan2=0;
		for(int i=n;i>=st0;i--)
		{
			if(xxkan[i])
			{
				chk=xxkan^((xxkan<<(N-i-1))>>(N-st0-1));
				xxkan2=maxbs(xxkan2,chk);
			}
		}
		bool f=0;
		for(int i=n;i>=1;i--)
		{
			if(f||xxkan2[i])
			{
				cout<<xxkan2[i];
				f=1;
			}
		}
		cout<<"\n";
	}
	return 0;
}
/*
1
5
10101

1
10
0011100110
*/
