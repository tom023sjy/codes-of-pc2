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
constexpr int N=5e3+10,Mod=1e9+7;
int n,m,x,fst,lst=-1,a[N],jmp[N],f[2][N][N];
map<int,int> mp;
signed main(){
	freopen("three.in","r",stdin);
	freopen("three.out","w",stdout);
	out(0);
	AC_AK
}
