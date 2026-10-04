#include <bits/stdc++.h>
using namespace std;

struct node {
	int fa, ls, rs, x = -1, lscnt = 0, rscnt = 0;
} tre[100005];

int n, q;

int d(int idx) {
	if (tre[idx].ls != 0) tre[idx].lscnt += d(tre[idx].ls);
	if (tre[idx].rs != 0) tre[idx].rscnt += d(tre[idx].rs);
	return tre[idx].lscnt + tre[idx].rscnt + 1;
}

int d2(int idx, int la) {
//	printf("d2(%d, %d);\n", idx, la);
	int sum = 0;
	if (idx != 1) sum = d2(tre[idx].fa, idx);
	if (la != -1) {
		if (la == tre[idx].ls) {
			if (tre[idx].x == -1) sum++;
		} else {
			if (tre[idx].x != 1) sum++;
			sum += tre[idx].lscnt;
		}
	} else {
		sum++;
		if (tre[idx].x != -1) sum += tre[idx].lscnt;
		if (tre[idx].x == 1) sum += tre[idx].rscnt;
	}
	return sum;
}

int main() {
	freopen("traversing.in", "r", stdin);
	freopen("traversing.out", "w", stdout);
	scanf("%d%d", &n, &q);
	int t1, t2;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &t1, &t2);
		tre[i].ls = t1;
		tre[i].rs = t2;
		tre[t1].fa = i;
		tre[t2].fa = i;
	}
	d(1);
	int op, op1, op2, op3;
	for (int i = 1; i <= q; i++) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d%d", &op1, &op2, &op3);
			for (int j = op1; j <= op2; j++) {
				tre[j].x = op3;
			}
		} else {
			scanf("%d", &op1);
			printf("%d\n", d2(op1, -1));
		}
	}
	return 0;
}
/*
w w w   a   n   n ttttt  222   000    +   pppp  ttttt  sss  !
w w w  a a  nn  n   t   2   2 0   0   +   p   p   t   s     !
w w w a   a n n n   t      2  0   0 +++++ pppp    t    sss  !
w w w aaaaa n  nn   t     2   0   0   +   p       t       s 
 w w  a   a n   n   t   22222  000    +   p       t   ssss  !
*/
