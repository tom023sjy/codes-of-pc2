#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;
const int N=205;
int n;
ll f[N][N*N];
long long ans=1;
const int Mod=998244353;
ll qp(ll x,ll k){
	ll res=1;
	while(k){
		if(k&1) (res*=x)%=Mod;
		k>>=1;
		(x*=x)%=Mod;
	}
	return res;
}
int main(){
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	scanf("%d",&n);
	f[1][0]=1;
	for(int i=1;i<=n;++i)
	for(int j=0;j<=n*(n+1)/2;++j){
		if(!f[i][j]) continue;
		f[i+1][j]+=f[i][j];
		f[i+1][j+i]+=f[i][j];
	}
	for(int i=1;i<=n*(n+1)/2;++i) (ans*=qp(i,f[n+1][i]))%=Mod;
	printf("%lld",ans);
	return 0;
} 
