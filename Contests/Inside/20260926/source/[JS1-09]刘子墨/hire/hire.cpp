#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6+5;
ll n,m,k,d,ans,b[maxn];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hire.in","r",stdin);
	freopen("hire.out","w",stdout);
	cin>>n>>m>>k>>d;
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		if(k==0){
			b[1]+=y;
			if(b[1]==0){
				cout<<"YES\n";
			}
			else{
				cout<<"NO\n";
			}
		}
	}
	cout<<ans;
	return 0;
}
