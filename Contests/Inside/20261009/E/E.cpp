#include<bits/stdc++.h>
#define I return
#define AK 0
#define IOI
#define ll long long
#define db double
using namespace std;
int t;
ll dis(ll x,ll y,ll z,ll w){
	return (x-z)*(x-z)+(y-w)*(y-w);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
    	ll x,y,z,w,a,b;
    	cin>>x>>y>>z>>w>>a>>b;
    	if(dis(0,0,x,y)>=dis(x,y,z,w)&&dis(0,0,x,y)>=dis(x,y,a,b)) cout<<"YES\n";
    	else cout<<"NO\n"; 
	}
    I AK IOI;
}

