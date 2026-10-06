#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		string s;
		cin>>n;
		cin>>s;
		s=' '+s;
		int fir1=-1,lst1=-1,fir0=-1,lst0=-1;
		for(int i=1;i<=n;i++){
			if(fir1==-1&&s[i]=='1'){
				fir1=i;
			}
			if(lst1==-1&&fir1!=-1&&s[i]=='0'){
				lst1=i-1;
				fir0=i;
			}
			if(lst0==-1&&fir0!=-1&&s[i]=='1'){
				lst0=i-1;
			}
		}
		if(fir1==-1){
			cout<<"0\n";
			continue;
		}
		if(lst1==-1){
			if(fir1==1){
				for(int i=1;i<n;i++){
					cout<<1;
				}
				cout<<"0\n";
			}
			else{
				for(int i=fir1;i<=n;i++){
					cout<<1;
				}
				cout<<endl;
			}
			continue;
		}
		int hav1=lst1-fir1+1,hav0=lst0-fir0+1;
		if(lst0==-1){
			hav0=n-fir0+1;
			if(hav1>=hav0){
				for(int i=fir1;i<=n;i++){
					cout<<1;
				}
				cout<<"\n";
			}
			else{
				hav1*=2;
				for(int i=1;i<=hav1;i++){
					cout<<1;
				}
				hav1=hav0-hav1/2;
				for(int i=1;i<=hav1;i++){
					cout<<0;
				}
				cout<<"\n";
			}
			continue;
		}
		if(hav1>hav0){
			string s2=" ";
			for(int i=1;i<=lst1;i++){
				s2+='0';
			}
			s2+=s.substr(fir0-hav0,n-lst1);
			for(int i=fir1;i<=n;i++){
				if(s[i]==s2[i]){
					cout<<0;
				}
				else{
					cout<<1;
				}
			}
			cout<<endl;
		}
		else{
			string s2=" ";
			for(int i=1;i<=lst1;i++){
				s2+='0';
			}
			s2+=s.substr(fir1,n-lst1);
			for(int i=fir1;i<=n;i++){
				if(s[i]==s2[i]){
					cout<<0;
				}
				else{
					cout<<1;
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
