#include <bits/stdc++.h>
using namespace std;

int n, m, A[5005], Box[5005];

int Min(int A, int B, int C) { return min(min(A, B), C); }

void Main_1() { printf("1"); }

void Main_2() {
	int cnt = 0;
	for(int i = 1; i <= n; i++) if(A[i] == 1) cnt++;
	printf("%d", cnt % 3 ? 0 : 1);
}

void Main_3() {
	int cnt = 0;
	for(int i = 1; i <= n; i++) Box[A[i]]++;
	for(int i = 0; i <= Min(Box[1], Box[2], Box[3]); i++)
		if(!((Box[1] - i) % 3 || (Box[2] - i) % 3 || (Box[3] - i) % 3))
			cnt++;
	printf("%d", cnt);
}

void Main_4() {
	int cnt = 0;
	for(int i = 1; i <= n; i++) Box[A[i]]++;
	for(int i = 0; i <= Min(Box[2], Box[3], Box[4]); i++) {
		if((Box[4] - i) % 3) continue;
		Box[2] -= i;  Box[3] -= i;

		for(int j = 0; j <= Min(Box[1], Box[2], Box[3]); j++)
			if(!((Box[1] - j) % 3 || (Box[2] - j) % 3 || (Box[3] - j) % 3))
				cnt++;

		Box[2] += i;  Box[3] += i;
	}
	printf("%d", cnt);
}

void Main_5() {
	int cnt = 0;
	for(int i = 1; i <= n; i++) Box[A[i]]++;
	for(int i = 1; i <= m; i++) if(Box[i] % 3) { printf("0");  return; }
	printf("1");
}

int main() {
	freopen("three.in", "r", stdin);
	freopen("three.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &A[i]);  sort(A + 1, A + n + 1);
	
	if(m == 1) { Main_1();  return 0; }
	if(m == 2) { Main_2();  return 0; }
	if(m == 3) { Main_3();  return 0; }
	if(m == 4) { Main_4();  return 0; }
	Main_5();  return 0;
}
