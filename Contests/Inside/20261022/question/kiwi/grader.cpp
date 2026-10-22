#include<bits/stdc++.h>
#include"kiwi.h"
using namespace std;
namespace zxxwillakIOI2027_zxxshiquanshijiezuiqiangdechuzhongsheng_xianmudaniellelehuizuoti_tazazhemeniu{
const long long V=1e18;
int T,n,R,cnt,mx;
bool flag1,flag2;
long long a[10005];
set<pair<int,int> > S;
void Wrong_Answer(int o){
	printf("Wrong Answer[%d]\n",o);
	exit(0);
}
vector<long long> ask(vector<int> x,vector<int> y){
	if(x.size()!=y.size()) Wrong_Answer(1);
	if((int)x.size()>2*n) Wrong_Answer(2);
	for(auto i:x) if(i<0||n<=i) Wrong_Answer(3);
	for(auto i:y) if(i<0||n<=i) Wrong_Answer(3);
	if(++cnt>n) Wrong_Answer(4);
	mx=max(mx,(int)x.size());
	vector<long long> arr(x.size());
	for(int i=0;i<(int)x.size();i++){
		arr[i]=a[x[i]]+a[y[i]];
		if(x[i]>y[i]) swap(x[i],y[i]);
		if(x[i]==y[i]) flag1=true;
		if(S.count(make_pair(x[i],y[i]))) flag2=true;
		S.insert(make_pair(x[i],y[i]));
	}
	sort(arr.begin(),arr.end());
	return arr;
}
long double get_C3(int A){
	assert(A<=n);
	if(A<=2) return 1;
	if(A<=3) return 0.8;
	if(A<=4) return 0.6;
	if(A<=10) return 0.4;
	return 0.2;
}
long double get_C4(int B){
	assert(B<=2*n);
	if(B<=n-1) return 1;
	if(B<=n) return 0.9;
	if(B<=n+1) return 0.8;
	if(B<=n+2) return 0.7;
	if(B<=n+20) return 0.6;
	return 0.5;
}
void work(){
	assert(scanf("%d%d%d",&T,&n,&R)==3);
	mt19937_64 rnd(R);
	for(int i=1;i<=T;i++){
		cnt=mx=flag1=flag2=0;S.clear();
		for(int j=0;j<n;j++) a[j]=rnd()%(V+1);
		vector<long long> b=game(n);
		if((int)b.size()!=n) Wrong_Answer(5);
		for(int j=0;j<n;j++) if(b[j]!=a[j]) Wrong_Answer(6);
		long double C1=(flag1?0.8:1);
		long double C2=(flag2?0.7:1);
		long double C3=get_C3(cnt);
		long double C4=get_C4(mx);
		printf("OK, you can get %d points.\n",(int)floor(100*C1*C2*C3*C4));
	}
}
}
vector<long long> ask(vector<int> x,vector<int> y){
	return zxxwillakIOI2027_zxxshiquanshijiezuiqiangdechuzhongsheng_xianmudaniellelehuizuoti_tazazhemeniu::ask(x,y);
}
int main(){
	zxxwillakIOI2027_zxxshiquanshijiezuiqiangdechuzhongsheng_xianmudaniellelehuizuoti_tazazhemeniu::work();
}