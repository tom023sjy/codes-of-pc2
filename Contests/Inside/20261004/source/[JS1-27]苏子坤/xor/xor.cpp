#include<bits/stdc++.h>
using namespace std;
int n;
string s,ans="";
string _max(string a,string b){
	if(b.size()>a.size())swap(a,b);
	if(a.size()==b.size()){
		for(int i=0;i<a.size();i++){
			if(a[i]=='1'&&b[i]=='0')break;
			if(a[i]=='0'&&b[i]=='1'){
				swap(a,b);
				break;
			}
		}
	}
	return a;
}
string get(string aa,string bb){
	string ret=_max(aa,bb),ss=_max(aa,bb),a=aa,b=bb;
	for(int i=0;i<aa.size();i++){
		a[aa.size()-1-i]=aa[i];
	}
	for(int i=0;i<bb.size();i++){
		b[bb.size()-1-i]=bb[i];
	}
	for(int i=0;i<min(a.size(),b.size());i++){
		ret[i]=(a[i]!=b[i])+'0';
	}
	if(a.size()>b.size()){
		for(int i=b.size();i<a.size();i++)ret[i]=a[i];
	}
	else if(a.size()<b.size()){
		for(int i=a.size();i<b.size();i++)ret[i]=b[i];
	}
	for(int i=0;i<ret.size();i++){
		ss[ret.size()-1-i]=ret[i];
	}
	return ss;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int _;
	cin>>_;
	while(_--){
		cin>>n>>s;
		ans="";
		for(int l1=0;l1<n;l1++){
			for(int r1=1;l1+r1-1<n;r1++){
				for(int l2=0;l2<n;l2++){
					for(int r2=1;l2+r2-1<n;r2++){
						string aa=s.substr(l1,r1),bb=s.substr(l2,r2);
						ans=_max(get(aa,bb),ans);
					}
				}
			}
		}
		int t=0;
		while(t<ans.size()-1&&ans[t]=='0')t++;
		ans=ans.substr(t);
		cout<<ans<<'\n';
	}
	return 0;
}
