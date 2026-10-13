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
constexpr const int N=1e5;
int n,m,a[N+1];
int main(){
	freopen("minmax.in","r",stdin);
	freopen("minmax.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i]; 
		}
		bool ans=true;
		int i=0;
		while(m--){
			int x;
			cin>>x;
			while(i<=n&&a[i]!=x){
				i++;
			}
			if(i<=n&&a[i]==x){
				i++;
			}else{
				ans=false;
			}
		}
		cout<<(ans?"Yes":"No")<<'\n';
	}
	
	cout.flush();
	
	/*fclose(stdin);
	fclose(stdout);*/
	return 0;
}
