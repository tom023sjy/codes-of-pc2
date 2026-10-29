#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("guess.in","r",stdin);
	freopen("guess.out","w",stdout);
	cin>>T;
	while(T--){
		unsigned long long m;
		cin>>m;
		for(int n=1;;n++){
			unsigned long long sum=0;
			for(int i=1;i<=n;i++)if(__gcd(i,n)==1)sum+=i;
			if(sum==m){
				cout<<n<<'\n';
				break;
			}
			//cout<<sum<<'\n';
		}
	}
	return 0;
}
