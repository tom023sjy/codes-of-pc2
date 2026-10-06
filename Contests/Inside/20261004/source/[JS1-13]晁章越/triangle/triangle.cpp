#include<bits/stdc++.h>
#define florr(a,b,c) for(int a=(b);a<=(c);a++)
#define AC_AK return 0;
using namespace std;
inline int in(){
	char c=getchar();
	int f=1,k=0;
	for(;!isdigit(c);c=getchar()) f=(c=='-')?-1:1;
	for(;isdigit(c);c=getchar()) k=10*k+c-'0';
	return f*k;
}
inline void out(int x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else out(x/10),putchar(x%10+'0');
	return;
}
int n,ans=INT_MAX,a[11][11][7],b[11][11][7];
signed main(){
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	n=in();
	florr(i,1,n)
		florr(j,1,i) a[i][j][1]=in();
	florr(i,1,n)
		florr(j,1,i) b[i][j][1]=in();
	{
		florr(i,1,n)
			florr(j,1,i)
				a[i][j][2]=a[n-j+1][i-j+1][1];
		florr(i,1,n)
			florr(j,1,i)
				a[i][j][3]=a[n-j+1][i-j+1][2];	
	}
	{
		florr(i,1,n)
			florr(j,1,i)
				b[i][j][2]=b[n-j+1][i-j+1][1];
		florr(i,1,n)
			florr(j,1,i)
				b[i][j][3]=b[n-j+1][i-j+1][2];	
	}
	florr(i,1,n)
		florr(j,1,i) a[i][j][4]=a[i][i-j+1][1];
	florr(i,1,n)
		florr(j,1,i) b[i][j][4]=b[i][i-j+1][1];
	{
		florr(i,1,n)
			florr(j,1,i)
				a[i][j][5]=a[n-j+1][i-j+1][4];
		florr(i,1,n)
			florr(j,1,i)
				a[i][j][6]=a[n-j+1][i-j+1][5];	
	}
	{
		florr(i,1,n)
			florr(j,1,i)
				b[i][j][5]=b[n-j+1][i-j+1][4];
		florr(i,1,n)
			florr(j,1,i)
				b[i][j][6]=b[n-j+1][i-j+1][5];	
	}
//	florr(i,1,n){
//		florr(j,1,i) out(a[i][j][1]),putchar(' ');
//		putchar('\n');
//	}
//	florr(i,1,n){
//		florr(j,1,i) out(a[i][j][4]),putchar(' ');
//		putchar('\n');
//	}
	florr(i,1,6)
		florr(j,1,6){
			int tot=0;
			florr(s,1,n)
				florr(d,1,s) tot+=(a[s][d][i]!=b[s][d][j]);
			ans=min(ans,tot);
		}
	out(ans);
	AC_AK
}

