#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) p*2
#define rs(p) p*2+1
inline int maxx(int a,int b){
	return a>b?a:b;
}
int sum[2000005],ma[2000005],lma[2000005],rma[2000005];
int n,m,k,d;
void push_up(int p){
	sum[p]=sum[ls(p)]+sum[rs(p)];
	lma[p]=maxx(lma[ls(p)],sum[ls(p)]+lma[rs(p)]);
	rma[p]=maxx(rma[rs(p)],sum[rs(p)]+rma[ls(p)]);
	ma[p]=maxx(ma[ls(p)],maxx(ma[rs(p)],rma[ls(p)]+lma[rs(p)]));
}
void build(int p,int l,int r){
	if(l==r){
		sum[p]=-k;
		return;
	}
	int mid=(l+r)/2;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
void update(int p,int l,int r,int w,int x){
	if(l==w&&l==r){
		sum[p]+=x;
		lma[p]=maxx(sum[p],0);
		rma[p]=maxx(sum[p],0);
		ma[p]=maxx(sum[p],0);
		return;
	}
	int mid=(l+r)/2;
	if(w<=mid){
		update(ls(p),l,mid,w,x);
	}
	else{
		update(rs(p),mid+1,r,w,x);
	}
	push_up(p);
}
int query(){
	return ma[1];
}
signed main(){
	freopen("hire.in","r",stdin);
	freopen("hire.out","w",stdout);
	cin>>n>>m>>k>>d;
	build(1,1,n);
	while(m--){
		int a,b;
		cin>>a>>b;
		update(1,1,n,a,b);
		if(query()-d*k>0){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
