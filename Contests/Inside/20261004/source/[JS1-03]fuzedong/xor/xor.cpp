#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
int n;
const int N=1e7+5;
bool s1[N],s2[N];
string s;
void test11(int tot,int tot1){
	cout<<"tot=="<<tot<<" tot1=="<<tot1<<'\n';
	for(int i=1;i<=tot;i++)cout<<s1[i];
	cout<<'\n';
	for(int i=1;i<=tot1;i++)cout<<s2[i];
	cout<<'\n';
}
void sbccf(){
	cin>>n;
	int tot=0,flag=0,fst0=0,cnt0=0,tot0=0;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		if(flag==0&&(s[i]-'0')){
			flag=1;
		}
		if(flag){
			s1[++tot]=s[i]-'0';
			if(s[i]=='0')tot0++;
		}
	}
	for(int i=1;i<=tot;i++){
		if(s1[i]==0&&fst0==0)fst0=i;
		else if(s1[i]==1&&fst0&&cnt0==0)cnt0=i-fst0;
	}
	if(tot<=1){
		cout<<tot<<'\n';
		return;
	}
	if(tot==n&&tot0==0){
		for(int i=1;i<n;i++){
			cout<<s[i];
		}
		cout<<"0\n";
		return;
	}
	int tot1=0;
	if(cnt0==0)cnt0=tot+1-fst0;
	for(int i=max(1ll,fst0-cnt0);tot1<tot-fst0+1;i++){
		s2[++tot1]=s1[i];
	}
//	cout<<"fst0=="<<fst0<<" cnt0=="<<cnt0<<'\n';
//	test11(tot,tot1);
	for(int i=tot,j=tot1;j>=1;j--,i--){
		s1[i]^=s2[j];
	}
	for(int i=1;i<=tot;i++){
		cout<<s1[i];
	}
	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	freopen("ex_xor3.in","r",stdin);
	cin>>T;
	while(T--){
		sbccf();
	}
	return 0;
}
