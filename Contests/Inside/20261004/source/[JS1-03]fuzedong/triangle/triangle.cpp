#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
int a1[15][15],a2[15][15];
int check(){
	int res=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(a1[i][j]!=a2[i][j])res++;
		}
	}	
	return res;
}
void duicheng(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i/2;j++){
			swap(a1[i][j],a1[i][i-j+1]);
		}
	}
}
void xuanzhuan(){
	int tmp[15][15];
	for(int i=1;i<=n;i++){
		int diff=n-i;
		for(int j=1;j<=i;j++){
			tmp[i][j]=a1[n-j+1][n-j+1-diff];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			a1[i][j]=tmp[i][j];
		}
	}
}
void test(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<a1[i][j]<<' ';
		}
		cout<<'\n';
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
//	freopen("ex_triangle2.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>a1[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>a2[i][j];
		}
	}
	ans=check();
	for(int i=1;i<=2;i++){
		xuanzhuan();
		ans=min(ans,check());
		//test();
	}
	duicheng();
	//test();
	for(int i=1;i<=3;i++){
		xuanzhuan();
		ans=min(ans,check());
	}
	cout<<ans<<'\n';
	return 0;
}
