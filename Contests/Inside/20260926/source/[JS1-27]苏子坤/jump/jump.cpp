#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s;
int f(string ss){
	cout<<ss<<endl;
	int ret=1;
	for(int i=0;i<n;i++){
		if(ss[i]=='1'&&ss[i+1]=='1'){
			for(int j=i+2;j<n;j++){
				if(ss[j]=='1')break;
				ret++;
			}
		}
	}
	for(int i=n-1;i>=0;i--){
		if(ss[i]=='1'&&ss[i-1]=='1'){
			for(int j=i-2;j>=0;j--){
				if(ss[j]=='1')break;
				ret++;
			}
		}
	}
	return ret;
}
void solve(string str,int now){
	if(now==n){
		ans+=f(str);
		return;
	}
	if(str[now]=='?'){
		str[now]='1';
		solve(str,now+1);
		str[now]='0';
		solve(str,now+1);
	}
	else solve(str,now+1);
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>s;
	solve(s,0);
	cout<<ans;
	return 0;
}
