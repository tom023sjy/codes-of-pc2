#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n,m;
int a[N], b[N], ta[N], tb[N];

void solve(){
	cin >> n >> m;
	if (n < m){
		cout << "No\n"; return;
	}
	memset(ta,0,sizeof(ta));
	memset(tb,0,sizeof(tb));
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		ta[a[i]]++;
	}
	for (int i = 1; i <= m; i++){
		cin >> b[i];
		tb[b[i]]++;
	}
	for (int i = 1; i <= n; i++){
		if (ta[i] < tb[i]){
			cout << "No\n"; return;
		}
	}
	int p = 1;
	for (int i = 1; i <= m; i++){
		int r = p;
		while (r <= n && a[r] != b[i]){
			r++;
		}
		if (r > n || a[r] != b[i]){
			cout << "No\n"; return;
		}
		p = r+1;
	}
	cout << "Yes\n";
}

int main(){
	freopen("minmax.in","r",stdin);
	freopen("minmax.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
