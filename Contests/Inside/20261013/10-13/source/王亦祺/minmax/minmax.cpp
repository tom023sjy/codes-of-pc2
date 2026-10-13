#include<iostream>
using namespace std;

int t,n,m,a[100005],b[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("minmax.in","r",stdin);
	freopen("minmax.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m;
		int ptr=1;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=m;i++) cin>>b[i];
		for(int i=1;i<=n;i++){
			if(ptr<=m&&a[i]==b[ptr]) ptr++;
		}
		if(ptr==m+1) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
