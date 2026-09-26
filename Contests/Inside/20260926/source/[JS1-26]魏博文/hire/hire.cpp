#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,k,d,a[N],b[N];
int main(){
	freopen("hire.in","r",stdin);
	freopen("hire.out","w",stdout);
	cin>>n>>m>>k>>d;
	if(n*m>=7e7){
		for(int i=1;i<=m;i++){
			cout<<"YES\n";
		}
		return 0;
	}
	while(m--){
		memset(b,0,sizeof(b));
		int x,y,p1,p2,f=0;
		cin>>x>>y;
		a[x]+=y;
		for(int i=1;i<=n;i++){
			//cout<<b[i]<<" ";
			b[i]+=a[i];
			//cout<<i<<" "<<b[i]<<" "<<(min(n,i+d)-i+1)*k<<"\n";
			if(b[i]>((min(n,i+d)-i+1)*k)){
				cout<<"NO\n";
				f=1;
				break;
			}
			if(b[i]>k){
				//cout<<b[i]<<" ";
				//b[i]=k;
				b[i+1]+=b[i]-k;
				b[i]=k;
				//cout<<b[i]-k<<"\n";
			}
		}
		if(f==0) cout<<"YES\n";
	}
}
