#include<bits/stdc++.h>
using namespace std;
int ls[100005],rs[100005],fa[100005],n,q,id[100005],idx,o[100005],root;
struct node{
	int t,l,r,x;
}cz[100005];
void dfs1(int x,int op){
	if(o[x]==0||o[x]==1||o[x]==-1){
		op=o[x];
	}
	if(op==-1){
		id[x]=++idx;
		if(ls[x]){
			dfs1(ls[x],op);
		}
		if(rs[x]){
			dfs1(rs[x],op);
		}
		return;
	}
	if(op==0){
		if(ls[x]){
			dfs1(ls[x],op);
		}
		id[x]=++idx;
		if(rs[x]){
			dfs1(rs[x],op);
		}
		return;
	}
	if(ls[x]){
		dfs1(ls[x],op);
	}
	if(rs[x]){
		dfs1(rs[x],op);
	}
	id[x]=++idx;
}
void solve1(){
	for(int i=1;i<=q;i++){
		if(cz[i].t==1){
			idx=0;
			for(int j=cz[i].l;j<=cz[i].r;j++){
				o[j]=cz[i].x;
			}
			dfs1(root,o[root]);
		}
		else{
			cout<<id[cz[i].x]<<endl;
		}
	}
}
int main(){
	freopen("traversing.in","r",stdin);
	freopen("traversing.out","w",stdout);
	memset(o,-1,sizeof(o));
	int cntq1=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>ls[i]>>rs[i];
		fa[ls[i]]=fa[rs[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(fa[i]==0){
			root=i;
		}
	}
	dfs1(root,o[root]);
	for(int i=1;i<=n;i++){
		cin>>cz[i].t;
		if(cz[i].t==1){
			cntq1++;
			cin>>cz[i].l>>cz[i].r>>cz[i].x;
		}
		else{
			cin>>cz[i].x;
		}
	}
	solve1();
	return 0;
}
