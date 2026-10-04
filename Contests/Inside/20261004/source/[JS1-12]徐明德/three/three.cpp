//three
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=6000;
int n,m;
int a[N];
int main(){
//	freopen("three.in","r",stdin);
//	freopen("three.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int x;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[x]++;
	}
	
	return 0;
}
