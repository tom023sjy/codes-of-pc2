#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,m,a[N],b[N];
int main(){
	freopen("minmax.in","r",stdin);
	freopen("minmax.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=m;i++) cin>>b[i];
		if(m>n){
			cout<<"No\n";
			continue;
		}
		int pos1=0;
		bool flag=0;
		for(int i=1;i<=m;i++){
			while(pos1<n&&a[pos1+1]!=b[i]) pos1++;
			if(a[pos1+1]==b[i]&&pos1+1<=n){
				pos1++;
				if(i==m) flag=1;
			}
			else{
				flag=0;break;
			}
		}
		if(flag) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
