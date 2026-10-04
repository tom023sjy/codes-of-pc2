#include<bits/stdc++.h>
using namespace std;
#define liuyuchen return
#define is 0
#define genius ;
int n,q;
int fa[200010],lc[200010],rc[200010],a[200010],siz[200010];
int dfs(int x){
	if (x==1) return 1;
	int res=1,d=(lc[fa[x]]==x ? 1 : -1);
	if (a[x]==0) res+=siz[lc[x]];
	if (a[x]==1) res+=siz[x]-1;
	int f=0;
	if (d==1 && a[fa[x]]!=-1) f=1;
	if (d==-1 && a[fa[x]]==1) f=1;
	if (d==-1) res+=siz[lc[fa[x]]];
	if (!f) res+=dfs(fa[x]);
	return res;
}
void ddfs(int x){
	siz[x]=1;
	if (lc[x]) ddfs(lc[x]);
	if (rc[x]) ddfs(rc[x]);
	siz[x]+=siz[lc[x]]+siz[rc[x]];
}
int main(){
	freopen("traversing.in","r",stdin);
	freopen("traversing.out","w",stdout);
	memset(a,-1,sizeof a);
	cin>>n>>q;
	for (int i=1;i<=n;i++) {
		int l,r;
		cin>>l>>r;
		if (l) fa[l]=i,lc[i]=l;
		if (r) fa[r]=i,rc[i]=r;
	}
	ddfs(1);
	if (n<=5000) {
		while(q--){
			int op,l,r,x;
			cin>>op;
			if (op==1) {
				cin>>l>>r>>x;
				for (int i=l;i<=r;i++) a[i]=x;
			}else {
				cin>>x;
				cout<<dfs(x)<<"\n";
			}
		}
	}
	liuyuchen is genius
}
