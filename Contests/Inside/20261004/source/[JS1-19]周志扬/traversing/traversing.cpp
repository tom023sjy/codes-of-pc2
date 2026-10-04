#include <bits/stdc++.h>
using namespace std;

struct Question { int op, l, r, x; };

const int N = 1e5 + 5;
int n, m, L[N], R[N], F[N], A[N], Siz[N], Ans[N];
int Cnt;  bool Flag, Flag3, Flag5;
Question Q[N];

struct SegmentTree {
	struct Point { int l, r, tag, val; } tree[N << 2];
	
	int Len(int pos) { return tree[pos].r - tree[pos].l + 1; }
	
	void Add_tag(int pos, int K) { tree[pos].tag = K, tree[pos].val = K * Len(pos); }
	
	void Push_up(int pos) { tree[pos].val = tree[pos << 1].val + tree[pos << 1 | 1].val; }
	
	void Push_down(int pos) {
		if(tree[pos].tag == 0x3f3f3f3f) return;
		Add_tag(pos << 1, tree[pos].tag);  Add_tag(pos << 1 | 1, tree[pos].tag);
		tree[pos].tag = 0x3f3f3f3f;
	}
	
	void Build(int pos, int L, int R) {
		tree[pos].l = L, tree[pos].r = R, tree[pos].tag = 0x3f3f3f3f;
		if(L == R) { tree[pos].val = -1;  return; }
		
		int mid = L + R >> 1, Left_son = pos << 1, Right_son = pos << 1 | 1;
		Build(Left_son, L, mid);
		Build(Right_son, mid + 1, R);
		
		Push_up(pos);
	}
	
	void Update(int pos, int L, int R, int K) {
		if(tree[pos].r < L || R < tree[pos].l) return;
		if(L <= tree[pos].l && tree[pos].r <= R) { Add_tag(pos, K);  return; }
		
		Push_down(pos);
		
		int Left_son = pos << 1, Right_son = pos << 1 | 1;
		Update(Left_son, L, R, K);
		Update(Right_son, L, R, K);
		
		Push_up(pos);
	}
	
	int Query(int pos, int P) {
		if(tree[pos].r < P || P < tree[pos].l) return 0;
		if(tree[pos].l == tree[pos].r) return tree[pos].val;
		
		Push_down(pos);
		
		int Left_son = pos << 1, Right_son = pos << 1 | 1, res = 0;
		res += Query(Left_son, P);
		res += Query(Right_son, P);
		
		return res;
	}
} Tree;

void Init(int x) {
	Siz[x] = 1;
	if(L[x]) Init(L[x]);  Siz[x] += Siz[L[x]];
	if(R[x]) Init(R[x]);  Siz[x] += Siz[R[x]];
}

int Solve(int x) {
	if(x == 1) return 1;
	
	int res = Solve(F[x]);
	if(A[F[x]] == -1 && L[F[x]] == x) res += 1;
	if(A[F[x]] == -1 && R[F[x]] == x) res += 1 + Siz[L[F[x]]];
	if(A[F[x]] == 0 && R[F[x]] == x) res += 1 + Siz[L[F[x]]];
	if(A[F[x]] == 1 && R[F[x]] == x) res += Siz[L[F[x]]];
	return res;
}

void Main_1() {
	Init(1);
	for(int i = 1; i <= m; i++) {
		if(Q[i].op == 1) { for(int j = Q[i].l; j <= Q[i].r; j++) A[j] = Q[i].x; }
		if(Q[i].op == 2) {
			int res = Solve(Q[i].x);
			if(A[Q[i].x] == 0) res += Siz[L[Q[i].x]];
			if(A[Q[i].x] == 1) res += 2 + Siz[L[Q[i].x]];
			printf("%d\n", res);
		}
	}
}

void Main_3() {
	Init(1);  Tree.Build(1, 1, n);
	for(int i = 1; i <= m; i++) {
		if(Q[i].op == 1) Tree.Update(1, Q[i].l, Q[i].r, Q[i].x);
		if(Q[i].op == 2) break;
	}
	for(int i = 1; i <= n; i++) A[i] = Tree.Query(1, i);
	
	for(int i = 1; i <= n; i++) {
		Ans[i] = Solve(i);
		if(A[i] == 0) Ans[i] += Siz[L[i]];
		if(A[i] == 1) Ans[i] += 2 + Siz[L[i]];
	}
	for(int i = 1; i <= m; i++) {
		if(Q[i].op == 1) continue;
		if(Q[i].op == 2) printf("%d\n", Ans[Q[i].x]);
	}
}

void Main_5() {
	Init(1);
	for(int i = 1; i <= m; i++) {
		if(Q[i].op == 1) A[Q[i].l] = Q[i].x;
		if(Q[i].op == 2) {
			int res = Solve(Q[i].x);
			if(A[Q[i].x] == 0) res += Siz[L[Q[i].x]];
			if(A[Q[i].x] == 1) res += 2 + Siz[L[Q[i].x]];
			printf("%d\n", res);
		}
	}
}

int main() {
	freopen("traversing.in", "r", stdin);
	freopen("traversing.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) { scanf("%d %d", &L[i], &R[i]);  F[L[i]] = F[R[i]] = i;  A[i] = -1; }
	for(int i = 1; i <= m; i++) {
		scanf("%d", &Q[i].op);
		if(Q[i].op == 1) scanf("%d %d %d", &Q[i].l, &Q[i].r, &Q[i].x);
		if(Q[i].op == 2) scanf("%d", &Q[i].x);
		
		Cnt += (Q[i].op == 1);
		if(Q[i].op == 2) Flag = true;
		if(Q[i].op == 1 && Flag) Flag3 = true;
		if(Q[i].op == 1 && Q[i].l != Q[i].r) Flag5 = true;
	}
	
	if(n <= 5000 && m <= 5000) { Main_1();  return 0; }
	if(Cnt <= 10) { Main_1();  return 0; }
	if(!Flag3) { Main_3();  return 0; }
	if(!Flag5) { Main_5();  return 0; }
}
