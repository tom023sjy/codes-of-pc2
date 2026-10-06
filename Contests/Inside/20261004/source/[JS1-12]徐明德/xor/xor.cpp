//xor
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+10;
int n;
string ss;
inline void solve(){
	cin>>n;
	int fstcnt0=0;
	int fstcnt1=0;
	bool f0=0,f1=0;
	cin>>ss;
	ss=" "+ss;
	for(int i=1;i<=n;i++){
		if(ss[i]=='1'){
			if(f1==0){
				f1=1;
				fstcnt1=i;
			}
		}
		else{
			if(f0==0&&f1==1){
				f0=1;
				fstcnt0=i;
			}
		}
	}
	if(!fstcnt1){
		cout<<0<<'\n';
		return ;
	}
	if(!fstcnt0){
		for(int i=fstcnt1;i<n;i++){
			cout<<'1';
		}
		cout<<"0\n";
		return ;
	}
	for(int i=fstcnt1;i<fstcnt0;i++){
		cout<<'1';
	}
	for(int i=fstcnt0,j=fstcnt1;i<=n&&j<=n;i++,j++){
		if(ss[i]!=ss[j]){
			cout<<'1';
		}
		else cout<<'0';
	}
	cout<<'\n';
}
int main(){
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _;
	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}
