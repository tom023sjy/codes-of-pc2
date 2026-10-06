#include<bits/stdc++.h>
using namespace std;
int n,m,tong[5005];
int main(){
	freopen("three.in","r",stdin);
	freopen("three.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		tong[t]++;
	}
	if(m==1){
		if(tong[1]%3==0)cout<<1;
		else cout<<0;
	}
	else if(m==2){
		if(tong[1]%3==0&&tong[2]&3==0)cout<<1;
		else cout<<0;
	}
	else if(m==3){
		if(tong[1]%3!=tong[2]%3||tong[1]%3!=tong[3]%3||tong[2]%3!=tong[3]%3
		)cout<<0;
		else{
			int ans;
			if(tong[1]%3==0)ans=0;
			else ans=1;
			ans+=min(tong[1],min(tong[2],tong[3]))/3;
			cout<<ans;
		}
	}
	else if(m==4){
		if(tong[2]%3!=tong[3]%3||(tong[1]+tong[4])%3!=tong[2]%3)cout<<0;
		else{
			int ans;
			if(tong[2]%3==0)ans=0;
			else ans=1;
			ans+=min(min(tong[2],tong[3]),tong[1]+tong[4])/3;
			cout<<ans;
		}
	}
	else{
		int ans=1;
		for(int i=1;i<=m;i+=3){
			if(tong[i]%3!=tong[i+1]%3||tong[i]%3!=tong[i+2]%3||tong[i+1]%3!=tong[i+2]%3){
				cout<<0;
				return 0;
			}
			int ret;
			if(tong[i]%3==0)ret=0;
			else ret=1;
			ret+=min(min(tong[2],tong[3]),tong[1])/3;
			if(ret!=0)ans*=ret;
			ans%=(int)(1e9+7);
		}
		cout<<ans;
	}
	return 0;
}
