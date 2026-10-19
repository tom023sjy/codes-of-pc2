#include<bits/stdc++.h>
using namespace std;
int cid,Q,cnt[505];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	cin>>cid>>Q;
	while(Q--){
		int op;
		cin>>op;
		if(op==1){
			int x,y;
			cin>>x>>y;
			cnt[x]=y;
		}
		else{
			int k;
			cin>>k;
			cout<<k<<"\n";
		}
	}
	return 0;
}
