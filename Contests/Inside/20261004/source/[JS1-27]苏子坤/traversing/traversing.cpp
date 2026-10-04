#include<bits/stdc++.h>
using namespace std;
int n,q,ans[100005],dfn=1;
bool flag=1;
struct node{
	int v,ls,rs;
}a[100005];
void dfs(int now){
	if(a[now].v==-1){
		ans[now]=dfn;
		dfn++;
		if(a[now].ls!=0)dfs(a[now].ls);
		if(a[now].rs!=0)dfs(a[now].rs);
	}
	if(a[now].v==0){
		if(a[now].ls!=0)dfs(a[now].ls);
		ans[now]=dfn;
		dfn++;
		if(a[now].rs!=0)dfs(a[now].rs);
	}
	if(a[now].v==1){
		if(a[now].ls!=0)dfs(a[now].ls);
		if(a[now].rs!=0)dfs(a[now].rs);
		ans[now]=dfn;
		dfn++;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("traversing.in","r",stdin);
	freopen("traversing.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].ls>>a[i].rs;
		if(a[i].ls!=0&&a[i].rs!=0)flag=0;
		a[i].v=-1;
	}
	dfs(1);
	bool need_update=0;
	while(q--){
		int op;
		cin>>op;
		if(op==1){
			int l,r,x;
			cin>>l>>r>>x;
			for(int i=l;i<=r;i++)a[i].v=x;
			if(!need_update)need_update=1;
		}
		if(op==2){
			if(need_update){
				need_update=1;
				dfn=1;
				dfs(1);
			}
			int t;
			cin>>t;
			cout<<ans[t]<<'\n';
		}
	}
	return 0;
}
