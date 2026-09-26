#include <iostream>
using namespace std;
long long n,aw=1,a[30000];
long long k(long long a,long long b){
	long long an=1;
	while(b){
		if(b&1){
			an*=a;
			an%=998244353;
		}
		b>>=1;
		a*=a;
		a%=998244353;
	}
	return an;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	cin>>n;
	a[0]=1;
	for(long long i=1;i<=n;i++){
		for(long long j=20100;j>=i;j--){
			a[j]+=a[j-i];
			a[j]%=998244352;
		//	w=max(w,a[j]);
		}
	}
	for(long long i=1;i<=20100;i++){
	//	cout<<a[i]<<','<<i<<" ";
		aw=aw*k(i,a[i])%998244353;
	}
	cout<<aw;
//	for(long long i=0;i<=6;i++){
//		cout<<a[i];
//	}
//	for(long long i=1;i<=n;i++){
//		
//	}
	return 0;
}
//a^(p-1)=1
//
