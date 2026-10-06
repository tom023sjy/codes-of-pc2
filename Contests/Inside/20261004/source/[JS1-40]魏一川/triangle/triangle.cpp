#include<bits/stdc++.h>
using namespace std;
int n,ans=INT_MAX;
bool a[6][11][11],b[6][11][11];
int main(){
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)cin>>a[0][i][j];
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)cin>>b[0][i][j];
	
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)a[1][n-j+1][n-i+1]=a[0][i][j];
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)b[1][n-j+1][n-i+1]=b[0][i][j];
	for(int j=1;j<=n;j++)for(int i=j,k=n;i<k;i++,k--)swap(a[1][i][j],a[1][k][j]);
	for(int j=1;j<=n;j++)for(int i=j,k=n;i<k;i++,k--)swap(b[1][i][j],b[1][k][j]);
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)a[2][n-j+1][n-i+1]=a[1][i][j];
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)b[2][n-j+1][n-i+1]=b[1][i][j];
	for(int j=1;j<=n;j++)for(int i=j,k=n;i<k;i++,k--)swap(a[2][i][j],a[2][k][j]);
	for(int j=1;j<=n;j++)for(int i=j,k=n;i<k;i++,k--)swap(b[2][i][j],b[2][k][j]);
	
	for(int i=1;i<=n;i++)for(int j=1,k=i;j<=k;j++,k--)a[3][i][j]=a[0][i][k],a[3][i][k]=a[0][i][j];
	for(int i=1;i<=n;i++)for(int j=1,k=i;j<=k;j++,k--)a[4][i][j]=a[1][i][k],a[4][i][k]=a[1][i][j];
	for(int i=1;i<=n;i++)for(int j=1,k=i;j<=k;j++,k--)a[5][i][j]=a[2][i][k],a[5][i][k]=a[2][i][j];
	for(int i=1;i<=n;i++)for(int j=1,k=i;j<=k;j++,k--)b[3][i][j]=b[0][i][k],b[3][i][k]=b[0][i][j];
	for(int i=1;i<=n;i++)for(int j=1,k=i;j<=k;j++,k--)b[4][i][j]=b[1][i][k],b[4][i][k]=b[1][i][j];
	for(int i=1;i<=n;i++)for(int j=1,k=i;j<=k;j++,k--)b[5][i][j]=b[2][i][k],b[5][i][k]=b[2][i][j];
	
	for(int x=0;x<6;x++){
		for(int y=0;y<6;y++){
			int cnt=0;
			for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)if(a[x][i][j]!=b[y][i][j])cnt++;
			ans=min(ans,cnt);
		}
	}
	cout<<ans;
	return 0;
}
