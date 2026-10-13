#include<iostream>
#define int long long
using namespace std;

int n,a[500005],b[500005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("maxmin.in","r",stdin);
	freopen("maxmin.out","w",stdout);
	cin>>n;
	int flag=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(a[i]!=b[i]) flag=0;
	}
	if(flag){
		cout<<n<<" ";
		for(int i=1;i<n;i++) cout<<"0 ";
		return 0;
	}
	return 0;
}
