#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
int sss[15][15];
int now[15][15],nxt[15][15],mi=INT_MAX;
void update1(){
	for(int ni=1,bj=1;bj<=n;ni++,bj++){
		for(int sj=bj,nj=1,si=n;sj>=1;nj++,sj--,si--){
			nxt[si][sj]=now[ni][nj];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			now[i][j]=nxt[i][j];
		}
	}
}
void update2(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i/2;j++){
			swap(now[i][j],now[i][i-j+1]);
		}
	}
}
void get(){
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			sum+=abs(now[i][j]-sss[i][j]);
		}
	}
	mi=min(mi,sum);
}
int main(){
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>now[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>sss[i][j];
		}
	}
	update1();
	get();
	update2();
	get();
	update2();
	update1();
	get();
	update2();
	get();
	update2();
	update1();
	get();
	update2();
	get();
	update2();
	cout<<mi;
	return 0;
}
