#include<bits/stdc++.h>
using namespace std;
int n,m,T;
int main(){
	freopen("familiar.in","r",stdin);
	freopen("familiar.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	vector<vector<int> >a(n+1,vector<int>(m));
	for(int i=1;i<=n;i++)for(int j=0;j<m;j++)scanf("%d",&a[i][j]);
	while(T--){
		int opt,x,y;
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==1){
			int k;
			scanf("%d",&k);
			int z=m*2-k+1;
			int l=min(a[x][0],a[y][0]),r=max(a[x][m-1],a[y][m-1]),ans=r;
			while(l<=r){
				int mid=(l+r)>>1;
				int cnt=(upper_bound(a[x].begin(),a[x].end(),mid)-a[x].begin())+(upper_bound(a[y].begin(),a[y].end(),mid)-a[y].begin());
				if(cnt>=z){
					ans=mid;
					r=mid-1;
				}
				else l=mid+1;
			}
			cout<<ans<<'\n';
		}
		else{
			auto it=upper_bound(a[x].begin(),a[x].end(),y);
			if(it!=a[x].begin()){
				auto z=prev(it);
				*z=y;
			}
		}
	}
	return 0;
}
