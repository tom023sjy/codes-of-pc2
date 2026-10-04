#include<bits/stdc++.h>
using namespace std;
int n,q,sx,sh[100005];
struct tree{int ls,rs,val;}a[100005];
void bianli(int u,int x){
	if(a[u].val==-1){
		sx++;sh[u]=sx;
		if(a[u].ls) bianli(a[u].ls,x);
		if(a[u].rs) bianli(a[u].rs,x);
	}
	if(a[u].val==0){
		if(a[u].ls) bianli(a[u].ls,x);
		sx++;sh[u]=sx;
		if(a[u].rs) bianli(a[u].rs,x);
	}
	if(a[u].val==1){
		if(a[u].ls) bianli(a[u].ls,x);
		if(a[u].rs) bianli(a[u].rs,x);
		sx++;sh[u]=sx;
	}
}
int main(){
	freopen("traversing.in","r",stdin);
	freopen("traversing.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].ls,&a[i].rs);
		a[i].val=-1;
	}
	int opt,l,r,x;
	while(q--){
		cin>>opt;
		if(opt==1){
			scanf("%d%d%d",&l,&r,&x);
			for(int i=l;i<=r;i++)
				a[i].val=x;
		}
		else{
			for(int i=1;i<=n;i++) sh[i]=0;
			scanf("%d",&x);
			sx=0;bianli(1,x);
			printf("%d\n",sh[x]);
		}
	}
	return 0;
}
