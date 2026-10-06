#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,ans=1LL<<30;
vector<vector<ll>> rgt_rot(ll siz,vector<vector<ll>> vec){
	vector<vector<ll>> res(siz+5,vector<ll>(siz+5));
	for(ll i=0;i<siz;++i){
		//iÎªºá×Ý×ø±ê²îÖµ
		for(ll j=1;j+i<=siz;++j){
			res[siz-i][siz+1-i-j]=vec[j+i][j];
		}
	}
	return res; 
}
vector<vector<ll>> duichen(ll siz,vector<vector<ll>> vec){
	vector<vector<ll>> res(siz+5,vector<ll>(siz+5));
	for(ll i=1;i<=siz;++i){
		for(ll j=1;j<=i;++j){
			res[i][i+1-j]=vec[i][j];
		}
	}
	return res;
}
vector<vector<ll>> rot(ll siz,ll stat,vector<vector<ll>> vec){
	vector<vector<ll>> nw;
	if(stat==0){
		nw=vec;
	}
	else if(stat==1){
		nw=rgt_rot(siz,vec);
	}
	else if(stat==2){
		nw=rgt_rot(siz,rgt_rot(siz,vec));
	}
	else if(stat==3){
		nw=duichen(siz,vec);
	}
	else if(stat==4){
		nw=rgt_rot(siz,duichen(siz,vec));
	}
	else if(stat==5){
		nw=rgt_rot(siz,rgt_rot(siz,duichen(siz,vec)));
	}
	return nw;
}
ll dif(ll siz,vector<vector<ll>> veca,vector<vector<ll>> vecb){
	ll cnt=0;
	for(ll i=1;i<=n;++i){
		for(ll j=1;j<=i;++j){
			if(veca[i][j]!=vecb[i][j]) ++cnt;
		}
	}
	
	return cnt;
}
int main(){
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	cin>>n;
	vector<vector<ll>> a(n+5,vector<ll>(n+5));
	vector<vector<ll>> b(n+5,vector<ll>(n+5));
	for(ll i=1;i<=n;++i){
		for(ll j=1;j<=i;++j){
			cin>>a[i][j];
		}
	}
	for(ll i=1;i<=n;++i){
		for(ll j=1;j<=i;++j){
			cin>>b[i][j];
		}
	}
	for(ll i=0;i<6;++i){
		ans=min(ans,dif(n,rot(n,i,a),b));
	}
	cout<<ans;
	return 0;
}
