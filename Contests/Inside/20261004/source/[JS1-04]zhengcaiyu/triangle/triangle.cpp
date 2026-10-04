#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=14;
int a[N][N][N],n,b[N][N];
inline int read()
{
	int sum=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum*f;
}
void change(int m)
{
	if(m<=0) return;
	for(int i=1;i<=m;++i) a[2][n-(n-m)/3][(n-m)/3+i]=a[1][(n-m)/3*2+i][(n-m)/3+1];
	for(int i=(n-m)/3+1,j=1;i<=(n-m)/3+m;++i,++j) a[2][n-(n-m)/3-j+1][(n-m)/3+m-j+1]=a[1][n-(n-m)/3][i];
	for(int i=1;i<=m;++i) a[2][i+(n-m)*2/3][(n-m)/3+1]=a[1][m+(n-m)/3*2-i+1][m+(n-m)/3-i+1];
	
	for(int i=1;i<=m;++i) a[3][n-(n-m)/3][(n-m)/3+i]=a[2][(n-m)/3*2+i][(n-m)/3+1];
	for(int i=(n-m)/3+1,j=1;i<=(n-m)/3+m;++i,++j) a[3][n-(n-m)/3-j+1][(n-m)/3+m-j+1]=a[2][n-(n-m)/3][i];
	for(int i=1;i<=m;++i) a[3][i+(n-m)*2/3][(n-m)/3+1]=a[2][m+(n-m)/3*2-i+1][m+(n-m)/3-i+1];
	
	change(m-3);
}
int main()
{
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	n=read();
	int ans=1e9;
	for(int i=1;i<=n;++i) for(int j=1;j<=i;++j) a[1][i][j]=read();
	for(int i=1;i<=n;++i) for(int j=1;j<=i;++j) b[i][j]=read();
	change(n);
	for(int i=1;i<=3;++i) for(int j=1;j<=n;++j) for(int k=1;k<=j;++k) a[i+3][j][k]=a[i][j][j-k+1];
	for(int i=1;i<=6;++i)
	{
		int sum=0;
		for(int j=1;j<=n;++j) for(int k=1;k<=j;++k) if(a[i][j][k]!=b[j][k]) ++sum;
		ans=min(ans,sum);
	}
	cout<<ans;
}
