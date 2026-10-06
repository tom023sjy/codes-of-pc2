#include <bits/stdc++.h>
using namespace std;
int n,q,a,b,op,h,tot;
struct tree{
	int l,r,x;
}t[100010];
void dfs(int i){
	if(i==0) return;
	if(t[i].x==-1){
		tot++;
		if(i==h) cout<<tot<<endl;
		dfs(t[i].l);
		dfs(t[i].r);
	}
	else if(t[i].x==0){
		dfs(t[i].l);
		tot++;
		if(i==h) cout<<tot<<endl;
		dfs(t[i].r);
	}
	else{
		dfs(t[i].l);
		dfs(t[i].r);
		tot++;
		if(i==h) cout<<tot<<endl;
	}
}
int main(){
	freopen("traversing.in","r",stdin);
	freopen("traversing.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a>>b;
		t[i].l=a,t[i].r=b,t[i].x=-1;
	}
	while(q--){
		cin>>op;
		if(op==1){
			cin>>a>>b>>h;
			for(int i=a;i<=b;++i) t[i].x=h;
		}
		else{
			cin>>h;
			tot=0;
			dfs(1);
		}
	}
	return 0;
}
