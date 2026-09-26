#include<bits/stdc++.h>
#define int __int128
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
constexpr int N=5e7+10;
int n,m,k,d,y,mp[N],a[N],idx=INT_MIN;
bool fl;
signed main(){
	freopen("sample1.in","r",stdin);
	
	
	
	freopen("hire.out","w",stdout);
	n=in(),m=in(),k=in(),d=in();
	for(int i=1;i<=m;i++){
		int nkn=in();
		mp[nkn]+=in(),idx=max(idx,nkn);
		for(int j=1;j<=n;j++) a[j]=0;
		for(int j=1;j<=idx;j++){
			fl=0,y=mp[j];
			if(!y) continue;
			for(int z=j;z<=j+d;z++){
				if(y<=k-a[z]){
					a[z]+=y,y=0;
					break;
				}
				y-=k-a[z],a[z]=k;
			}
			if(y>0){
				puts("NO"),fl=1;
				break;
			}
		}
		if(!fl) puts("YES");
	}
	return 0;
}
