#include <bits/stdc++.h>
using namespace std;
int n,cnt,cnt0,mod=1000000007;
string s;
int jc(int n){
	int ans=1;
	for(int i=1;i<=n;++i) ans*=i;
	return ans;
}
int C(int n,int m){return (jc(n)/(jc(m)*jc(n-m)))%mod;}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>s;
	s=" "+s;
	for(int i=1;i<=n;++i){if(s[i]=='1') cnt++;}
	cnt0=n;
	if(cnt%2==1){
		cnt0--;
		cnt/=2;
		cout<<C(cnt,cnt0)*(cnt*2-1);
	}
	else{
		cnt/=2;
		cout<<C(cnt,cnt0);
	}
	return 0;
}
