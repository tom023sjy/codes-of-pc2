#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int cid,n,h,w,maxx,cnt[15][15],ans[15][15],sum;
bool fl[9][15][15],id3=1;
struct node{
	int x,y,xx,yy,c;
}a[100005];
void dfs(int d){
	if(d==n+1){
		int now=0;
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				int t=ans[i][j];
				if(t)now+=t*(t-1)/2;
			}
		}
		maxx=max(maxx,now);
		return;
	}
	int mx=0,idx=0,idy=0;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(fl[d][i][j]){
				int sz=cnt[i][j];
				if(sz>mx){
					mx=sz;
					idx=i,idy=j;
				}
			}
		}
	}
	ans[idx][idy]+=a[d].c;
	dfs(d+1);
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>cid>>n>>h>>w;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].xx>>a[i].yy>>a[i].c;
		if(a[i].x==1&&a[i].y==1)id3=0;
		sum+=a[i].c;
		if(1<=cid&&cid<=8){
			for(int j=1;j<=h;j++){
				for(int k=1;k<=w;k++){
					if(j<a[i].x||j>a[i].xx||k<a[i].y||k>a[i].yy){
						//cout<<j<<' '<<k<<"\n";
						cnt[j][k]+=a[i].c;
						fl[i][j][k]=1;
					}
				}
			}
		}
	}
	if(1<=cid&&cid<=8){
		dfs(1);
		cout<<maxx;
		return 0;
	}
	if(id3)cout<<sum*(sum-1)/2;
	else cout<<0;
	return 0;
}
