#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n,m,idx,a[N],b[N];
void Solve()
{
	cin>>n>>m;
	idx=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	a[n+1]=-114514;
	for(int i=1;i<=m;i++) cin>>b[i];
	for(int i=1;i<=m;i++)
	{
		while(idx<=n&&a[idx]!=b[i]) idx++;
		if(idx>=n+1) {cout<<"No\n";return;}
		idx++;
	}
	cout<<"Yes\n";
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("minmax.in","r",stdin);
	freopen("minmax.out","w",stdout);
	cin>>t;
	while(t--) Solve();
}
