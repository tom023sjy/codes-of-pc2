#include<bits/stdc++.h>
using namespace std;
int n,T;
int dp[3005][3005];
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
cin>>T;
while(T--){
	cin>>n;
	cin>>s;
	string ans="";
	while(ans.size()<n)ans+='0';
	memset(dp,0,sizeof(0));
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			string cnt="";
			for(int q=j;q>=i;q--){
				if(s[q-1]!=s[n-(j-q)-1])cnt+='1';
				else cnt+='0';
		//		cout<<s[q-1]<<" "<<s[n-(j-q)-1]<<" "<<n-(j-q)-1<<"\n";
			}
			for(int ss=n-(j-i+1)-1;ss>=0;ss--){
				if(s[ss]=='1')cnt+='1';
				else cnt+='0';
			}
			
		//	while(cnt.size()<n)cnt+='0';
			reverse(cnt.begin(),cnt.end());//cout<<cnt<<" "<<i<<" "<<j<<"\n";
			int fl=0;
			for(int u=0;u<n;u++){
				if(ans[u]=='1'&&cnt[u]=='0'){
					fl=1;break;
				}else if(ans[u]=='0'&&cnt[u]=='1'){
					fl=2;break;
				}
			}if(fl==2)ans=cnt;
		}
	}int df=0;
	for(int uu=0;uu<ans.size();uu++){
		if(df)cout<<ans[uu];
		else if((!df)&&ans[uu]=='1'){
			df=1;
			cout<<ans[uu];
		}
	}
	if(!df)cout<<0;
	cout<<"\n";
//cout<<T<<"\n";
}
	return 0;
}

