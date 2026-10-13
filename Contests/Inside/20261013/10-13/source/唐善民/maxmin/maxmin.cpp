//#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<list>
using namespace std;
constexpr const int N=5e5;
int n,a[N+1],b[N+1];
vector<pair<int,int>>ans;
void calc(int a[],int b[],bool reverse){
	static int f[2][N+1],g[2][N+1];
	fill(f[1]+1,f[1]+n+1,0x3f3f3f3f);
	f[1][b[1]]=a[1];
	for(int i=2;i<=n;i++){
		fill(f[i&1]+1,f[i&1]+n+1,0x3f3f3f3f);
		for(int j=1;j<=n;j++){
			if(1<=f[i&1^1][j]&&f[i&1^1][j]<=n){
				f[i&1][min(j,b[i])]=min(f[i&1][min(j,b[i])],min(f[i&1^1][j],a[i]));
				f[i&1][max(j,b[i])]=min(f[i&1][max(j,b[i])],max(f[i&1^1][j],a[i]));
			}
		}
	}
	fill(g[1]+1,g[1]+n+1,0xc0c0c0c0);
	g[1][b[1]]=a[1];
	for(int i=2;i<=n;i++){
		fill(g[i&1]+1,g[i&1]+n+1,0xc0c0c0c0);
		for(int j=1;j<=n;j++){
			if(1<=g[i&1^1][j]&&g[i&1^1][j]<=n){
				g[i&1][min(j,b[i])]=max(g[i&1][min(j,b[i])],min(g[i&1^1][j],a[i]));
				g[i&1][max(j,b[i])]=max(g[i&1][max(j,b[i])],max(g[i&1^1][j],a[i]));
			}
		}
	}
	for(int j=1;j<=n;j++){
		if(1<=f[n&1][j]&&f[n&1][j]<=n){
			switch(reverse){
				case false:
					ans.push_back({f[n&1][j],j});
					break;
				case true:
					ans.push_back({j,f[n&1][j]});
					break;
			}
		}
		if(1<=g[n&1][j]&&g[n&1][j]<=n){
			switch(reverse){
				case false:
					ans.push_back({g[n&1][j],j});
					break;
				case true:
					ans.push_back({j,g[n&1][j]});
					break;
			}
		}
	}
}
int main(){
	freopen("maxmin.in","r",stdin);
	freopen("maxmin.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	calc(a,b,false);
	calc(b,a,true);
	sort(ans.begin(),ans.end());
	ans.resize(unique(ans.begin(),ans.end())-ans.begin());
	static int cnt[N+1];
	for(auto [x,y]:ans){
		if(abs(x-y)<n){
			cnt[abs(x-y)]++;
		}
	}
	for(int i=0;i<n;i++){
		cout<<cnt[i]<<' ';
	}
	
	cout.flush();
	
	/*fclose(stdin);
	fclose(stdout);*/
	return 0;
}
