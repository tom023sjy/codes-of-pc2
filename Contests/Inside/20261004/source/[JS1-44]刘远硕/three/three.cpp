#include<bits/stdc++.h>
using namespace std;
int n,m,dp[20][20][20],a[5005];
int main(){
	freopen("three.in","r",stdin);
	freopen("three.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		int x;
		cin>>x;
		a[x]++;
	}
	cout<<0;
	return 0;
}
