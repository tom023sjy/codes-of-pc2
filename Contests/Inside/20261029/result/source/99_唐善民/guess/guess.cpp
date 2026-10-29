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
#include<map>
using namespace std;
typedef __int128 lll;
istream& operator >>(istream& in,lll &x){
	string s;
	in>>s;
	x=0;
	for(char i:s){
		x=(x<<3)+(x<<1)+(i^'0');
	}
	return in;
}
ostream& operator <<(ostream& out,lll x){
	string s;
	if(x<0){
		x=-x;
		s.push_back('-');
	}
	do{
		s.push_back(x%10^'0');
		x/=10;
	}while(x);
	reverse(s.begin(),s.end());
	out<<s;
	return out;
}
lll sqrt(lll x){
	lll l=1,r=x,ans=1;
	while(l<=r){
		lll mid=l+r>>1;
		if(mid*mid<=x){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return ans;
}
vector<pair<lll,int>> calc(lll x){
	vector<pair<lll,int>>cnt;
	for(lll i=2;i*i<=x;){
		if(x%i==0){
			if(cnt.size()&&cnt.back().first==i){
				cnt.back().second++;
			}else{
				cnt.push_back({i,1});
			}
			x/=i;
		}else{
			i++;
		}
	}
	if(x>1){
		cnt.push_back({x,1});
	}
	return cnt;
}
lll qpow(lll base,int n){
	lll ans=1;
	while(n){
		if(n&1){
			ans=1ll*ans*base;
		}
		base*=base;
		n>>=1;
	}
	return ans;
}
lll query(lll m){
	m*=2;
	lll t=sqrt(4*m+1);
	if(t*t==4*m+1){
		if((t+1)%2==0){
			return t+1>>1;
		}
	}
	vector<pair<lll,int>>cnt=calc(m);
	reverse(cnt.begin(),cnt.end());
	vector<pair<lll,int>>pn;
	for(int i=0;i<cnt.size();i++){
		auto [q,d]=cnt[i];
		if(!d){
			continue;
		}
		pn.push_back({q,(d+1)/2});
		auto pl=calc(q-1);
		int j=cnt.size()-1;
		for(auto [plQ,plD]:pl){
			while(cnt[j].first<plQ){
				j--;
			}
			cnt[j].second-=plD;
		}
	}
	lll n=1;
	for(int i=0;i<pn.size();i++){
		auto [p,c]=pn[i];
		n*=qpow(p,c);
	}
	return n;
}
int main(){
	freopen("guess.in","r",stdin);
	freopen("guess.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int T;
	cin>>T;
	while(T--){
		lll m;
		cin>>m;
		cout<<query(m)<<'\n';
	}
	
	cout.flush();
	
	/*fclose(stdin);
	fclose(stdout);*/
	return 0;
}
