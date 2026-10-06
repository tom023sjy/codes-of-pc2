#include<bits/stdc++.h>
using namespace std;
int a[100][100],b[100][100],c[100][100];
int n;
void init(){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= i;j++){
			a[i][j] = c[i][j];
		}
	}
}
void turn(){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= i;j++){
			c[n - j + 1][i - j + 1] = a[i][j];
		}
	}
}
void turn_back(){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= i;j++){
			c[n - j + 1][n - i + 1] = a[i][j];
		}
	}
}
int chk(){
	int diff = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= i;j++){
			if(c[i][j] != b[i][j]) diff++;
		}
	}
	return diff;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= i;j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= i;j++){
			cin >> b[i][j];
		}
	}
	int ans = INT_MAX;
	for(int i = 1;i <= 2;i++){
		for(int j = 1;j <= 3;j++){
			turn();
			init();
			ans = min(ans,chk());
		}
		turn_back();
		init();
		ans = min(ans,chk());
	}
	cout << ans << '\n';
}
