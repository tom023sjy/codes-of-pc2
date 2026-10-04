#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int a[5005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("three.in","r",stdin);
	freopen("three.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int u;
		cin>>u;
		a[u]++;
	}
	for(int i=1;i<=5000;i++){
		if(a[i]!=0){
			if(a[i+1]<a[i]||a[i+2]<a[i]){
				cout<<0;
				return 0;
			}
			a[i+1]-=a[i],a[i+2]-=a[i];
		}
	}cout<<1;
	return 0;
}

