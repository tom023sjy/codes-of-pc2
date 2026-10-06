#include<bits/stdc++.h>
using namespace std;
int n,res,ans=INT_MAX,a[15][15],b[15][15],c[15][15];
void xz(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			c[i][j]=a[n-i+j][n-i+1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			a[i][j]=c[i][j];
}
void solve(){
	res=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			res+=abs(a[i][j]-b[i][j]);
	ans=min(ans,res);
	res=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			res+=abs(a[i][i-j+1]-b[i][j]);
	ans=min(ans,res);
}
int main(){
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			cin>>b[i][j];
	solve();
	xz();	
	solve();
	xz();
	solve();
	cout<<ans;
	return 0;
}
