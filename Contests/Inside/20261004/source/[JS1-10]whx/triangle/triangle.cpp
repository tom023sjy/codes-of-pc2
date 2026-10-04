#include<bits/stdc++.h>
using namespace std;
int n,tot,a[110][110],b[110][110],c[110][110],sum,k=2,minn;
int main(){
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		tot++;
		for(int j=1;j<=tot;j++){
			cin>>a[i][j];
			c[i][j]=a[i][j];
		}
	}
	tot=0;
	for(int i=1;i<=n;i++){
		tot++;
		for(int j=1;j<=tot;j++){
			cin>>b[i][j];
			if(a[i][j]!=b[i][j]){
				minn++;
			}
		}
	}
	if(n==1){
		cout<<minn;
		return 0;
	}
	while(k){
		tot=0,sum=0;
		for(int i=1;i<=n;i++){
			a[i][1]=c[n][i];
			a[n][i]=c[n-i+1][n-i+1];
			a[n-i+1][n-i+1]=c[i][1];
		}
		if(n>=5){
			for(int i=3;i<n;i++){
				a[i][2]=c[n-1][i-1];
				a[n-1][i-1]=c[n-i+2][n-i+1];
				a[n-i+2][n-i+1]=c[i][2];
			}
		}
		if(n>=8){
			for(int i=5;i<n-1;i++){
				a[i][3]=c[n-2][i-2];
				a[n-2][i-2]=c[n-i+3][n-i+1];
				a[n-i+3][n-i+1]=c[i][3];
			}
		}
		for(int i=1;i<=n;i++){
			tot++;
			for(int j=1;j<=tot;j++){
				c[i][j]=a[i][j];
				if(a[i][j]!=b[i][j]){
					sum++;
				}
			}
		}
		minn=min(sum,minn);
		k--;
	}
	tot=0;
	for(int i=1;i<=n;i++){
		tot++;
		for(int j=1;j<=tot;j++){
			a[i][j]=c[i][tot-j+1];
		}
	}
	sum=0;tot=0;
	for(int i=1;i<=n;i++){
		tot++;
		for(int j=1;j<=tot;j++){
			c[i][j]=a[i][j];
			if(a[i][j]!=b[i][j]){
				sum++;
			}
		}
	}
	minn=min(sum,minn);
	k=2;
	while(k){
		tot=0,sum=0;
		for(int i=1;i<=n;i++){
			a[i][1]=c[n][i];
			a[n][i]=c[n-i+1][n-i+1];
			a[n-i+1][n-i+1]=c[i][1];
		}
		if(n>=5){
			for(int i=3;i<n;i++){
				a[i][2]=c[n-1][i-1];
				a[n-1][i-1]=c[n-i+2][n-i+1];
				a[n-i+2][n-i+1]=c[i][2];
			}
		}
		if(n>=8){
			for(int i=5;i<n-1;i++){
				a[i][3]=c[n-2][i-2];
				a[n-2][i-2]=c[n-i+3][n-i+1];
				a[n-i+3][n-i+1]=c[i][3];
			}
		}
		for(int i=1;i<=n;i++){
			tot++;
			for(int j=1;j<=tot;j++){
				c[i][j]=a[i][j];
				if(a[i][j]!=b[i][j]){
					sum++;
				}
			}
		}
		minn=min(sum,minn);
		k--;
	}
	cout<<minn<<'\n';
	
	return 0;
}
