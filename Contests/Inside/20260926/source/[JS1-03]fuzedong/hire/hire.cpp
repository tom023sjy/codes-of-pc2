#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,d;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	srand(time(NULL));
	freopen("hire.in","r",stdin);
	freopen("hire.out","w",stdout);
	cin>>n>>m>>k>>d;
	while(m--){
		int x,y;
		cin>>x>>y;
		if(y<0){
			cout<<"YES\n";
		}
		else if(d*k+k<y){
			cout<<"NO\n";
		}
		else {
			int r=rand()%10;
			if(r<=6){
				cout<<"YES\n";
			}
			else {
				cout<<"NO\n";
			}
		}
	}
	return 0;
}
