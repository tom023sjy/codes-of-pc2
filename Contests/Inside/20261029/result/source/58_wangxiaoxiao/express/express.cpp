#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000010,inf=(1LL<<62);
int n,k[N],xs[N],s=0,ans=inf,tr[2][N*4],P=1;
void build(){
	for(int i=0;i<2;i++){
		for(int j=0;j<N*4;j++){
			tr[i][j]=inf;
		}
	}
	P=1;
	while(P<=n+2){
		P<<=1;
	}
}
void update(int op,int x,int val){
	tr[op][x+P]=min(tr[op][x+P],val);
	for(x=(x+P)>>1;x;x>>=1){
		tr[op][x]=min(tr[op][x<<1],tr[op][x<<1|1]);
	}
}
int query(int op,int l,int r){
	if(r<l){
		return inf;
	}
	int res=inf;
	l+=P-1;
	r+=P+1;
	while(l^1^r){
		if(-l&1){
			res=min(res,tr[op][l^1]);
		}
		if(r&1){
			res=min(res,tr[op][r^1]);
		}
		l>>=1;
		r>>=1;
	}
	return res;
}
signed main(){
	freopen("express.in","r",stdin);
	freopen("express.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	xs[0]=0;
	for(int i=1;i<=n;i++){
		xs[i]=k[i];
	}
	sort(xs,xs+n+1);
	for(int i=1;i<=n;i++){
		k[i]=lower_bound(xs+1,xs+n+2,k[i])-xs;
	}
	build();
	update(0,1,xs[k[1]]-xs[1]);
	update(1,1,xs[k[1]]+xs[1]);
	ans=xs[k[1]];
	for(int i=2;i<=n;i++){
		int l=query(0,1,k[i])+xs[k[i]],r=query(1,k[i]+1,n+1)-xs[k[i]],val=min(l,r)+s;
		s+=abs(xs[k[i]]-xs[k[i-1]]);
		ans=min(ans,val-s);
		update(0,k[i-1],val-s-xs[k[i-1]]);
		update(1,k[i-1],val-s+xs[k[i-1]]);
	}
	cout<<ans+s;
	return 0;
}