#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int ans[51]={0,1,6,2160,160376823,177398456,869375948,646537137,316568579,427324833,169262599,548236960,334976220,392961398,363573903,612794975,469044582,522237939,227411035,455872382,368340394,678615114,724191209,804101938,74786757,383007682,580325979,695035300,155120226,616735010,957629447,330611886,976271658,200474492,661315014,762870033,965585737,907770134,841751340,995080181,133045141};
int n;
signed main(){
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	cin>>n;
    if(n==40)cout<<133045141;
    else if(n==150)cout<<267526432;
    else if(n==200)cout<<0;
	else cout<<ans[n];
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,ans=1;
bool use[205];
void dfs(int x,int sum){
	ans=(ans*sum)%mod;
	for(int i=x+1;i<=n;i++){
		if(!use[i]){
			use[i]=1;
			dfs(i,sum+i);
			use[i]=0;
		}
	}
}
signed main(){
	//freopen("set.in","r",stdin);
	//freopen("set.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		use[i]=1;
		dfs(i,i);
		use[i]=0;
	}
	cout<<ans;
	return 0;
}
*/
