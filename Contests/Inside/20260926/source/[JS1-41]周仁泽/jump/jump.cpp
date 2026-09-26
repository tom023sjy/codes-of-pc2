#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e2+7;
const int MAXM=2e6+7;
int n,ans;
int a[MAXN];
bool jud[MAXM];
char op;
void check(int x){
	jud[x]=1;
	ans++;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			if(i>2){
				if(a[i-1]==1&&a[i-2]==0){
					a[i]=0;
					a[i-2]=1;
					int y=x;
					y-=(1<<(i-1));
					y+=(1<<(i-3));
					if(!jud[y]) check(y);
					a[i]=1,a[i-2]=0;
				}
			}
			if(i<n-1){
				if(a[i+1]==1&&a[i+2]==0){
					a[i]=0;
					a[i+2]=1;
					int y=x;
					y-=(1<<(i-1));
					y+=(1<<(i+1));
					if(!jud[y]) check(y);
					a[i]=1,a[i+2]=0;
				}
			}
		}
	}
	return;
}
void dfs(int x){
	if(x>n){
		int start=0,p=1;
		for(int i=1;i<=n;i++){
			start+=(a[i]*p);
			p*=2;
		}
		memset(jud,0,sizeof(jud));
		check(start);
		return;
	}
	if(a[x]==-1){
		a[x]=0;
		dfs(x+1);
		a[x]=1;
		dfs(x+1);
		a[x]=-1;
	}
	else dfs(x+1);
	return;
}
signed main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>op;
		if(op=='?') a[i]=-1;
		else a[i]=op-'0';
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
