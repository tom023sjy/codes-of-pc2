#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls p<<1
#define rs p<<1|1
#define mid (l+r>>1)
const int N=1e5+5;
int n,q;
int L[N],R[N];
int ans[N],tot;
int num[N<<2],tag[N<<2];
void build(int l,int r,int p){
	tag[p]=2;
	if(l==r){
		num[p]=-1;
		return;
	}
	build(l,mid,ls);
	build(mid+1,r,rs);
}
void down(int l,int r,int p){
	if(tag[p]!=2){
		if(l==r){
			num[p]=tag[p];
			return;
		}
		tag[ls]=tag[p];
		tag[rs]=tag[p];
		tag[p]=2;
	}
}
void update(int ql,int qr,int v,int l,int r,int p){
	if(ql<=l&&r<=qr){
		tag[p]=v;
		return;
	}
	down(l,r,p);
	if(ql<=mid)update(ql,qr,v,l,mid,ls);
	if(mid<qr)update(ql,qr,v,mid+1,r,rs);
}
int query(int x,int l,int r,int p){
	down(l,r,p);
	if(l==r){
		//cout<<"I found "<<l<<"!\nAnd it's num&tag is "<<num[p]<<' '<<tag[p]<<'\n';
		return num[p];
	}
	if(x<=mid)return query(x,l,mid,ls);
	else return query(x,mid+1,r,rs);
}
void dfs(int u){
	if(u==0)return;
	int nm=query(u,1,n,1);
	if(nm==-1)ans[u]=++tot;
	dfs(L[u]);
	if(nm==0)ans[u]=++tot;
	dfs(R[u]);
	if(nm==1)ans[u]=++tot;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("traversing.in","r",stdin);
	freopen("traversing.out","w",stdout);
//	freopen("ex_traversing1.in","r",stdin);

	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>L[i]>>R[i];
	}
	build(1,n,1);
	dfs(1);
	int flag=1;
	while(q--){
		int t,l,r,x;
		cin>>t;
		if(t==1){
			cin>>l>>r>>x;
			update(l,r,x,1,n,1);
			flag=0;
//			tot=0,dfs(1),flag=1;
//			dfs(1);
//			cout<<'\n';
//			for(int i=1;i<=n;i++){
//				cout<<query(i,1,n,1)<<' ';
//			}
//			cout<<"\n";
//			cout<<'\n';
//			for(int i=1;i<=n;i++){
//				cout<<ans[i]<<' ';
//			}
//			cout<<"\n";
		}
		else{
			cin>>x;
			if(!flag)tot=0,dfs(1),flag=1;
			cout<<ans[x]<<'\n';
		}
	}
	return 0;
}
