#include <cstdio>
#include <algorithm>
#include <bitset>
using namespace std;
int read(){
	char c=getchar();int x=0;
	while(c<48||c>57) c=getchar();
	do x=(x<<1)+(x<<3)+(c^48),c=getchar();
	while(c>=48&&c<=57);
	return x;
}
const int N=2003;
int a[N];
bitset<25003> f,g;
int main(){
	freopen("cup.in","r",stdin);
	freopen("cup.out","w",stdout);
	int n=read();
	for(int i=0;i<n;++i) a[i]=read();
	sort(a,a+n);f.set(0);--n;
	for(int i=0;i<n;++i){g=f;for(int j=i+1;j<n;++j) if(a[j]>a[i]) f|=g<<(a[j]-a[i]);}
	for(int i=f._Find_first();i!=f.size();i=f._Find_next(i)) printf("%d ",i);
	putchar('\n');
	return 0;
}
