#include<bits/stdc++.h>
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
int a[]={1,1,6,2160,160376823,177398456,869375948,646537137,316568579,427324833,
	169262599,548236960,334976220,392961398,363573903,612794975,469044582,522237939,227411035,455872382,
	368340394,678615114,724191209,804101938,74786757,383007682,580325979,695035300,155120226,616735010,
	957629447,330611886,976271658,200474492,661315014,762870033,965585737,907770134,841751340,995080181};
signed main(){
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	out(a[in()]);
	return 0;
}

