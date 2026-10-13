#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
int T;
int n,m;
int a[N],b[N];
signed main(){
	freopen("minmax.in","r",stdin);
	freopen("minmax.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i = 1;i<=n;i++)cin>>a[i];
		for(int i = 1;i<=m;i++)cin>>b[i];
		int tmp = 0;
		for(int i = 1;i<=n;i++){
			if(tmp<m&&a[i]==b[tmp+1])tmp++;
		}
		if(tmp==m)cout<<"Yes\n";
		else cout<<"No\n";
	}
	
	
	return 0;
} 
