#include<bits/stdc++.h>
using namespace std;
int n,a[500005],b[500005],fl_3=1,fl_4=1;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("maxmin.in","r",stdin);
	freopen("maxmin.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			fl_3=0;
			break;
		}
	}
	if(fl_3){
		cout<<n;
		for(int i=2;i<=n;i++)cout<<" 0";
		return 0;
	}
	for(int i=1;i<n;i++)cout<<"2 ";
	cout<<0;
	return 0;
}
