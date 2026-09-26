#include<bits/stdc++.h>
#define lowbit(x) x&-x
using namespace std;
struct edge{
	int v;
};
vector<edge> e[25],s[25],fx[25];
int val[25],dfn[25],jms[25];
string ss;
int n,m,k,d,ans,tot,df;
void dfs(int now){
	//cout<<now<<" "<<df<<"\n";
	dfn[now]=++df;
	for(auto ed:e[now]){
		dfs(ed.v);
	}
	return ;
}
void jm(int l){
	ss="";
	while(l){
		l%2?ss+='1':ss+='0';
		l/=2;
	}
	while(ss.size()<n)ss+='0';
	reverse(ss.begin(),ss.end());
	return ;
}
bool check(int ll,int rr){
	for(auto vv:s[ll]){
		if(vv.v==rr)return true;
	}return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>val[i];
	}
	for(int i=1;i<=n;i++){
		int tot;
		cin>>tot;
		for(int j=1;j<=tot;j++){
			int v;
			cin>>v;
			e[i].push_back({v});
			fx[v].push_back({i});
		}
	}
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		s[u].push_back({v});
		s[v].push_back({u});
	}
	dfs(1);
//	cout<<"asdfghjkk"<<"\n";
//	for(int i=1;i<=n;i++)cout<<dfn[i]<<" ";
//	cout<<"\n";
	for(int i=1;i<=(1<<n)-1;i++){
		jm(i);
		int fl=1;
		tot=0;
		for(int j=0;j<ss.size();j++){
			if(ss[j]=='1'){
				tot+=val[j+1];
				for(int k=0;k<j;k++){
					if(ss[k]=='1'&&abs(dfn[k+1]-dfn[j+1])<=1&&check(k+1,j+1)){
						fl=0;
						break;
					}
				}
			}
		}
		if(fl)ans=max(ans,tot);
	}cout<<ans;
	return 0;
} 
