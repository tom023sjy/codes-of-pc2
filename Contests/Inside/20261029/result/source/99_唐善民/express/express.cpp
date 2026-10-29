//#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<list>
using namespace std;
typedef long long ll;
constexpr const int N=1e6;
constexpr const ll inf=0x3f3f3f3f3f3f3f3f;
int n,a[N+1],r[N+1];
ll f[N+1];
struct bitPre{
	ll t[N+1];
	
	bitPre(){
		memset(t,0x3f,sizeof(t));
	}
	
	int lowbit(int x){
		return x&-x;
	}
	ll query(int x){
		ll ans=inf;
		while(x){
			ans=min(ans,t[x]);
			x-=lowbit(x);
		}
		return ans;
	}
	void set(int x,ll k){
		while(x<=N){
			t[x]=min(t[x],k);
			x+=lowbit(x);
		}
	}
}pre;
struct bitSuf{
	ll t[N+1];
	
	bitSuf(){
		memset(t,0x3f,sizeof(t));
	}
	
	int lowbit(int x){
		return x&-x;
	}
	ll query(int x){
		ll ans=inf;
		while(x<=N){
			ans=min(ans,t[x]);
			x+=lowbit(x);
		}
		return ans;
	}
	void set(int x,ll k){
		while(x){
			t[x]=min(t[x],k);
			x-=lowbit(x);
		}
	}
}suf;
void discrete(){
	static int m,tmp[N+1+1];
	for(int i=0;i<=n;i++){
		tmp[++m]=a[i];
	}
	sort(tmp+1,tmp+m+1);
	m=unique(tmp+1,tmp+m+1)-tmp-1;
	for(int i=0;i<=n;i++){
		r[i]=lower_bound(tmp+1,tmp+m+1,a[i])-tmp;
	}
}
int main(){
	freopen("express.in","r",stdin);
	freopen("express.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	discrete();
	ll sum=0;
	for(int i=2;i<=n;i++){
		sum+=abs(a[i]-a[i-1]);
	}
	memset(f,0x3f,sizeof(f));
	f[0]=a[1];
	pre.set(r[0],f[0]-a[0]);
	suf.set(r[0],f[0]+a[0]);
	for(int i=2;i<=n;i++){
		f[i-1]=min({f[i-1],a[i]+pre.query(r[i]),-a[i]+suf.query(r[i])});
		f[i-1]-=abs(a[i]-a[i-1]);
		pre.set(r[i-1],f[i-1]-a[i-1]);
		suf.set(r[i-1],f[i-1]+a[i-1]);
	}
	ll ans=inf;
	for(int j=0;j<=n;j++){
		ans=min(ans,f[j]);
	}
	ans+=sum;
	cout<<ans<<'\n';
	
	cout.flush();
	
	/*fclose(stdin);
	fclose(stdout);*/
	return 0;
}
