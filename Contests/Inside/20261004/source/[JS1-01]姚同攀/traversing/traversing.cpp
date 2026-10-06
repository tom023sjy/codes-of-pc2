#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,Q,a[N],ls[N],rs[N],f[N][21],sz[N],dep[N];
struct ST{
	int tg[N<<2],flg[N<<2];
	void pd(int o){
		if(!flg[o]) return;
		tg[o<<1]=tg[o<<1|1]=tg[o];
		flg[o<<1]=flg[o<<1|1]=1;
		flg[o]=0;
	}
	void upd(int L,int R,int x,int o,int l,int r){
		if(L<=l&&r<=R){
			tg[o]=x;
			flg[o]=1;
			return;
		}
		pd(o);
		int m=l+((r-l)>>1);
		if(L<=m) upd(L,R,x,o<<1,l,m);
		if(R>m) upd(L,R,x,o<<1|1,m+1,r);
	}
	int que(int p,int o,int l,int r){
		if(l==r) return tg[o];
		pd(o);
		int m=l+((r-l)>>1);
		if(p<=m) return que(p,o<<1,l,m);
		return que(p,o<<1|1,m+1,r);
	}
}t;
void pre(int o){
	if(!o) return;
	for(int i=1;i<=20;++i) f[o][i]=f[f[o][i-1]][i-1];
	f[ls[o]][0]=f[rs[o]][0]=o;
	dep[ls[o]]=dep[rs[o]]=dep[o]+1;
	pre(ls[o]);pre(rs[o]);
	sz[o]=sz[ls[o]]+sz[rs[o]]+1;
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;--i)
		if(dep[f[x][i]]>=dep[y])
			x=f[x][i];
	if(x==y) return x;
	for(int i=20;i>=0;--i)
		if(f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
int dfs(int p,int o){
	if(!o) return 0;
	int v=t.que(o,1,1,n);
	if(p==o){
		if(v==-1) return 1;
		if(v==0) return 1+sz[ls[o]];
		return sz[o];
	}
	int on=(lca(p,ls[o])==ls[o]);
	if(v==-1){
		if(on) return 1+dfs(p,ls[o]);
		return 1+sz[ls[o]]+dfs(p,rs[o]);
	}else if(!v){
		if(on) return dfs(p,ls[o]);
		return 1+sz[ls[o]]+dfs(p,rs[o]);
	}else{
		if(on) return dfs(p,ls[o]);
		return sz[ls[o]]+dfs(p,rs[o]); 
	}
}
int main(){
	freopen("traversing.in","r",stdin);
	freopen("traversing.out","w",stdout);
	f[1][0]=1;
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;++i) scanf("%d%d",&ls[i],&rs[i]);
	t.upd(1,n,-1,1,1,n);
	pre(1);
	while(Q--){
		int opt,L,R,x;
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d%d",&L,&R,&x);
			t.upd(L,R,x,1,1,n);
		}else{
			scanf("%d",&x);
			printf("%d\n",dfs(x,1));
		}
	}
	return 0;
}
