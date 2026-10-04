#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5; 
struct edge{
	int ls,rs;
};
int n,q;
edge e[N];
int num[N];
int fl[N];
int nw[N],tot;
void first(int u,int op);
void mid(int u,int op);
void lst(int u,int op);
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("traversing.in","r",stdin);
	freopen("traversing.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)fl[i]=1;
	for(int i=1;i<=n;i++){
		int l,r;
		cin>>l>>r;
		if(l!=0)e[i].ls=l;
		fl[l]=0;
		if(r!=0)e[i].rs=r;
		fl[r]=0;
	}
	int s=1;
	for(int i=1;i<=n;i++)if(fl[i]==1)s=i;
	for(int i=1;i<=q;i++){
		int op;
		cin>>op;
		if(op==1){
			int l,r,x;
			cin>>l>>r>>x;
			for(int i=l;i<=r;i++)num[i]=x;
		}else{
			int ii;
			cin>>ii;
			tot=1;
			memset(nw,0,sizeof(nw));
			if(num[s]==-1)first(s,ii);
			else if(num[s]==0)mid(s,ii);
			else lst(s,ii);
			cout<<nw[ii]<<"\n";
		}
	}
	return 0;
}
void first(int u,int op){
	
	nw[u]=tot++;if(u==op)return ;
	if(e[u].ls!=0){
		if(num[e[u].ls]==-1)first(e[u].ls,op);
		if(num[e[u].ls]==0)mid(e[u].ls,op);
		if(num[e[u].ls]==1)lst(e[u].ls,op);
	}
	if(e[u].rs!=0){
		if(num[e[u].rs]==-1)first(e[u].rs,op);
		if(num[e[u].rs]==0)mid(e[u].rs,op);
		if(num[e[u].rs]==1)lst(e[u].rs,op);
	}
}
void lst(int u,int op){
	if(e[u].ls!=0){
		if(num[e[u].ls]==-1)first(e[u].ls,op);
		if(num[e[u].ls]==0)mid(e[u].ls,op);
		if(num[e[u].ls]==1)lst(e[u].ls,op);
	}
	if(e[u].rs!=0){
		if(num[e[u].rs]==-1)first(e[u].rs,op);
		if(num[e[u].rs]==0)mid(e[u].rs,op);
		if(num[e[u].rs]==1)lst(e[u].rs,op);
	}
	nw[u]=tot++;if(u==op)return ;
}
void mid(int u,int op){
		if(e[u].ls!=0){
		if(num[e[u].ls]==-1)first(e[u].ls,op);
		if(num[e[u].ls]==0)mid(e[u].ls,op);
		if(num[e[u].ls]==1)lst(e[u].ls,op);
	}
	nw[u]=tot++;if(u==op)return ;
	if(e[u].rs!=0){
		if(num[e[u].rs]==-1)first(e[u].rs,op);
		if(num[e[u].rs]==0)mid(e[u].rs,op);
		if(num[e[u].rs]==1)lst(e[u].rs,op);
	}
}
