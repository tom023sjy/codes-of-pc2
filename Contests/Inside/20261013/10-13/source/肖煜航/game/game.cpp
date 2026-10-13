#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int M=3005;
const int mod=1e9+7;
int qpow(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=1ll*ans*x%mod;
		y>>=1;
		x=1ll*x*x%mod;
	}
	return ans;
}
struct edge{
	int to,nxt;
}e[N<<1];
int head[N],tot;
void add(int u,int v){
	e[++tot]={v,head[u]};
	head[u]=tot;
} 
int n;
int dep[N];
int s[N];
int f[2][M][3];
int g[M][M];
int dfn[N],sz[N],mx;
int low[N],tim;
int tmp[M];
void dfs(int u,int f){
	dep[u]=dep[f]+1;
	sz[u]=1;
	dfn[u]=++tim;
	mx=max(mx,dep[u]);
	low[tim]=u;
	g[u][dep[u]]=1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==f) continue;
		dfs(v,u);
		memcpy(tmp,g[u],sizeof tmp);
		memset(g[u],0,sizeof g[u]);
		for(int j=1;j<=mx;j++) g[u][j]=tmp[j];
		for(int j=1;j<=mx;j++) tmp[j]=(tmp[j-1]+tmp[j])%mod;
		sz[u]+=sz[v];
		for(int j=dep[u];j<=mx;j++){
			g[u][j]=(g[u][j]+1ll*tmp[j]*g[v][j]%mod)%mod;			
		}
	}
}
int inv[M];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	inv[0]=1;
	for(int i=1;i<=n;i++) inv[i]=qpow(i,mod-2);
	bool flag=1;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
		if(y!=x+1){
			flag=0;
		}
	}
	if(flag){
		cout<<"1";
		return 0;
	}
	dfs(1,0);
	for(int i=1;i<=mx;i++) f[0][i][0]=1;
	int nw=0,lst=0;
	for(int i=head[1];i;i=e[i].nxt){
		int v=e[i].to;
		lst=nw;
		nw^=1; 
		for(int j=1;j<=mx;j++) f[nw][j][0]=f[nw][j][1]=f[nw][j][2]=0;
		s[0]=0;
		for(int j=1;j<=mx;j++) s[j]=(s[j-1]+g[v][j])%mod;
		for(int j=1;j<=mx;j++){
			f[nw][j][0]=f[lst][j][0];
			f[nw][j][1]=f[lst][j][1];
			f[nw][j][2]=f[lst][j][2];
			f[nw][j][0]=(f[nw][j][0]+1ll*f[lst][j][0]*s[j-1]%mod)%mod;
			f[nw][j][1]=(f[nw][j][1]+1ll*f[lst][j][1]*s[j-1]%mod)%mod;
			f[nw][j][2]=(f[nw][j][2]+1ll*f[lst][j][2]*s[j]%mod)%mod; 
			f[nw][j][2]=(f[nw][j][2]+1ll*f[lst][j][1]*g[v][j]%mod)%mod;
			f[nw][j][1]=(f[nw][j][1]+1ll*f[lst][j][0]*g[v][j]%mod)%mod;
		}
	}
	int ans=1;
	for(int i=1;i<=mx;i++) ans=(ans+f[nw][i][2])%mod;
	cout<<ans;	
	return 0;
}
