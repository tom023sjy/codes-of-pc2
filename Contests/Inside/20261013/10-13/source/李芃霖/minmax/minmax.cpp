#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld double
#define lc(k) st[k].lc
#define rc(k) st[k].rc
#define IM (int)1e9
#define LLM (ll)1e17
#define mids (nl+nr)>>1
#define hh putchar(10);
#define Re(x) qpow(x,mod-2)
#define set_it set<int>::iterator
#define pc(x) putchar(x)
#define mp(x,y) make_pair(x,y)
#define Re(x) qpow(x,mod-2)
const int N=2e5+50;
template<class T>
inline T read(){
	T x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f; 
}
template<class T>
inline void write(T ans){
	if(ans<0){putchar('-');write<T>(-ans);}
	else if(ans<10) putchar(ans+'0');
	else{write<T>(ans/10);putchar(ans%10+'0');}
	return ;
}
int a[N],b[N],ptr,n,m,T;
int main(){
	freopen("minmax.in","r",stdin);
	freopen("minmax.out","w",stdout);
	T=read<int>();
	while(T--){
		n=read<int>();m=read<int>();
		for(int i=1;i<=n;i++) a[i]=read<int>();
		for(int i=1;i<=m;i++) b[i]=read<int>();
		ptr=0;
		for(int i=1;i<=n;i++){
			if(ptr+1<=m&&b[ptr+1]==a[i]) ptr++;
		}
		if(ptr==m) puts("Yes");
		else puts("No");
	}
	return 0;
} 
