//#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<list>
using namespace std;
constexpr const int N=1000,M=1000;
int n,m,a[N+1][M+1];
int query(int x,int y,int k){
	int ans=0;
	for(int i=m,j=m;k;k--){
		if(1<=i&&a[x][i]>=a[y][j]){
			ans=a[x][i];
			i--;
		}else{
			ans=a[y][j];
			j--;
		}
	}
	return ans;
}
void update(int x,int y){
	for(int i=m;1<=i;i--){
		if(a[x][i]<=y){
			a[x][i]=y;
			break;
		}
	}
}
int main(){
	freopen("familiar.in","r",stdin);
	freopen("familiar.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	while(q--){
		int op,x,y,k;
		cin>>op>>x>>y;
		switch(op){
			case 1:
				cin>>k;
				cout<<query(x,y,k)<<'\n';
				break;
			case 2:
				update(x,y);
				break;
		}
	}
	
	cout.flush();
	
	/*fclose(stdin);
	fclose(stdout);*/
	return 0;
}
