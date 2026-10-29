#include<iostream>
using namespace std;

int n,as=0,a[15],mp[505]={},light[15]={},now[15];

void dfs(int x){
	if(x>n){
		int cnt=0,maxxl[15],maxxr[15];
		maxxl[0]=0;
		maxxr[n+1]=0;
		for(int i=1;i<=n;i++) maxxl[i]=max(maxxl[i-1],now[i]);
		for(int i=n;i>=1;i--) maxxr[i]=max(maxxr[i+1],now[i]);
		for(int i=2;i<n;i++){
			if(maxxl[i-1]>now[i]&&now[i]<maxxr[i+1]) cnt+=min(maxxl[i-1],maxxr[i+1])-now[i];
		}
		mp[cnt]=1;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!light[i]){
			now[x]=a[i];
			light[i]=1;
			dfs(x+1);
			light[i]=0;
		}
	}
}

int main(){
	freopen("cup.in","r",stdin);
	freopen("cup.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	for(int i=0;i<=500;i++){
		if(mp[i]) cout<<i<<" ";
	}
	return 0;
}
