#include <bits/stdc++.h>
using namespace std;
int a[20][20],n,b[20][20],c[20][20],ans=1e9;
void xz(){
	for(int i=1;i<=n;++i){for(int j=1;j<=i;++j) c[i][j]=a[i][j];}
	for(int i=1;i<=n;++i){for(int j=1;j<=i;++j){a[i][j]=c[n-i+j][n-i+1];}}
}
void dc(){for(int i=1;i<=n;++i){for(int j=1;j<=i/2;++j){swap(a[i][j],a[i][i-j+1]);}}}
int check(){
	int cnt=0;
	for(int i=1;i<=n;++i){for(int j=1;j<=i;++j) cnt+=(a[i][j]!=b[i][j]);}
	return cnt;
}
int main(){
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;++i){for(int j=1;j<=i;++j) cin>>a[i][j];}
	for(int i=1;i<=n;++i){for(int j=1;j<=i;++j) cin>>b[i][j];}
	xz();
	ans=min(ans,check());
	dc();
	ans=min(ans,check());
	xz();
	ans=min(ans,check());
	dc();
	ans=min(ans,check());
	xz();
	ans=min(ans,check());
	dc();
	ans=min(ans,check());
	cout<<ans;
	return 0;
}
