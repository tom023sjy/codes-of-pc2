#include <bits/stdc++.h>
using namespace std;
int a[20][20],b[20][20],n,c[20][20],aw=2147483647;
void t(){
	for(int k=1;k<=3;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				c[j+(n-i)][n-i+1]=a[i][j];
			}
		}
		int h=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				a[i][j]=c[i][j];
				h+=abs(a[i][j]-b[i][j]);
	//			cout<<a[i][j]<<' ';
			}
	//		cout<<'\n';
		}
		aw=min(aw,h);
	}
}
int main(){
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>b[i][j];
		}
	}
	t();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			c[i][i-j+1]=a[i][j];
		}
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			a[i][j]=c[i][j];
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=i;j++){
//			cout<<a[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	t();
	cout<<aw;
	return 0;
}
