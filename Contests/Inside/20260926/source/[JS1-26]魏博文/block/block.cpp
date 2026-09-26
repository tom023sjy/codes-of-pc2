#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int p=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		p=max(p,x);
	}
	cout<<p;
}
