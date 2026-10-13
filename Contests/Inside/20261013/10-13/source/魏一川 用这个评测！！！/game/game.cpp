#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,fl=1;
vector<int>G[200005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		if(x+1!=y)fl=0;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	if(fl){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}
