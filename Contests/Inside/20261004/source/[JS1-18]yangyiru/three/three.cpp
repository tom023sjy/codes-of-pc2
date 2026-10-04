#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int mod = 1e9 + 7;
int n, m;
int a[N], vis[N];

int main(){
	freopen("three.in", "r", stdin);
	freopen("three.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		vis[a[i]]++;
	}
	int ans = 0;
	if(m <= 3){
		if(!vis[1] || !vis[2] || !vis[3]){
			if(vis[1]%3==0 && vis[2]%3==0 && vis[3]%3==0) ans = 1;
		}
		else{
		}
	}
	else if(m <= 4){
		if(vis[2]==0 || vis[3]==0){
			if(vis[1]%3==0 && vis[2]%3==0 && vis[3]%3==0 && vis[4]%3==0) ans = 1;
		}
		else{	
		}
	}
	cout<<ans;
	return 0;
}
