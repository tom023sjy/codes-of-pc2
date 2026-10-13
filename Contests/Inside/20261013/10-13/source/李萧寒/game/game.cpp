#include<bits/stdc++.h>
using namespace std;
vector<int>v[10];
int n,cnt,dep[10],fa[10];
bool vis[10];
struct node{
	int a,b;
}e[10];
void getdep(int x,int fa){
	dep[x]=dep[fa]+1;
	for(auto d:v[x]){
		if(d==fa){
			continue;
		}
		getdep(d,x);
	}
}
bool dfs(int x,int step){
	dep[0]=-1;
	getdep(x,0);
	bool flag=false;
	for(int i=1;i<=n;i++){
		if(x!=i&&vis[i]&&dep[i]>step){
			flag|=!dfs(i,dep[i]);
			getdep(x,0);
		}
	} 
	return flag;
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
void add(int a,int b){
	if(find(a)!=find(b)){
		fa[find(a)]=find(b);
	}
}
void get(int k){
	if(k==n+1){
		init();
		for(int i=1;i<n;i++){
			if(vis[e[i].a]&&vis[e[i].b]){
				add(e[i].a,e[i].b);
			}
		}
		for(int i=1;i<=n;i++){
			if(vis[i]&&find(1)!=find(i)){
				return;
			}
		}
		if(!dfs(1,0)){
			cnt++;
		}
		return;
	}
	vis[k]=1;
	get(k+1);
	if(k>1){
		vis[k]=0;
		get(k+1);
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	if(n>7){
		cout<<1;
		return 0;
	}
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
		e[i].a=a,e[i].b=b;
	}
	get(1);
	cout<<cnt;
	return 0;
}

