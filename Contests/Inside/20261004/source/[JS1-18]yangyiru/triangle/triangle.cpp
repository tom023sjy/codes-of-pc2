#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int n;
int a[N][N], b[N][N];
int t[3][N][N];
int ans[7];

int main(){
	freopen("triangle.in", "r", stdin);
	freopen("triangle.out", "w", stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			cin>>a[i][j];
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			cin>>b[i][j];
			if(b[i][j] != a[i][j]) ans[1]++;
		}
	}
	for(int j=1; j<=n; j++){ //turn * 1
		for(int i=n; i>=n-j+1; i--){
			t[0][j][n-i+1] = a[i][j];
			if(b[j][n-i+1] != a[i][j]) ans[2]++;
		}
	}
	for(int j=n; j>=1; j--){ //turn * 2
		for(int i=n; i>=j; i--){
			t[1][n-j+1][n-i+1] = a[i][j];
			if(b[n-j+1][n-i+1] != a[i][j]) ans[3]++;
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=i; j>=1; j--){
			if(b[i][i-j+1] != a[i][j]) ans[4]++;
			if(b[i][i-j+1] != t[0][i][j]) ans[5]++;
			if(b[i][i-j+1] != t[1][i][j]) ans[6]++;
		}
	}
	int res = INT_MAX;
	for(int i=1; i<=6; i++) res = min(res, ans[i]);
	cout<<res;
	return 0;
}
