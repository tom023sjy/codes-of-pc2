#include<bits/stdc++.h>
using namespace std;
int T,a[100005],b[100005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("minmax.in","r",stdin);
	freopen("minmax.out","w",stdout);
	cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		if(m>n){
			cout<<"No\n";
			continue;
		}
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=m;i++)cin>>b[i];
		int i=1,j=1;
		while(i<=n&&j<=m){
			if(a[i]==b[j])i++,j++;
			else i++;
		}
		if(j==m+1)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
