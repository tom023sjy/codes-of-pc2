#include<bits/stdc++.h>
using namespace std;
int n,m,k,d,a[500005];
signed main(){
	freopen("hire.in","r",stdin);
	freopen("hire.out","w",stdout);
	cin>>n>>m>>k>>d;
	while(m--){
		int x,y,sum=0;
		cin>>x>>y;
		a[x]+=y;
		bool ok=1;
		for(int i=1;i<=n-d;i++){
			sum+=a[i];
			if(a[i]>k*(d+1)){
				ok=0;
				break;
			}
		}
		for(int i=n-d+1;i<=n;i++){
			sum+=a[i];
			if(a[i]>k*(n-i+1)){
				ok=0;
				break;
			}
		}
		if(sum<=n*k&&ok)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
