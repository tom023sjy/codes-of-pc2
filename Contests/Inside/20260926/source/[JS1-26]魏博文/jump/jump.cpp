#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long p;
/*void dp(long long r){
	
}
void g(int x){
	for(int i=x;i<s.size();i++){
		if(s[x]=='?'){
			g(x+1);
			p+=1<<x;
			g(x+1);
		}
		else{
			int c=s[x]-'0'
			p+=c<<x;
		}
		if(i==s.size()-1){
			
		}
	}
}*/
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>s;
		int ans=s.size()-1;
		if(s[0]=='1') ans--;
		if(s[s.size()-1]=='1') ans--;
		cout<<ans;
}
