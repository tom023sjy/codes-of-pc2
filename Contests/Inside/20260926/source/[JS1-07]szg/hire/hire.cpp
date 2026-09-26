#include<bits/stdc++.h>
using namespace std;
int a[2005],b[2005],now[2005];
int n,m,k,d;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hire.in","r",stdin);
	freopen("hire.out","w",stdout);
	cin>>n>>m>>k>>d;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		a[x]+=y;
		int fl=0;
		for(int j=1;j<=n;j++)b[j]=a[j];
		for(int j=1;j<=n;j++)now[j]=k;
		for(int j=1;j<=n;j++){	
			for(int u=j;u<=min(n,j+d);u++){
	//			cout<<b[j]<<" "<<u<<"\n";
				if(b[j]>=now[u]){
				b[j]-=now[u],now[u]=0;
		//		cout<<b[j]<<"\n";
				}
				else {
					now[u]-=b[j],b[j]=0;
					u--;
					break;
				}
			}
		//	for(int kk=1;kk<=n;kk++)cout<<b[kk]<<" ";
		//	cout<<"\n";
		}
		for(int j=1;j<=n;j++){
	//		cout<<b[j]<<" ";
			if(b[j]!=0)fl=1;
		}
		if(fl)cout<<"NO";
		else cout<<"YES";
		cout<<"\n";
	}
	return 0;
} 
