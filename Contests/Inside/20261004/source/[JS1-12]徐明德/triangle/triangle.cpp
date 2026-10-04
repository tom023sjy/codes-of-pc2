//triangle
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ans;
bool a[11][11],b[11][11],c[11][11];
inline void turn(){
	for(int x=1,y=1,z=n;z>0;x+=2,y++,z-=3){
		for(int k=1;k<=z-1;k++){
			c[x+k][y+k]=a[x+z-1-k][y];
			c[x+z-1-k][y]=a[x+z-1][y+z-1-k];
			c[x+z-1][y+z-1-k]=a[x+k][y+k];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			a[i][j]=c[i][j];
		}
	}
}
inline void dc(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			c[i][j]=a[n-j+1][n-i+1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			a[i][j]=c[i][j];
		}
	}
}
inline int check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(a[i][j]!=b[i][j])cnt++;
		}
	}
	return cnt;
}
int main(){
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	//ios::sync_with_stdio(0);
	//cin.tie(0);cout.tie(0);
	cin>>n;
	ans=(1+n)*n/2;
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
	for(int i=1;i<=3;i++){
		turn();
		dc();
		ans=min(ans,check());
		dc();
		ans=min(ans,check());
	}
	cout<<ans;
	return 0;
}
/*
4
0
1 0
0 0 1
1 1 0 0
0
0 1
0 0 0
0 1 1 1
*/
