#include<bits/stdc++.h>
using namespace std;
#define int long long
const int P=998244353;
long long n,ans[205];
int mp[20105],tmp[20105];
int qpow(int a,int b){
	int res=1,cnt=a;
	while(b){
		if(b&1){
			res*=cnt;
			res%=P;
		}
		cnt*=cnt;
		cnt%=P;
		b>>=1;
	}
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	ans[1]=1;
	mp[1]=1;
	cin>>n;
	mp[0]=1;
	for(int i=2;i<=n;i++){
		int res=ans[i-1];
		for(int j=0;j<=(i-1)*i/2;j++){
//			if(mp[j]<0){
//				cout<<(long long)(i)<<'\n';
//				break;
//			}
			if(mp[j])tmp[j+i]=mp[j],res*=qpow(j+i,mp[j]),res%=P;
		}
		for(int j=0;j<=i*(i+1)/2;j++){
			if(tmp[j])mp[j]+=tmp[j];
			tmp[j]=0;
			if(mp[j]>=P-1)mp[j]%=(P-1);
		}
		ans[i]=res;
	}
//	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	cout<<ans[n]<<'\n';
	return 0;
}
