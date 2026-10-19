#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int cid,n,a[11],ans[11],pow2[5005];
char c[5005];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("mountain.in","r",stdin);
	freopen("mountain.out","w",stdout);
	cin>>cid>>(c+1);
	n=strlen(c+1);
	if(cid==10){
		pow2[0]=1;
		cout<<"1 ";
		for(int i=1;i<n-1;i++){
			pow2[i]=pow2[i-1]*2%mod;
			cout<<pow2[i]<<' ';
		}
		cout<<1;
		return 0;
	}
	if(cid==11){
		cout<<"1 ";
		pow2[0]=1;
		for(int i=1;i<n-1;i++)pow2[i]=pow2[i-1]*2%mod;
		for(int i=n-2;i>=0;i--)cout<<pow2[i]<<' ';
		return 0;
	}
	if(cid==12||cid==13){
		for(int i=1;i<=n;i++)cout<<"0 ";
		return 0;
	}
	for(int i=1;i<=n;i++)a[i]=i;
	do{
		bool fl=1;
		for(int i=2;i<=n;i++){
			if(c[a[i-1]]=='U'){
				if(a[i]<a[i-1]){
					fl=0;
					break;
				}
			}
			else{
				if(a[i]>a[i-1]){
					fl=0;
					break;
				}
			}
		}
		if(fl)ans[a[n]]++;
	}while(next_permutation(a+1,a+n+1));
	for(int i=1;i<=n;i++)cout<<ans[i]%mod<<' ';
	return 0;
}
