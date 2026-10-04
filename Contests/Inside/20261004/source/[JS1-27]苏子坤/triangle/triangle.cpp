#include<bits/stdc++.h>
using namespace std;
int n,a[10][15][15];
int get(int id){
	int ret=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(a[id][i][j]!=a[7][i][j])ret++;
		}
	}
	return ret;
} 
int main(){
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>a[1][i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>a[7][i][j];
		}
	}
	for(int k=n;k>=1;k--){
		for(int i=1;i<=k;i++){
			a[2][k][i]=a[1][i+n-k][n-k+1];
		}
	}
	for(int k=n;k>=1;k--){
		for(int i=1;i<=k;i++){
			a[3][k][i]=a[2][i+n-k][n-k+1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			a[4][i][j]=a[1][i][i-j+1];
		}
	}
	for(int k=n;k>=1;k--){
		for(int i=1;i<=k;i++){
			a[5][k][i]=a[4][i+n-k][n-k+1];
		}
	}
	for(int k=n;k>=1;k--){
		for(int i=1;i<=k;i++){
			a[6][k][i]=a[5][i+n-k][n-k+1];
		}
	}
//	for(int k=1;k<=6;k++){
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=i;j++){
//				cout<<a[k][i][j]<<" ";
//			}
//			cout<<endl;
//		}
//	}
	cout<<min(min(min(get(1),get(2)),get(3)),min(min(get(4),get(5)),get(6)));
	return 0;
}
