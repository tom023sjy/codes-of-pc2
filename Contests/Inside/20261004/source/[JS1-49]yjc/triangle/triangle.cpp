#include<bits/stdc++.h>
using namespace std;
int a[15][15],b[15][15],c[15][15],dc[15][15],nc[15][15];
int n,ans=2e9;
int main(){
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			scanf("%d",&b[i][j]);
	int sum=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			if(a[i][j]!=b[i][j]) sum++;
	ans=min(ans,sum);
	sum=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			c[i][i-j+1]=a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			if(c[i][j]!=b[i][j]) sum++;
	ans=min(ans,sum);
	sum=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			c[n-j+1][i-j+1]=a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			if(c[i][j]!=b[i][j]) sum++;
	ans=min(ans,sum);sum=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dc[i][i-j+1]=c[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			if(dc[i][j]!=b[i][j]) sum++;
	ans=min(ans,sum);sum=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			nc[n-j+1][i-j+1]=c[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			if(nc[i][j]!=b[i][j]) sum++;
	ans=min(ans,sum);sum=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dc[i][i-j+1]=nc[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			if(dc[i][j]!=b[i][j]) sum++;
	ans=min(ans,sum);sum=0;
	printf("%d",ans);
}
	
	 
