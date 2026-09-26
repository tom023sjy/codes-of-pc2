#include<bits/stdc++.h>
using namespace std;
int n;
string s;
#define int long long
#define md 1000000007
int f[505],inf[550];
int poww(int a,int b){
	int res=1;
	while(b){
		if (b&1) res=(res*a)%md;
		b>>=1;
		a=(a*a)%md;
	}
	return res;
}
void init(){
	f[1]=1;
	for (int i=2;i<=500;i++) f[i]=(f[i-1]*i)%md;
	inf[500]=poww(f[500],md-2);
	for (int i=499;i>0;i--) inf[i]=(inf[i+1]*i)%md;
}
signed main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>s;
	int cnt1=0;
	for (int i=1;i<=n;i++) cnt1+=(s[i-1]=='1');
	int cnt0=n-cnt1,cnt2=cnt1/2;
	int down=cnt0+cnt2,up=cnt2;
	init();
	cout<<f[down]*poww(f[down-up],md-2)%md*poww(f[up],md-2)%md;
	return 0;
}
