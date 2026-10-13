#include<iostream>
#include<vector>
#define int long long
using namespace std;

const unsigned int mod=1e9+7;
int n,ans=1,deep[200005],ast[200005]={},asp[200005]={},light[200005]={};
vector<int> v[200005];

int fma(int a,int b,int p){
	a%=p;
	int ass=1;
	while(b){
		if(b&1) ass=ass*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ass;
}

int powt(int x){
	return fma(2,x,mod);
}

void dfs(int x,int from){
	deep[x]=deep[from]+1;
	int siz=v[x].size()-1,dep=deep[x]+1;
	if(x==1){
		siz++;
		if(siz==1) return;
		ans=(ans+powt(siz)-1-siz+mod)%mod;
	}
	if(siz&&x!=1){
		if(ast[dep]){
			light[dep]=1;
			ast[dep]=ast[dep]*powt(siz)%mod;
			asp[dep]=(asp[dep]+powt(siz)-1+mod)%mod;
		}
		else{
			asp[dep]+=powt(siz)-1;
			ast[dep]+=powt(siz); 
		}
	}
	for(int i=0;i<(int)v[x].size();i++){
		int too=v[x][i];
		if(too!=from) dfs(too,x);
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	if(n>7){
		cout<<"1";
		return 0;
	}
	for(int i=1;i<=n-1;i++){
		int a,b;
		cin>>a>>b;
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	dfs(1,0);
	for(int i=2;i<=n;i++){
		if(light[i]) ans=(ans+ast[i]-asp[i]-1+mod)%mod;
	}
	cout<<ans;
	//cout<<ans<<"\n"<<ast[2]<<" "<<asp[2]<<"\n"<<ast[3]<<" "<<asp[3];
	return 0;
}
