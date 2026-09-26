#include<bits/stdc++.h>
using namespace std;
int n,m,k,d;
struct TREENODE{
	int v,l,r,len,ls,rs;
} t[2000010];
void pushup(int id){
	t[id].ls=(t[id*2].ls==t[id*2].len && (0<=t[id*2+1].l) ? t[id*2].ls+t[id*2+1].ls : t[id*2].ls);
	t[id].l=(t[id*2].ls==t[id*2].len ? max(t[id*2].l+t[id*2+1].l,t[id*2].l) : t[id*2].l);
	t[id].rs=(t[id*2+1].rs==t[id*2+1].len && (0<=t[id*2].r) ? t[id*2+1].rs+t[id*2].rs : t[id*2+1].rs);
	t[id].r=(t[id*2+1].rs==t[id*2+1].len ? max(t[id*2+1].r+t[id*2].r,t[id*2+1].r ): t[id*2+1].r);
	t[id].len=t[id*2].len+t[id*2+1].len;
	t[id].v=max(t[id*2].r+t[id*2+1].l,max(t[id*2].v,t[id*2+1].v));
}

void build(int id,int l,int r){
	if (l==r){
		t[id].ls=t[id].rs=t[id].len=1;
		t[id].l=t[id].r=t[id].v=-k;
		return ;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	pushup(id);
}
void update(int id,int l,int r,int x,int p){
	if (l==r) {
		t[id].l+=p,t[id].r+=p;
		t[id].v+=p;
		return ;
	}
	int mid=(l+r)/2;
	if (x<=mid) update(id*2,l,mid,x,p);
	else update(id*2+1,mid+1,r,x,p);
	pushup(id); 
//	cout<<id<<" "<<t[id].l<<" "<<t[id].r<<" "<<t[id].ls<<" "<<t[id].rs<<" "<<t[id].v<<" "<<t[id].len<<"\n";
}
int  main(){
	freopen("hire.in","r",stdin);
	freopen("hire.out","w",stdout);
	cin>>n>>m>>k>>d;
	build(1,1,n);
	while(m--){
		int x,y;
		cin>>x>>y;
		update(1,1,n,x,y);
		if (t[1].v>k*d) cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}
