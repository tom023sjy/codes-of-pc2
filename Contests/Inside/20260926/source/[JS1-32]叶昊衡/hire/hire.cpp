#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int n,m,d,k,num[N];
signed main()
{
	freopen("hire.in","r",stdin);
	freopen("hire.out","w",stdout);
	cin>>n>>m>>k>>d;
	while(m--)
	{
		int x,y,idx=1,res=0,need;
		bool ok=1;
		cin>>x>>y;
		num[x]+=y;
		for(int i=1;i<=n-d;i++)
		{
			need=num[i];
			if(idx<i) idx=i,res=0;
			need-=k-res,idx++,res=0;
			if(need<=0) continue;
			int whole=need/k;
			res=need-whole*k;
			idx+=whole;
			if(idx>i+d+(res==0)){ok=0;break;}
		}
		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
