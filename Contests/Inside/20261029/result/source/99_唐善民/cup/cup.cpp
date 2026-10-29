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
#include<bitset>
using namespace std;
constexpr const int N=2000,H=50,V=N*H;
int n,h[N+1],cnt[H+1];
bitset<V+1>f[N+1];
int main(){
	freopen("cup.in","r",stdin);
	freopen("cup.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i];
		cnt[h[i]]++;
	}
	sort(h+1,h+n+1);
	cnt[h[n]]--;
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		for(int j=1;h[i]+j<=H;j++){
			if(cnt[h[i]+j]){
				f[i]|=f[i-1]<<j;
			}
		}
	}
	for(int i=0;i<=V;i++){
		if(f[n][i]){
			cout<<i<<' ';
		}
	}
	
	cout.flush();
	
	/*fclose(stdin);
	fclose(stdout);*/
	return 0;
}
