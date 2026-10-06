#include<bits/stdc++.h>
using namespace std;
int T;
string Xor(int N,string a,string b){
	int x=(int)a.size();
	int y=(int)b.size();
	string supa(N-x,'0'),supb(N-y,'0');
	a=supa+a;
	b=supb+b;
	string ret="";
	for(int i=0;i<N;++i){
		if(a[i]!=b[i]) ret+="1";
		else ret+="0";
	}
	return ret;
}


int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		int n;
		string str;
		cin>>n>>str;
		string ans(n,'0');
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j){
				ans=max(ans,Xor(n,str,str.substr(i-1,j-i+1)));
			}
		}
		bool flag=false;
		for(int i=0;i<n;++i){
			if(ans[i]=='1'||i==n-1) flag=true;
			if(flag) cout<<ans[i];
		}
		cout<<'\n';
	}
	return 0;
}
