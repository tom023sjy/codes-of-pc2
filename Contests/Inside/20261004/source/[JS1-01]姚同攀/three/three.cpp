#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,m,a[N];
void solve1(){
	int res=1;
	for(int i=1;i<=m;++i)
		if(a[i]&&a[i+1]&&a[i+2]){
			int k=min({a[i],a[i+1],a[i+2]})/3*3;
			if((a[i]-k)%3==0&&(a[i+1]-k)%3==0&&(a[i+2]-k)%3==0) res+=k/3;
			else res=0;
			break;
		}
	printf("%d",res);
}
int main(){
	freopen("three.in","r",stdin);
	freopen("three.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;++i){
		scanf("%d",&x);
		++a[x];
	}
	int v=0;
	for(int i=1;i<=m;++i) if(a[i]) ++v;
	if(v==3){
		solve1();
		return 0;
	}
	for(int i=1;i<=n;++i){
		if(a[i]<0){
			printf("0");
			return 0;
		}
		int k=a[i]%3;
		a[i]-=k;a[i+1]-=k;a[i+2]-=k;
	}
	for(int i=1;i<=n;++i) a[i]/=3;
	
	printf("1");
	return 0;
}
