#include <bits/stdc++.h>
using namespace std;
int n,a[15][15],b[15][15],c[15][15],ans=0x3f3f3f3f;
void Rotate(){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			c[i][j]=a[i][j];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++){
			a[n-j+1][n-i+1]=c[i][j];
		}
}
void Flip(){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i/2;j++){
			swap(a[i][j],a[i][i-j+1]);
		}
}
int check(){
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			ans+=(b[i][j]^a[i][j]);
	return ans;
}
int main(){
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			cin>>a[i][j];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			cin>>b[i][j];
	ans=min(ans,check());
	Flip();
	ans=min(ans,check());
	Rotate();
	ans=min(ans,check());
	Flip();
	ans=min(ans,check());
	Rotate();
	ans=min(ans,check());
	Flip();
	ans=min(ans,check());
	cout<<ans;
	return 0;
}
