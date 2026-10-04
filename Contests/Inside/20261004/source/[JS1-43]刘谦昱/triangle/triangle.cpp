#include <iostream>
#include <cstring>
#define int long long
#define F(i, st, ed) for (int i = st; i <= ed; i++)
using namespace std;

const int N = 15;

int n, ans = 1e9;
bool a[N][N], b[N][N];

inline bool inrange(int x, int l, int r) {
	return l <= x && x <= r;
}

inline void xz() { // 顺时针旋转120度 
	bool c[N][N];
	memset(c, 0, sizeof c);
	int ceng = (n / 3) + (bool)(n % 3);
	F(i, 1, n) F(j, 1, i) {
		int c1 = n - i + 1; // 行 
		int c2 = j; // 列 
		int c3 = i - j + 1; // 斜线 
		int t = 0, cur;
		if (inrange(c1, 1, ceng)) {
			cur = c1, t++;
			c[cur + j - 1][cur] = a[i][j];
		}
		else if (inrange(c2, 1, ceng)) {
			cur = c2, t++;
			c[n + cur - i][n - i + 1] = a[i][j];
		}
		else if (inrange(c3, 1, ceng)) {
			cur = c3, t++;
			c[n - cur + 1][n - i + 1] = a[i][j];
		}
		//if (t != 1) cout << "error!\n";
	}
	F(i, 1, n) F(j, 1, i) a[i][j] = c[i][j];
	return ;
}

inline void dc() {
	bool c[N][N];
	memset(c, 0, sizeof c);
	F(i, 1, n) F(j, 1, i)
		c[i][i - j + 1] = a[i][j];
	F(i, 1, n) F(j, 1, i)
		a[i][j] = c[i][j];
	return ;
}

inline int calc() {
	int cnt = 0;
	F(i, 1, n) F(j, 1, i)
		if (a[i][j] != b[i][j])
			cnt++;
	return cnt;
}

inline void print() {
	cout << '\n';
	F(i, 1, n) {
		F(j, 1, i) cout << a[i][j] << ' ';
		cout << '\n';
	}
	return ;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("triangle.in", "r", stdin);
	freopen("triangle.out", "w", stdout);
	cin >> n;
	F(i, 1, n) F(j, 1, i) cin >> a[i][j];
	F(i, 1, n) F(j, 1, i) cin >> b[i][j];
	F(i, 1, 3) {
		xz();
		//print();
		ans = min(ans, calc());
		dc();
		//print();
		ans = min(ans, calc());
		dc();
		//print();
	}
	cout << ans;
	return 0;
}
