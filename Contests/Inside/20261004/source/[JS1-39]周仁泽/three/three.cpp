// three Auther T_cat
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e3 + 7;
const int INF = 0x3f3f3f3f;
int n, m, a;
int t[MAXN];
bool type = 1;
vector<int> val;
int solve1() {
	int Min = INF, Max = -1;
	for (auto u : val) {
		Min = min(Min, u);
		Max = max(Max, u);
	}
	if (Max - Min > 2 || val.size() < 3) {
		bool flag = 1;
		for (auto u : val) {
			if (t[u] % 3) {
				flag = 0;
				break;
			}
		}
		if (flag) return 1;
		else return 0;
	}
	else {
		int yu = -1;
		bool flag = 1;
		for (auto u : val) {
			if (yu == -1) yu = t[u]%3;
			else if (yu != t[u]%3) {
				flag = 0;
				break;
			}
		}
		if (!flag) return 0;
		else{
			int tmp = INF;
			for (auto u : val) tmp = min(tmp, t[u]/3);
			return (tmp + 1);
		}
	}
}
int solve2() {
	int cnt = 0, Min = INF, Max = -1;
	vector<int> vis;
	for (auto u : val) {
		Min = min(Min, u);
		Max = max(Max, u);
		vis.push_back(u);
	}
	if (Max - Min > 3) {
		int p = INF, q = -1;
		for (auto u : val) {
			if (u != Min) p = min(p, u);
			if (u != Max) q = max(q, u);
		}
		if (Max - p <= 2) {
			if (t[Min] % 3 == 0) {
				val.clear();
				for (auto u : vis) {
					if (u != Min) val.push_back(u);
				}
				return solve1();
			}
			else return 0;
		} else if (q - Min <= 2) {
			if (t[Max] % 3 == 0) {
				val.clear();
				for (auto u : vis) {
					if (u != Max) val.push_back(u);
				}
				return solve1();
			}
			else return 0;
		} else {
			bool flag = 1;
			for (auto u : val) {
				if (t[u] % 3) {
					flag = 0;
					break;
				}
			}
			if (flag) return 1;
			else return 0;
		}
	} else {
		int must = t[Min] % 3;
		for (int i = 0; i <= t[Min] / 3; i++) {
			int now = i * 3 + must;
			bool ok = 1;
			for (auto u : val) {
				if (u == Min || u == Max) continue;
				t[u] -= now;
				if (t[u] < 0) {
					ok = 0;
					break;
				}
			}
			if (ok) {
				val.clear();
				for (auto u : vis) {
					if (u == Min) continue;
					val.push_back(u);
				}
				cnt += solve1();
				val.clear();
				for (auto u : vis) {
					if (u != Min && u != Max) t[u] += now;
					val.push_back(u);
				}
			}
		}
		return cnt;
	}
}
int solve3() {
	bool flag = 1;
	for (int i = 0; i <= m; i += 4) {
		int a1 = t[i + 1];
		int a2 = t[i + 2];
		int a3 = t[i + 3];
		if (a1 % 3 == a2 % 3 && a2 % 3 == a3 % 3) continue;
		else flag = 0;
	}
	if (flag) return 1;
	else return 0;
}
int solve4() {
	bool flag = 1;
	for (int i = 3; i <= m; i++) {
		while (t[i]) {
			if (t[i - 2] && t[i - 1]) {
				t[i]--;
				t[i - 1]--;
				t[i - 2]--;
			}
			else break;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (t[i]) {
			flag = 0;
			break;
		}
	}
	if (flag) return 1;
	else return 0;
}
signed main() {
	freopen("three.in", "r", stdin);
	freopen("three.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (!t[a]) val.push_back(a);
		t[a]++;
		if (a % 4 == 0) type = 0;
	}
    if (val.size() <= 3) cout << solve1() << "\n";
	else if (val.size() == 4) cout << solve2() << "\n";
	else if (type) cout << solve3() << "\n";
	else cout << solve4() << "\n";
	return 0;
}
