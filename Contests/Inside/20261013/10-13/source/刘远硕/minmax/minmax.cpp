#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100200],b[100020];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("minmax.in","r",stdin);
	freopen("minmax.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=1;i<=m;i++) cin>>b[i];
		int now=1;
		for (int i=1;i<=n;i++) {
			if (a[i]==b[now]) {
				now++;
				if (now>m) {
					cout<<"Yes\n";
					break;
				}
			}
		}
		if (now<=m) cout<<"No\n";
	}
	return 0;
} 
