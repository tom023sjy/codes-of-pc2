#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,a[N][N],b[N][N],c[N][N],ans=2e9;
void cnt(){
	int cur=0;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=i;++j)
		cur+=(a[i][j]^b[i][j]);
	ans=min(ans,cur);
}
void op1(){
	for(int i=1;i<=n;++i)
	for(int j=1;j<=i;++j)
		c[n-j+1][i-j+1]=b[i][j];
	for(int i=1;i<=n;++i)
	for(int j=1;j<=i;++j)
		b[i][j]=c[i][j];
}
void op2(){
	for(int i=1;i<=n;++i)
	for(int j=1;j<=i/2;++j)
		swap(b[i][j],b[i][i-j+1]);
}
int main(){
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	for(int j=1;j<=i;++j)
		scanf("%d",&a[i][j]);
	for(int i=1;i<=n;++i)
	for(int j=1;j<=i;++j)
		scanf("%d",&b[i][j]);
	for(int i=1;i<=3;++i){
		cnt();
		op2();cnt();op2();
		op1();
	}
	printf("%d",ans);
	return 0;
}
