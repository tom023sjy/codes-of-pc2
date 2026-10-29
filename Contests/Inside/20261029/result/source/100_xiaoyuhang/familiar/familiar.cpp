#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int a[N][N];
int n,m,T;
int main(){
	freopen("familiar.in","r",stdin);
 	freopen("familiar.out","w",stdout);
 	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>T;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	for(int i=1;i<=n;i++) a[i][m+1]=1e9;
	while(T--){
		int opt,x,y,K;
		cin>>opt>>x>>y;
		if(opt==1){
			cin>>K;
			int l=max(1,m-K+1),r=min(m+1,2*m-K+1),ans=0;
			while(l<=r){
				int mid=l+r>>1;
				int to=K-(m-mid+1);
				to=m-to+1;
				if(a[x][mid]<a[y][to]){
					if(a[y][to-1]>a[x][mid]){
						l=mid+1;
					}
					else{
						ans=a[x][mid];
						break;
					}
				}
				else if(a[x][mid]>a[y][to]){
					if(a[x][mid-1]>a[y][to]){
						r=mid-1;
					}
					else{
						ans=a[y][to];
						break;
					}
				}
				else{
					ans=a[x][mid];
					break;
				}
			}
			cout<<ans<<"\n";
		}
		else{
			int l=1,r=m,pos=0;
			while(l<=r){
				int mid=l+r>>1;
				if(a[x][mid]<=y) pos=mid,l=mid+1;
				else r=mid-1;
			}
			if(pos>0) a[x][pos]=y;
		}
	}
	return 0;
}
/*
3 3 5
2 6 7
1 4 9
3 5 8
1 1 2 3
1 2 3 1
2 3 12
1 2 3 1
1 1 3 5
*/
