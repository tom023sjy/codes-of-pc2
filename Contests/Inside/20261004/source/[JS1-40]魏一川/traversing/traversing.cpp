#include<bits/stdc++.h>
using namespace std;
struct node{
	int ls,rs;
	int tag;
}a[100005];
int n,q,cnt,anss;
int solve(int rt,int ans){
	if(anss)return 0;
	if(a[rt].ls==0&&a[rt].rs==0){
		cnt++;
		if(rt==ans&&anss==0)return anss=cnt;
		else return 0;
	}
	if(a[rt].tag==-1){
		cnt++;
		if(rt==ans&&anss==0)return anss=cnt;
		if(a[rt].ls&&anss==0){
			int left=solve(a[rt].ls,ans);
			if(left)return anss=left;
		}
		if(a[rt].rs&&anss==0){
			int right=solve(a[rt].rs,ans);
			if(right)return anss=right;
		}
	}
	if(a[rt].tag==0){
		if(a[rt].ls&&anss==0){
			int left=solve(a[rt].ls,ans);
			if(left)return anss=left;
		}
		cnt++;
		if(rt==ans&&anss==0)return anss=cnt;
		if(a[rt].rs&&anss==0){
			int right=solve(a[rt].rs,ans);
			if(right)return anss=right;
		}
	}
	if(a[rt].tag==1){
		if(a[rt].ls&&anss==0){
			int left=solve(a[rt].ls,ans);
			if(left)return anss=left;
		}
		if(a[rt].rs&&anss==0){
			int right=solve(a[rt].rs,ans);
			if(right)return anss=right;
		}
		cnt++;
		if(rt==ans&&anss==0)return anss=cnt;
	}
}
int main(){
	freopen("traversing.in","r",stdin);
	freopen("traversing.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].ls,&a[i].rs);
		a[i].tag=-1;
	}
	while(q--){
		int t;
		scanf("%d",&t);
		if(t==1){
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			for(int i=l;i<=r;i++)a[i].tag=x;
		}
		else{
			int i;
			scanf("%d",&i);
			anss=0,cnt=0;
			solve(1,i);
			cout<<anss<<"\n";
		}
	}
	return 0;
}
