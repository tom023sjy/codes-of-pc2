#include <bits/stdc++.h>
using namespace std;
int T,n,a[20000000],l,r,ma,c[20000000],mb=1;
bool b[11000000];
//string b="!abab#ababab";
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);//fc xor.out ex_xor1.out
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>T;
	while(T--){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	ma=0;
	mb=1;
	l=r=0;
	cin>>n;
//	n=11;
	for(int i=1;i<=n;i++){
		char f;
		cin>>f;
		if(f=='1')b[i]=1;
		else b[i]=0;
//		cin>>b[i];
	}
//		cout<<b[2]<<' ';
	bool g=0;
	int u=n;
	for(int i=1;i<=n;i++){
	//	cout<<b[i]<<' ';
		g|=b[i];
		if(b[i]==0&&g){
			u=i;
			break;
		}
	}
	for(int i=u;i<=n;i++){
		c[i-u+1]=b[i];
	//	cout<<i<<' '<<b[i]<<',';
	}
	c[n-u+2]=114;
	for(int i=n-u+3;i<=n-u+2+n;i++){
		c[i]=!b[i-(n-u+3)+1];
	}
	int m=n-u+2+n;
	for(int i=n-u+3;i<=n+2;i++){
	//	cout<<c[i]<<":";
		if(r>=i){
			a[i]=min(a[i-l+1],a[l]+l-i);
		}
	//cout<<a[l]+l-i+1<<' '<<a[i]<<' ';
		while(c[i+a[i]]==c[a[i]+1]&&i+a[i]<=m){
			a[i]++;
		}
		if(i+a[i]-1>r){
			r=i+a[i]-1;
			l=i;
		}
		if(a[i]>ma){
			ma=a[i];
			mb=i-(n-u+3)+1;
		}
//		cout<<a[i]<<' ';
	}
	int p=0;
	for(int i=1;i<u;i++){
		p|=b[i];
		if(p){
			cout<<b[i];
		}
	}
	for(int i=1;i<=n-u+1;i++){
		cout<<(b[mb+i-1]^b[i+u-1]);
	}
	cout<<'\n';
//	cout<<u<<' '<<ma<<" "<<mb<<' ';
	}
	return 0;
}
/*194
00000100000000000010000000000101000000000010000010000000010000000000111000000000000000000000000000010000010000010000000000000000000000001000001001000000000000000000000000000010000000000000000000
*/
