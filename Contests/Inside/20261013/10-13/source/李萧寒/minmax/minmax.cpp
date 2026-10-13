#include<bits/stdc++.h>
using namespace std;
int x[100005],y[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("minmax.in","r",stdin);
	freopen("minmax.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=m;i++){
		cin>>y[i];
	}
	int now=1;
	bool bigflag=true;
	for(int i=1;i<=m;i++){
		bool flag=false;
		for(;now<=n;now++){
			if(x[now]==y[i]){
				flag=true;
				break;
			}
		}
		if(flag){
			now++;
		}
		else{
			cout<<"No"<<endl;
			bigflag=false;
			break;
		}
	}
	if(bigflag)
	cout<<"Yes"<<endl;
	}
	return 0;
}
