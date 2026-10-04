#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,q,tot,root,lson[N],rson[N],a[N],b[N];
bool Root[N];
void tra(int u)
{
	if(u==0) return;
	if(a[u]==-1) b[u]=++tot,tra(lson[u]),tra(rson[u]);
	if(a[u]==0) tra(lson[u]),b[u]=++tot,tra(rson[u]);
	if(a[u]==1) tra(lson[u]),tra(rson[u]),b[u]=++tot;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("traversing.in","r",stdin);
	freopen("traversing.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>lson[i]>>rson[i],a[i]=-1;
	for(int i=1;i<=n;i++)
		Root[lson[i]]=Root[rson[i]]=1;
	for(int i=1;i<=n;i++)
		if(!Root[i]) root=i;
	while(q--)
	{
		int op,l,r,i,x;
		cin>>op;
		if(op==1)
		{
			cin>>l>>r>>x;
			for(int i=l;i<=r;i++) a[i]=x;
		}
		else
		{
			tot=0;
			tra(root);
			cin>>i;
			cout<<b[i]<<endl;
		}
	}
}
