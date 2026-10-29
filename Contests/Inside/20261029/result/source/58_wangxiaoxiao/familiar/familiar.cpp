#include <bits/stdc++.h>
using namespace std;
int n,m,T,a[1010][1010];
vector<int>v[1010];
int main(){
	freopen("familiar.in","r",stdin);
	freopen("familiar.out","w",stdout);
	cin>>n>>m>>T;
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
		v[i].assign(a[i],a[i]+m);
		sort(v[i].begin(),v[i].end());
	}
	while(T--){
		int op;
		cin>>op;
		if(op==1){
			int x,y,k,lo=1,hi=1e9,ans=0;
			cin>>x>>y>>k;
			while(lo<=hi){
				int mid=(lo+hi)/2;
				int c=(v[x].end()-lower_bound(v[x].begin(),v[x].end(),mid))+(v[y].end()-lower_bound(v[y].begin(),v[y].end(),mid));
				if(c>=k){
					ans=mid;
					lo=mid+1;
				}
				else{
					hi=mid-1;
				}
			}
			cout<<ans<<'\n';
		}
		else{
			int x,y;
			cin>>x>>y;
			int p=-1;
			for(int j=m-1;j>=0;j--){
				if(a[x][j]<y){
					p=j;
					break;
				}
			}
			if(p!=-1){
				int old=a[x][p];
				a[x][p]=y;
				v[x].erase(lower_bound(v[x].begin(),v[x].end(),old));
				v[x].insert(lower_bound(v[x].begin(),v[x].end(),y),y);
			}
		}
	}
	return 0;
}
