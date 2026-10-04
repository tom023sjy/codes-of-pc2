#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5;
int n, Res[N];  char S[N];

struct Trie {
	int Index = 0;
	struct Point { int son[2]; } tree[N];
	
	void Insert(char *S, int l, int r) {
		int pos = 0;
		for(int i = 1; i <= n - (r - l + 1); i++) {
			int op = 0;
			if(!tree[pos].son[op]) tree[pos].son[op] = ++Index;
			pos = tree[pos].son[op];
		}
		for(int i = l; i <= r; i++) {
			int op = S[i] - '0';
			if(!tree[pos].son[op]) tree[pos].son[op] = ++Index;
			pos = tree[pos].son[op];
		}
	}
	
	void Find(char *S, int l, int r) {
		int pos = 0, num;  bool flag = false;
		for(int i = 1; i <= n - (r - l + 1); i++) {
			int op = 0;  op ^= 1;
			if(tree[pos].son[op]) pos = tree[pos].son[op], num = 1;
			else pos = tree[pos].son[op ^ 1], num = 0;
			
			if(num < Res[i] && !flag) break;
			if(num > Res[i]) flag = true;
			Res[i] = num;
		}
		for(int i = l; i <= r; i++) {
			int op = S[i] - '0';  op ^= 1;
			if(tree[pos].son[op]) pos = tree[pos].son[op], num = 1;
			else pos = tree[pos].son[op ^ 1], num = 0;
			
			if(num < Res[n - r + i] && !flag) break;
			if(num > Res[n - r + i]) flag = true;
			Res[n - r + i] = num;
		}
	}
} Tree;

void Init() {
	for(int i = 1; i <= n; i++) Res[i] = 0;
	for(int i = 0; i <= Tree.Index; i++) Tree.tree[i].son[0] = Tree.tree[i].son[1] = 0;
	Tree.Index = 0;
}

void Print() {
	bool flag = true;
	for(int i = 1; i <= n; i++) {
		if(!Res[i] && flag) continue;
		flag = false;  printf("%d", Res[i]);
	}
	printf("\n");
}

void Main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf(" %c", &S[i]);
	
	for(int len = 1; len <= n; len++) for(int l = 1; l + len - 1 <= n; l++)
		Tree.Insert(S, l, l + len - 1);
	for(int len = 1; len <= n; len++) for(int l = 1; l + len - 1 <= n; l++)
		Tree.Find(S, l, l + len - 1);
	Print();  Init();
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int T;  scanf("%d", &T);  while(T--) Main();  
	return 0; 
}
