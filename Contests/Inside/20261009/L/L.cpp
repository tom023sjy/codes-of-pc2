#include<bits/stdc++.h>
#define I return
#define AK 0
#define IOI
#define ll long long
using namespace std;
int n,a[60],b[60];
int ans=2e9;
void dfs(int x,int m,int k){
	if(m+k-x>=ans) return ;
	if(x==0){
		ans=min(ans,m+k);
		return ;
	}
	m=max(a[x],m);
	k=max(b[x],k);
	if(m+k-x>=ans) return ;
	if(x!=1){
		int d1=a[x-1]-m,d2=b[x-1]-k;
		if(m+k-x>=ans) return ;
		if(d1>0&&d2<=0) dfs(x-1,m,k-1);
		else if(d1<=0&&d2>0) dfs(x-1,m-1,k);
		else{
			if(m+k-x>=ans) return ;
			dfs(x-1,m-1,k);
			if(m+k-x>=ans) return ;
			dfs(x-1,m,k-1);
		}
	}
	else {
		if(m+k-x>=ans) return ;
		dfs(0,m,k);
	}
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>b[i];
	}
	dfs(n,0,0);
	cout<<ans;
    I AK IOI;
}

