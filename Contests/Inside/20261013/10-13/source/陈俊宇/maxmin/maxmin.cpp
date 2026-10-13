#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 500005;
int n;
int a[N], b[N], st[N], pa[N], pb[N];
ll ans[N];
bool subtask1 = true, subtask2 = true;

int main(){
	freopen("maxmin.in","r",stdin);
	freopen("maxmin.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		pa[a[i]] = i;
	}
	for (int i = 1; i <= n; i++){
		cin >> b[i];
		pb[b[i]] = i;
	}
	for (int i = 1; i <= n; i++){
		if (a[i] != b[i]) subtask1 = false;
		if (a[i] != i) subtask2 = false;
	}
	if (subtask1){
		cout << n;
		for (int i = 1; i <= n-1; i++)	cout << " 0";
		return 0;
	}
	for (int x = 1; x <= n; x++){
		for (int y = 1; y <= n; y++){
			int xp = a[1], bp = b[1];
			bool ok = true;
			memset(st,0,sizeof(int)*(n+2));
			for (int i = pa[x] + 1; i <= n; i++){
				if (x < a[i]) st[i] = 1;
				else st[i] = 2;
			}
			for (int i = pb[y] + 1; i <= n; i++){
				if (y < b[i]){
					if (st[i] == 2){
						ok = false; break;
					}
				}
				else{
					if (st[i] == 1){
						ok = false; break;
					}
				}
			}
			if (ok){
				ans[abs(x-y)]++;
				printf("xy %d %d\n",x,y);
			}
				
		}
	}
	for (int i = 0; i <= n-1; i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
