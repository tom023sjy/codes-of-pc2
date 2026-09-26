#include<bits/stdc++.h>
using namespace std;
#define ls p<<1
#define rs p<<1|1
#define mid (pl+pr)>>1
int n,m,k,d;
long long a[500050],q[500050],t[500050];
int main()
{
	freopen("hire.in","r",stdin);
	freopen("hire.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k>>d;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=n;j++) t[j]=1e18,q[j]=0;
		int x,y;
		cin>>x>>y;
		a[x]+=y;
		int c=0,nw=0;
		bool f=0;
		for(int j=1;j<=n;j++)
		{
			if(j-t[nw]>d)
			{
				cout<<"NO\n";
				f=1;
				break;
			}
			int p=k;
			while(p>=q[nw]&&nw<=c+1)
			{
				p-=q[nw],nw++;
			}
			nw=min(nw,c+1);
			if(q[nw]>p) 
			{
				q[nw]-=p;
				p=0;
			}
			if(a[j]>p)
			{
				t[++c]=j;
				q[c]=a[j]-p;
			}
		}
		if(f==0) 
		{
			if(q[nw]>0) cout<<"NO\n";
			else cout<<"YES\n";
		}
	}
	return 0;
}
