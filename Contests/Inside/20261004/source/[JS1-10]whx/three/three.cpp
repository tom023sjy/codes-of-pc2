#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,a[5010],b[5010];
int main(){
	freopen("three.in","r",stdin);
	freopen("three.out","w",stdout);
	cin>>n>>m;
	int aa=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]%4==0){
			aa=0;
		}
	}
	sort(a+1,a+1+n);
	if(m<=3){
		int cnt=3,sum=0;
		for(int i=1;i<=n;i++){
			b[a[i]]++;
		}
		if(b[1]==0){
			if(b[2]%3==0&&b[3]%3==0){
				cout<<1;
				return 0;
			}
		}
		while(b[1]>=0){
			if(b[2]>=b[1]&&(b[2]-b[1])%3==0&&b[3]>=b[1]&&(b[3]-b[1])%3==0){
				sum++;
				sum%=mod;
			}
			b[1]-=cnt;
		}
		cout<<sum<<'\n';
		return 0;
	}
	if(aa==1){
		int cnt=3,sum=0,ans=1;
		for(int i=1;i<=n;i++){
			b[a[i]]++;
		}
		int k=1;
		while(k<=m){
			if(b[k]>0||b[k+1]>0||b[k+2]>0){
				if(b[k]==0){
					if(b[k+1]%3==0&&b[k+2]%3==0){
						ans*=1;
					}else{
						cout<<0;
						return 0;
					}
					continue;
				}
				while(b[k]>=0){
					if(b[k+1]>=b[k]&&(b[k+1]-b[k])%3==0&&b[k+2]>=b[k]&&(b[k+2]-b[k])%3==0){
						sum++;
						sum%=mod;
					}
					b[k]-=cnt;
				}
				ans*=sum;
				ans%=mod;
				sum=0;
			}
			k+=4;
		}
		cout<<ans<<'\n';
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i+1]>=a[i]&&a[i+2]>=a[i]){
			a[i+1]-=a[i];
			a[i+2]-=a[i];
		}else{
			cout<<0<<'\n';
			return 0;
		}
	}
	cout<<1<<'\n';
	return 0;
}
