#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
int qpow(int w,int b){
	if(b==0){
		return 1;
	}
	int r=qpow(w,b/2);
	r=r*r%mod;
	if(b%2==1){
		r*=w;
		r%=mod;
	}
	return r;
}
signed main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,cnt=0;
	string s;
	cin>>n>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			cnt++;
		}
	}
	int cnt1=cnt/2;
	if(cnt1==0){
		cout<<1;
		return 0;
	}
	int cnt2=n-cnt+cnt1;
	int ss=1;
	for(int i=1;i<=cnt1;i++){
		ss*=i;
		ss%=mod;
	}
	int l=qpow(ss,mod-2);
	for(int i=cnt2,ll=1;ll<=cnt1;ll++,i--){
		l*=i;
		l%=mod;
	}
	cout<<l;
	return 0;
}
