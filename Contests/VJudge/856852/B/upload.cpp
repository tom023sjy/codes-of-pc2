#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 270;
int a[N + 5][N + 5];
bool vis[N + 5][N + 5];
signed main() {
	map<int, bool> bbb;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			cin >> a[i][j], bbb[a[i][j]] = 1;
	int sum = 0, ans = 0;
	for (int i = 1; i < n; i ++)
		for (int j = 1; j < n; j ++) {
			map<int, int> mp;
			mp[a[i][j]] ++; mp[a[i][j + 1]] ++; 
			mp[a[i + 1][j]] ++; mp[a[i + 1][j + 1]] ++;
			vis[i][j] = mp.size() >= 3;
			sum += vis[i][j];
		}
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++) {
			set<int> colors;
			for (int ii = i - 1; ii <= i + 1; ii ++)
				for (int jj = j - 1; jj <= j + 1; jj ++)
					if (1 <= ii && ii <= n && 1 <= jj && jj <= n)
						colors.insert(a[ii][jj]);
			if (colors.size() < k)
				colors.insert(k + 1);
			int bc = a[i][j];
			for (int v : colors) {
				a[i][j] = v;
				int tsum = sum;
				for (int ii = i - 1; ii <= i; ii ++)
					for (int jj = j - 1; jj <= j; jj ++) {
						if (!(1 <= ii && ii < n && 1 <= jj && jj < n)) continue;
						map<int, int> mp;
						mp[a[ii][jj]] ++; mp[a[ii][jj + 1]] ++; 
						mp[a[ii + 1][jj]] ++; mp[a[ii + 1][jj + 1]] ++;
						if (mp.size() >= 3 && !vis[ii][jj])
							tsum ++;
						if (mp.size() < 3 && vis[ii][jj])
							tsum --;
					}
				ans = max(ans, tsum);
			}
			a[i][j] = bc;
		}
	cout << ans;
	return 0;
}
