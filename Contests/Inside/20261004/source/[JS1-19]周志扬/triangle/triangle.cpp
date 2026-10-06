#include <bits/stdc++.h>
using namespace std;

int n, Res = 0x3f3f3f3f;
int A[15][15], B[15][15], C[15][15];


void Turn() {
	vector<int> V;  int cur = 0;
	for(int x = 1; x <= n; x++) {
		int i = n, j = x;
		while(i > 0 && j > 0) { V.push_back(A[i][j]);  i--, j--; }
	}
	for(int i = 1; i <= n; i++) for(int j = 1; j <= i; j++)
		A[i][j] = V[cur++];
}

void Reverse() {
	for(int i = 1; i <= n; i++) for(int j = 1; j <= i; j++)
		C[i][i - j + 1] = A[i][j];
	for(int i = 1; i <= n; i++) for(int j = 1; j <= i; j++)
		A[i][j] = C[i][j];
}

int Check() {
	int cnt = 0;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= i; j++)
		if(A[i][j] != B[i][j]) cnt++;
	return cnt;
}

int main() {
	freopen("triangle.in", "r", stdin);
	freopen("triangle.out", "w", stdout);
	
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) for(int j = 1; j <= i; j++) scanf("%d", &A[i][j]);
	for(int i = 1; i <= n; i++) for(int j = 1; j <= i; j++) scanf("%d", &B[i][j]);
	
	Res = min(Res, Check());  Turn();
	Res = min(Res, Check());  Turn();
	Res = min(Res, Check());  Turn();
	Reverse();
	Res = min(Res, Check());  Turn();
	Res = min(Res, Check());  Turn();
	Res = min(Res, Check());  Turn();
	
	printf("%d", Res);
	return 0;
}
