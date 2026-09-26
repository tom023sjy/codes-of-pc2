#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, Q, K, d;
int tree[N*4], tag[N*4];

int ls(int p){return p<<1;}
int rs(int p){return p<<1|1;}

void push_up(int p){
	tree[p] = tree[ls(p)] + tree[rs(p)];
}

void build(int p, int pl, int pr){
	if(pl == pr){
		tree[p] = K;
		return;
	}
	int mid = (pl+pr) >> 1;
	build(ls(p), pl, mid);
	build(rs(p), mid+1, pr);
	push_up(p);
}

void addtag(int p, int pl, int pr, int k){
	tag[p] += k;
	tree[p] += k * (pr-pl+1);
}

void push_down(int p, int pl, int pr){
	if(tag[p]){
		int mid = (pl+pr) >> 1;
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
	int mid = (pl+pr) >> 1;
	if(l <= mid) update(l, r, ls(p), pl, mid, k);
	if(r >= mid+1) update(l, r, rs(p), mid+1, pr, k);
	push_up(p);
}

int query(int l, int r, int p, int pl, int pr){
	if(l<=pl && r>=pr){
		return tree[p];
	}
	push_down(p, pl, pr);
	int mid = (pl+pr) >> 1;
	int res = 0;
	if(l <= mid) res += query(l, r, ls(p), pl, mid);
	if(r >= mid+1) res += query(l, r, rs(p), mid+1, pr);
	return res;
}

int main(){
	freopen("hire.in", "r", stdin);
	freopen("hire.out", "w", stdout);
	cin>>n>>Q>>K>>d;
	build(1, 1, n);
	while(Q--){
		int x, y;
		cin>>x>>y;
		int q = query(x, x+d, 1, 1, n);
		if(y<0 && y>(d+1)*K-q) cout<<"NO\n";
		else if(y>0 && y>q) cout<<"NO\n";
		else{
			update(x, x+y, 1, 1, n, -y);
			cout<<"YES\n";
		}
	}
	return 0;
}
