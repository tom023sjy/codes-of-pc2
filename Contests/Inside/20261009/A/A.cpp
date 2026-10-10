#include<bits/stdc++.h>
#define I return
#define AK 0
#define IOI
#define ll long long
using namespace std;
ll n,d,m,a[100010],sum,t;
queue<ll> q;
bool cmp(ll x,ll y){
	return x>y;
}
bool ck(ll x){
	sum=t=0;
	while(!q.empty()) q.pop();
	for(int i=n-x+1;i<=n;i++){
		t+=a[i];
		if(!q.empty()&&q.front()<=t){
			sum-=q.front()-t+a[i];
			q.pop();
		} 
		sum-=q.size()*a[i];
		sum+=d;
		q.push(t+d);
		/*queue<ll> qq=q;
		cout<<t<<":";
		while(!qq.empty()){
			cout<<qq.front()<<" ";
			qq.pop();
		} 
		cout<<sum<<"\n";*/
		if(sum>=d*m) return 1;
	}
	return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>d>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ll l=1,r=n,ans=-1;
	while(l<=r){
		ll mid=(l+r)/2;
		if(ck(mid)){
			r=mid-1;
			ans=mid;
		}
		else l=mid+1;
	}
	cout<<ans;
    I AK IOI;
}

