#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
	ll n,k;
	cin>>n>>k;
	ll sum=0;
	for(int i=0;i<=30;i++){//这里的i就是t
		ll p=((1ll<<i)-1)<<k;
		if(p>n)continue;
		for(int j=30;j>=0;j--){
			if(j>=k&&j<=k+i)continue;
			if(p+(1ll<<j)<=n){
				p+=(1ll<<j);
			}
		}
        ll a=p>>(i+k+1),b=p%(1ll<<k);
		ll q1=a<<k;
		ll q2=b+1;
        cerr<<q1<<" "<<q2<<'\n';
		sum+=(q1+q2)*(((1ll<<(i+1))-1)<<k);
	}
	cout<<sum<<"\n";
}
int main(){
	int t;
	cin>>t;
	while(t--)solve();
    return 0;
}
