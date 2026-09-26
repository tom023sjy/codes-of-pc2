//set  100pts
#include<bits/stdc++.h>
using namespace std;
const int N=210;
const int mod=998244353;
int n;
int a[N];
long long b[20200];
inline long long qp(long long x,long long y){
	long long cnt=1;
	while(y>0){
		if(y&1)cnt*=x,cnt%=mod;
		x*=x;
		x%=mod;
		y>>=1;
	}
	return cnt;
}
int main(){
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	b[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=(n*(n+1))>>1;j>=1;j--){
			if(j-i>=0){
				b[j]+=b[j-i];
				if(b[j]>=mod-1)b[j]%=(mod-1);
			}
		}
	}
	/*for(int i=1;i<=n*(n+1)/2;i++){
		cout<<i<<"   "<<b[i]<<"\n";
	}*/
	long long ans=1;
	for(int i=2;i<=n*(n+1)/2;i++){
		ans*=qp(i,b[i]);
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
