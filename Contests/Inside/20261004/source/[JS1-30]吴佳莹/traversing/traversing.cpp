#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,q,a[N],ls[N],rs[N],p[N],s,ans;
void sol(int root){
	if(a[root]==-1){
	//	cout<<root;
		ans++;
		if(root==s) cout<<ans<<endl;
		if(ls[root]==0&&rs[root]==0) return;
		if(ls[root]) sol(ls[root]);
		if(rs[root]) sol(rs[root]);	
	}
	if(a[root]==0){
	
		if(ls[root])sol(ls[root]);
	//	cout<<root;
		ans++;
		if(root==s) cout<<ans<<endl;	
		if(ls[root]==0&&rs[root]==0) return;
		if(rs[root])sol(rs[root]);	
	}
	if(a[root]==1){
		
		if(ls[root])sol(ls[root]);
		if(rs[root])sol(rs[root]);	
		ans++;
		if(root==s) cout<<ans<<endl;
	//	cout<<root;
		if(ls[root]==0&&rs[root]==0) return;
	}
}

int main(){
	freopen("traversing.in","r",stdin);
	freopen("traversing.out","w",stdout);
	int root;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>ls[i]>>rs[i],p[ls[i]]=1,p[rs[i]]=1;
	for(int i=1;i<=n;i++) if(p[i]==0) root=i;
	for(int i=1;i<=n;i++) a[i]=-1;
	while(q--){
		int t,l,r,x;
		cin>>t;
		if(t==1){
			cin>>l>>r>>x;
			for(int i=l;i<=r;i++)a[i]=x;
		}
		else{
			ans=0;
			cin>>s;
			sol(root);
		}
	}
	return 0;
}
