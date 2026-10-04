#include <iostream>
#include <cstring>
#include <vector>
#define int long long
#define F(i, st, ed) for (int i = st; i <= ed; i++)
using namespace std;

const int N = 1e6 + 5;

int n;
string str;

int tot, p[N][2];

inline void init() {
	tot = 0, memset(p, 0, sizeof p);
	return ;
}

inline void add(string sttr) {
	int cur = 0;
	F(i, 1, (int)sttr.size() - 1) {
		bool c = sttr[i] - '0';
		if (!p[cur][c]) p[cur][c] = ++tot;
		cur = p[cur][c];
	}
	return ;
}

inline string match(string sttr) {
	int cur = 0;
	string ans = "";
	F(i, 1, (int)sttr.size() - 1) {
		bool want = !(sttr[i] - '0');
		if (!p[cur][want]) ans += '0', want = !want;
		else ans += '1';
		cur = p[cur][want];
	}
	return ans;
}

inline void solve() {
	init(), str = " ", cin >> n;
	bool ok = 0, del = 0;
	F(i, 1, n) {
		char c;
		cin >> c;
		//cout << "ok " << ok << '\n';
		if (c == '0' && !ok) {
			del = 1;
			continue ;
		}
		else {
			if (c == '1') ok = 1;
			str += c;
		}
	}
	n = str.size() - 1;
	//cout << "n " << n << '\n';
	//cout << "str " << str << '\n';
	
	//cout << "step1 end\n";
	
	if (str == " ") {
		cout << "0\n";
		return ;
	}
	
	bool has0 = 0;
	F(i, 1, n) if (str[i] == '0') has0 = 1;
	if (!has0) {
		F(i, 1, n - 1) cout << 1;
		cout << (del ? "1\n" : "0\n");
		return ;
	}
	
	//cout << "step2 end\n";
	
	int pos = 1;
	while (str[pos] == '1') cout << /*"ans " <<*/ 1, pos++;
	vector <string> vec;
	F(i, 1, pos - 1) {
		string s = " ";
		F(j, i, i + n - pos) s += str[j];
		vec.push_back(s);
	}
	
	{
		//cout << '\n';
		//for (auto i : vec) cout << "vec " << i << '\n';
		//cout << '\n';
	}
	
	//cout << "step3 end\n";
	
	for (auto i : vec) add(i);
	string str2 = " ";
	F(i, pos, n) str2 += str[i];
	cout << /*"ans " <<*/ match(str2) << '\n';
	//string ans = match(str2);
	return ;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
