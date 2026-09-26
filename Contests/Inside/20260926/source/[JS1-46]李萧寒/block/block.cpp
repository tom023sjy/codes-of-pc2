#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	int n,m,a,ma=INT_MIN;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		ma=max(ma,a);
	}
	cout<<ma;
	return 0;
}
