#include<bits/stdc++.h>
using namespace std;
int sb,n,dp[30][1100000],p=1e9+7;
string t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("mountain.in","r",stdin);
	freopen("mountain.out","w",stdout);
	cin>>sb>>t;
	n=t.size();
	t=" "+t;
	if(sb==10){
		int tmp=1;
		for(int i=1;i<n;i++){
			cout<<tmp<<" ";
			tmp=(2*tmp)%p;
		}
		cout<<1;
		return 0;
	}
	if(sb==11){
		vector<int> v;
		int tmp=1;
		for(int i=1;i<n;i++){
			v.push_back(tmp);
			tmp=(2*tmp)%p;
		}
		v.push_back(1);
		reverse(v.begin(),v.end());
		for(auto x:v) cout<<x<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++){
		dp[i][(1<<(i-1))]=1;
	}
	for(int s=1;s<(1<<n);s++){
		for(int i=1;i<=n;i++){
			if(s&(1<<i-1)) continue;
			for(int j=1;j<=n;j++){
				if((s&(1<<j-1))==0) continue; 
				if((i<j&&t[j]=='D')||(j<i&&t[j]=='U')){
					dp[i][s|(1<<i-1)]+=dp[j][s];
					if(dp[i][s|(1<<i-1)]>p) dp[i][s|(1<<i-1)]-=p;
				} 
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<dp[i][(1<<n)-1]<<" ";
	}
	return 0;
}
