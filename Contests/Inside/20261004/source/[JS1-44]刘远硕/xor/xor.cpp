#include<bits/stdc++.h>
using namespace std;
int n,t;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>t;
	if (t<=10){
		bitset <10000005> bs1;
		bitset <10000005> bs2;
		bitset <10000005> bs3;
		bitset <10000005> bs4;
		while(t--){
			bs4.reset();
			bs2.reset();
			bs1.reset();
			cin>>n>>s;
			s="%"+s;
			int pos=0;
			if (s=="1") {
				cout<<"0\n";
				continue;
			}
			for (int i=1;i<=n;i++) {
				if (s[i]!='0'){
					n-=i-1;
					s=s.substr(i);
					break;
				} 
			}
			if (s[0]=='%') {
				cout<<0<<"\n";
				continue;
			}
			s="r"+s;
//		cout<<s<<"\n";
			for (int i=n,j=1;i>=1;i--,j++){
				if (s[i]!='0') bs1.set(j);
//			cout<<bs1<<" "<<i<<" "<<j<<"\n";
			}	
			for (int i=1;i<=n;i++) {
				if (s[i]=='0'){
					pos=i;
					break;
				} 
			}
			if (s=="r1") cout<<1;
			else if (pos==0) cout<<s.substr(2)<<0;
			else {
				int i;
				for (i=n-pos+1;i>=1;i--) bs2[i]=bs1[i]; 
				for (i=n-pos+2;i<=n+1;i++){
					bs3=bs2^bs1;
//				cout<<bs1<<" "<<bs2<<" "<<bs3<<" "<<bs4<<" "<<pos<<"\n";
					if (bs3.to_string()>bs4.to_string()) bs4=bs3;
					bs2>>=1;
					bs2[n-pos+1]=bs1[i];
				}
				int f=0;
				string ans=bs4.to_string();
				for (int i=(int)(ans.size()-1-s.size());i<(int)(ans.size()-1);i++){
					if (ans[i]!='0' || f){
						f=1;
						cout<<ans[i];
					}
				}
			}
			
			cout<<endl;
		}
	}
	else if (t<=50){
		bitset <1000005> bs1;
		bitset <1000005> bs2;
		bitset <1000005> bs3;
		bitset <1000005> bs4;
		while(t--){
			bs4.reset();
			bs2.reset();
			bs1.reset();
			cin>>n>>s;
			s="%"+s;
			int pos=0;
			if (s=="1") {
				cout<<"0\n";
				continue;
			}
			for (int i=1;i<=n;i++) {
				if (s[i]!='0'){
					n-=i-1;
					s=s.substr(i);
					break;
				} 
			}
			if (s[0]=='%') {
				cout<<0<<"\n";
				continue;
			}
			s="r"+s;
//		cout<<s<<"\n";
			for (int i=n,j=1;i>=1;i--,j++){
				if (s[i]!='0') bs1.set(j);
//			cout<<bs1<<" "<<i<<" "<<j<<"\n";
			}	
			for (int i=1;i<=n;i++) {
				if (s[i]=='0'){
					pos=i;
					break;
				} 
			}
			if (s=="r1") cout<<1;
			else if (pos==0) cout<<s.substr(2)<<0;
			else {
				int i;
				for (i=n-pos+1;i>=1;i--) bs2[i]=bs1[i]; 
				for (i=n-pos+2;i<=n+1;i++){
					bs3=bs2^bs1;
//				cout<<bs1<<" "<<bs2<<" "<<bs3<<" "<<bs4<<" "<<pos<<"\n";
					if (bs3.to_string()>bs4.to_string()) bs4=bs3;
					bs2>>=1;
					bs2[n-pos+1]=bs1[i];
				}
				int f=0;
				string ans=bs4.to_string();
				for (int i=(int)(ans.size()-1-s.size());i<(int)(ans.size()-1);i++){
					if (ans[i]!='0' || f){
						f=1;
						cout<<ans[i];
					}
				}
			}
			
			cout<<endl;
		}
	}else {
		bitset <200005> bs1;
		bitset <200005> bs2;
		bitset <200005> bs3;
		bitset <200005> bs4;
		while(t--){
			bs4.reset();
			bs2.reset();
			bs1.reset();
			cin>>n>>s;
			s="%"+s;
			int pos=0;
			if (s=="1") {
				cout<<"0\n";
				continue;
			}
			for (int i=1;i<=n;i++) {
				if (s[i]!='0'){
					n-=i-1;
					s=s.substr(i);
					break;
				} 
			}
			if (s[0]=='%') {
				cout<<0<<"\n";
				continue;
			}
			s="r"+s;
//		cout<<s<<"\n";
			for (int i=n,j=1;i>=1;i--,j++){
				if (s[i]!='0') bs1.set(j);
//			cout<<bs1<<" "<<i<<" "<<j<<"\n";
			}	
			for (int i=1;i<=n;i++) {
				if (s[i]=='0'){
					pos=i;
					break;
				} 
			}
			if (s=="r1") cout<<1;
			else if (pos==0) cout<<s.substr(2)<<0;
			else {
				int i;
				for (i=n-pos+1;i>=1;i--) bs2[i]=bs1[i]; 
				for (i=n-pos+2;i<=n+1;i++){
					bs3=bs2^bs1;
//				cout<<bs1<<" "<<bs2<<" "<<bs3<<" "<<bs4<<" "<<pos<<"\n";
					if (bs3.to_string()>bs4.to_string()) bs4=bs3;
					bs2>>=1;
					bs2[n-pos+1]=bs1[i];
				}
				int f=0;
				string ans=bs4.to_string();
				for (int i=(int)(ans.size()-1-s.size());i<(int)(ans.size()-1);i++){
					if (ans[i]!='0' || f){
						f=1;
						cout<<ans[i];
					}
				}
			}
			
			cout<<endl;
		}
	}
	return 0;
}
