#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int T,n;
char s[N];
void solve(){
	scanf("%d%s",&n,&s);
	int p1=-1,p0=-1;
	for(int i=0;i<n;++i)
		if(s[i]=='1'){
			p1=i;
			break;
		}
	if(p1==-1){
		printf("0\n");
		return;
	}
	for(int i=p1+1;i<n;++i)
		if(s[i]=='0'){
			p0=i;
			break;
		}
	if(p0==-1){
		for(int i=p1;i<n-1;++i) printf("1");
		p1?printf("1\n"):printf("0\n");
		return;
	}
	int l=p0-1,r=p0;
	while(l>p1&&r<n-1&&s[r+1]=='0') --l,++r;
	for(int i=p1;i<=r;++i) printf("1");
	for(int i=r+1;i<n;++i) printf("%d",(s[i]-'0')^(s[p0+i-r-1]-'0'));
	printf("\n");
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
