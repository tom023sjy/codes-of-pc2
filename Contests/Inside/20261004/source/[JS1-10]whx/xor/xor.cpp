#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>t;
	while(t--){
		int n,tot=0,cnt=0;
		string s,s1,s2,s3="0";
		cin>>n>>s;
		while(s[tot]=='0'){
			tot++;
		}
		int len=s.length();
		for(int i=tot;i<len;i++){
			if(s[i]=='0'){
				for(int j=i;j<len;j++){
					if(s[j]=='1'){
						s1[cnt]='0';
					}else{
						s1[cnt]='1';
					}
					cnt++;
				}
				for(int j=tot;j<i;j++){
					int p=0;
					for(int k=j;k<=cnt;k++){
						if(s[k]==s1[k-j]){
							s2[p]='1';
						}else{
							s2[p]='0';
						}
						p++;
					}
					if(s2>s3){
						s3=s2;
					}
				}
				cout<<s3<<'\n';
				break;
			}
			if(i==len-1){
				cout<<0<<'\n';
				break;
			}
			cout<<s[i];
		}
	}
	return 0;
}
