#include<bits/stdc++.h>
using namespace std;
vector<int> mp[100005];
int n,q,cnt;
int val[100005],num[100005];
void search(int u)
{
	if(val[u]==-1)
	{
		num[u]=++cnt;
		if(mp[u][0]!=0) search(mp[u][0]);
		if(mp[u][1]!=0) search(mp[u][1]);
	}
	else if(val[u]==0)
	{
		if(mp[u][0]!=0) search(mp[u][0]);
		num[u]=++cnt;
		if(mp[u][1]!=0) search(mp[u][1]);
	}
	else if(val[u]==1)
	{
		if(mp[u][0]!=0) search(mp[u][0]);
		if(mp[u][1]!=0) search(mp[u][1]);
		num[u]=++cnt;
	}
}
int main()
{
	freopen("traversing.in","r",stdin);
	freopen("traversing.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		val[i]=-1;
		int l,r;
		cin>>l>>r;
		mp[i].push_back(l);
		mp[i].push_back(r);
	}
	bool f=0;
	while(q--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int l,r,x;
			cin>>l>>r>>x;
			for(int i=l;i<=r;i++)
			{
				val[i]=x;
			}
			f=0;
		}
		else
		{
			int p;
			cin>>p;
			if(!f)
			{
				cnt=0;
				search(1);
				f=1;
			}
			cout<<num[p]<<"\n";
		}
	}
	return 0;
}
