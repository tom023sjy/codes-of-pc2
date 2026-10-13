#include<bits/stdc++.h>
using namespace std;
int x[500005],y[500005],cnt[500005],mi[500005],mi1[500005],ma[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("maxmin.in","r",stdin);
	freopen("maxmin.out","w",stdout);
	int n;
	bool flag=true;
	cin>>n;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		cin>>y[i];
		if(x[i]!=y[i]){
			flag=false;
		}
	}
	if(flag){
		cout<<n<<" ";
		for(int i=2;i<=n;i++){
			cout<<0<<" ";
		}
		return 0;
	}
	//i-1~i->max i~n->min
	mi[n]=y[n],mi1[1]=y[1];
	for(int i=n-1;i>=1;i--){
		mi[i]=min(mi[i+1],y[i]);
	}
	ma[1]=y[1];
	for(int i=2;i<=n;i++){
		mi1[i]=min(mi1[i-1],y[i]);
		ma[i]=max(ma[i-1],y[i]);
	}
	int l=max(mi1[n-1],y[n]),r=n;
//	cout<<n-r<<" "<<n-l<<endl;
	cnt[n-r]++,cnt[n-l+1]--;
	l=1,r=1;
	cnt[1-l]++,cnt[1-r+1]--;
//	cout<<1-l<<" "<<1-r<<endl;
	for(int i=2;i<n;i++){
		l=min(max(mi1[i-1],y[i]),mi[i+1]),r=min(mi[i+1],ma[i]);
//		cout<<i-r<<" "<<i-l<<endl; 
		cnt[i-r]++,cnt[i-l+1]--;
	}
	for(int i=1;i<n;i++){
		cnt[i]+=cnt[i-1];
	}
	for(int i=0;i<n;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
