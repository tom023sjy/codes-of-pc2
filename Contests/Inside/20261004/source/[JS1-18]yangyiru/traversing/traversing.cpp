#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, Q;
int tree[N], tag[N], dfn[N], ans[N];
//dfn[]×îÖÕË³Ğò 

struct node{
	int L, R, sty;
}T[N];

struct Ask{
	int op, l, r, x;
}q[N];

int ls(int p){return p<<1;}
int rs(int p){return p<<1|1;}

int push_up(int p){
	tree[p] = tree[ls(p)] + tree[rs(p)];
}

int addtag(int p, int pl, int pr, int k){
	tag[p] = k;
	tree[p] = k * (pr-pl+1);
}

void push_down(int p, int pl, int pr){
	if(tag[p]){
		int mid = (pl + pr) >> 1;
		addtag(ls(p), pl, mid, tag[p]);
		addtag(rs(p), mid+1, pr, tag[p]);
		tag[p] = 0;
	}
}

void update(int l, int r, int p, int pl, int pr, int k){
	if(l<=pl && r>=pr){
		addtag(p, pl, pr, k);
		return;
	}
	push_down(p, pl, pr);
	int mid = (pl + pr) >> 1;
	if(l <= mid) update(l, r, ls(p), pl, mid, k);
	if(r >= mid+1) update(l, r, rs(p), mid+1, pr, k);
	push_up(p);
}

int query(int p, int pl, int pr, int x){
	if(pl == pr) return tree[p];
	int mid = (pl + pr) >> 1;
	if(x <= mid) return query(ls(p), pl, mid, x);
	else return query(rs(p), mid+1, pr, x);
}

int len = 0;

void dfs1(int u){
	int sty = T[u].sty, l = T[u].L, r = T[u].R;
	if(sty == -1){
		dfn[++len] = u;
		if(l) dfs1(l);
		if(r) dfs1(r);
	}
	else if(sty == 0){
		if(l) dfs1(l);
		dfn[++len] = u;
		if(r) dfs1(r);
	}
	else{
		if(l) dfs1(l);
		if(r) dfs1(r);
		dfn[++len] = u;
	}
}

void dfs2(int u){
	int sty = query(1, 1, n, u), l = T[u].L, r = T[u].R;
	if(sty == -1){
		dfn[++len] = u;
		if(l) dfs1(l);
		if(r) dfs1(r);
	}
	else if(sty == 0){
		if(l) dfs1(l);
		dfn[++len] = u;
		if(r) dfs1(r);
	}
	else{
		if(l) dfs1(l);
		if(r) dfs1(r);
		dfn[++len] = u;
	}
}


int main(){
	freopen("traversing.in", "r", stdin);
	freopen("traversing.out", "w", stdout);
	cin>>n>>Q;
	int c1 = 0, c2 = 0;
	bool f1 = 1, f2 = 1, f3 = 1;
	for(int i=1; i<=n; i++){
		cin>>T[i].L>>T[i].R;
		T[i].sty = -1;
		if(T[i].L && T[i].R) f2 = 0;
	}
	for(int i=1; i<=Q; i++){
		int op, l, r, x;
		cin>>op;
		if(op == 1){
			cin>>l>>r>>x;
			q[i] = {op, l, r, x};
			if(c1) f1 =0;
			c2++;
			if(l != r) f3 = 0;
		}
		else{
			cin>>x;
			q[i] = {op, 0, 0, x};
			c1++;
		}
	}
	if(f1){ // Subtask 3 ok
		int cut = 0;
		for(int i=1; i<=Q; i++){
			if(q[i].op == 1) update(q[i].l, q[i].r, 1, 1, n, q[i].x);
			else{
				cut = i;
				break;
			}
		}
		for(int i=1; i<=n; i++) T[i].sty = query(1, 1, n, i);
		dfs1(1);
		for(int i=1; i<=n; i++) ans[dfn[i]] = i;
		for(int i=cut; i<=Q; i++) cout<<ans[q[i].x]<<'\n';
	}
	else if(c2 <= 10 || (n<=5000 && Q <=5000)){ // Subtask 1 & 2
		bool f = 1;
		dfs1(1);
		for(int i=1; i<=n; i++) ans[dfn[i]] = i;
		for(int i=1; i<=Q; i++){
			if(q[i].op == 1){
				f = 0;
				update(q[i].l, q[i].r, 1, 1, n, q[i].x);
			}
			else{
				if(!f){
					for(int i=1; i<=n; i++) T[i].sty = query(1, 1, n, i);
					len = 0;
					dfs1(1);
					for(int i=1; i<=n; i++) ans[dfn[i]] = i;
				}
				cout<<ans[q[i].x]<<'\n';
				f = 1;
			}
		}
	}
	else if(f3){ // Subtask 5
		bool f = 1;
		dfs1(1);
		for(int i=1; i<=n; i++) ans[dfn[i]] = i;
		for(int i=1; i<=Q; i++){
			if(q[i].op == 1){
				f = 0;
				T[q[i].l].sty = q[i].x;
			}
			else{
				if(!f){
					len = 0;
					dfs1(1);
					for(int i=1; i<=n; i++) ans[dfn[i]] = i;
				}
				cout<<ans[q[i].x]<<'\n';
				f = 1;
			}
		}
	}
/*
	else if(f2){ // Subtask 6 & 8
		dfs1(1);
		for(int i=1; i<=Q; i++){
			if(q[i].op == 1){
				
			}
		}
	}
//	*/
	else{
		bool f = 1;
		dfs1(1);
		for(int i=1; i<=n; i++) ans[dfn[i]] = i;
		for(int i=1; i<=Q; i++){
			if(q[i].op == 1){
				f = 0;
				update(q[i].l, q[i].r, 1, 1, n, q[i].x);
			}
			else{
				if(!f){
					for(int i=1; i<=n; i++) T[i].sty = query(1, 1, n, i);
					len = 0;
					dfs1(1);
					for(int i=1; i<=n; i++) ans[dfn[i]] = i;
				}
				cout<<ans[q[i].x]<<'\n';
				f = 1;
			}
		}
	}
	return 0;
}
