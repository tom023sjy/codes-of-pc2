#include<bits/stdc++.h>
#define lowbit(x) x&-x
using namespace std;
const int mod=1e9+7;
int dp[1<<20+1],n;
string s2;
void fj(int x){
	s2="";
	while(x){
		x%2?s2+='1':s2+='0';
		x>>=1;
	}
	while(s2.size()<n)s2+='0';
	reverse(s2.begin(),s2.end());
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n;
	string s;
	cin>>s;
	dp[0]=1;
	for(int i=0;i<=(1<<n)-1;i++){
		fj(i);
		dp[i]=dp[i>>1&1]+dp[i<<1&1];
	}cout<<dp[(1<<n)-1]%mod;
	return 0; 
}
