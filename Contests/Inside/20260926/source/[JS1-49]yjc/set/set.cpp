#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int cnt[400005],n;
int ksm(int a,int b){
	int k=1;
	while(b){
		if(b%2)k=k*a%mod;
		a=a*a%mod;b>>=1;
	}
	return k%mod;
}
signed main(){
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	scanf("%lld",&n);
	cnt[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=i*(i+1)/2;j>=i+1;j--){
			cnt[j]=cnt[j]+cnt[j-i];
			if(cnt[j]>mod) cnt[j]-=mod-1; 
		}
		cnt[i]++;
	}
	int ans=1;
	for(int i=1;i<=n*(n+1)/2;i++){
//		cout<<i<<" "<<cnt[i]<<endl;
		ans=ans*ksm(i,cnt[i])%mod;
	}
	printf("%lld",ans);
	return 0;
}
