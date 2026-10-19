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
typedef unsigned long long ull;
constexpr const int N=5000,M=5000,K=1e5;
struct node{
	int x1,y1,x2,y2,c;
}q[K+1];
int n,m,k;
ll cnt[N+1+1][M+1+1];
ll calc(int pi,int pj,vector<int>id){
	pi=(pi?n:1);
	pj=(pj?m:1);
	ll ans=0;
	for(int i:id){
		auto &[x1,y1,x2,y2,c]=q[i];
		if(!(x1<=pi&&pi<=x2&&y1<=pj&&pj<=y2)){
			ans+=c;
		}
	}
	ans=ans*(ans-1)>>1;
	return ans;
}
ull solve1(){
	int i0=0,j0=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1&&j==1||i==1&&j==m||i==n&&j==1||i==n&&j==m){
				continue;
			}
			if(cnt[i][j]>cnt[i0][j0]){
				i0=i,j0=j;
			}
		}
	}
	ull ans=0;//cnt[i0][j0]*(cnt[i0][j0]-1ll)>>1;
	vector<int>id;
	if(1||!i0){
		for(int i=1;i<=k;i++){
			id.push_back(i);
		}
	}else{
		for(int i=1;i<=k;i++){
			auto &[x1,y1,x2,y2,c]=q[i];
			if(x1<=i0&&i0<=x2&&y1<=j0&&j0<=y2){
				id.push_back(i);
			}
		}
	}
	ull Max=0;
	for(int i1=0;i1<=(n>1);i1++){
		for(int j1=0;j1<=(m>1);j1++){
			vector<int>id2;
			ull calc1=calc(i1,j1,id);
			int pi1=(i1?n:1),pj1=(j1?m:1);
			for(int i:id){
				auto &[x1,y1,x2,y2,c]=q[i];
				if(x1<=pi1&&pi1<=x2&&y1<=pj1&&pj1<=y2){
					id2.push_back(i);
				}
			}
			for(int i2=0;i2<=(n>1);i2++){
				for(int j2=0;j2<=(m>1);j2++){
					if(i1==i2&&j1==j2){
						continue;
					}
					//~ cerr<<"(i1,j1)="<<i1<<","<<j1<<'\n';
					//~ cerr<<"(i2,j2)="<<i2<<","<<j2<<'\n';
					//~ cerr<<"calc = "<<calc(i1,j1)+calc(i2,j2)<<'\n';
					Max=max(Max,calc1+calc(i2,j2,id2));
				}
			}
		}
	}
	ans+=Max;
	return ans;
}
ull solve2(){
	int i0=0,j0=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1&&j==1||i==1&&j==m||i==n&&j==1||i==n&&j==m){
				continue;
			}
			if(cnt[i][j]>cnt[i0][j0]){
				i0=i,j0=j;
			}
		}
	}
	ull ans=cnt[i0][j0]*(cnt[i0][j0]-1ll)>>1;
	vector<int>id;
	if(!i0){
		for(int i=1;i<=k;i++){
			id.push_back(i);
		}
	}else{
		for(int i=1;i<=k;i++){
			auto &[x1,y1,x2,y2,c]=q[i];
			if(x1<=i0&&i0<=x2&&y1<=j0&&j0<=y2){
				id.push_back(i);
			}
		}
	}
	ull Max=0;
	for(int i1=0;i1<=(n>1);i1++){
		for(int j1=0;j1<=(m>1);j1++){
			vector<int>id2;
			ull calc1=calc(i1,j1,id);
			int pi1=(i1?n:1),pj1=(j1?m:1);
			for(int i:id){
				auto &[x1,y1,x2,y2,c]=q[i];
				if(x1<=pi1&&pi1<=x2&&y1<=pj1&&pj1<=y2){
					id2.push_back(i);
				}
			}
			for(int i2=0;i2<=(n>1);i2++){
				for(int j2=0;j2<=(m>1);j2++){
					if(i1==i2&&j1==j2){
						continue;
					}
					//~ cerr<<"(i1,j1)="<<i1<<","<<j1<<'\n';
					//~ cerr<<"(i2,j2)="<<i2<<","<<j2<<'\n';
					//~ cerr<<"calc = "<<calc(i1,j1)+calc(i2,j2)<<'\n';
					Max=max(Max,calc1+calc(i2,j2,id2));
				}
			}
		}
	}
	ans+=Max;
	return ans;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int cid;
	cin>>cid>>k>>n>>m;
	for(int i=1;i<=k;i++){
		auto &[x1,y1,x2,y2,c]=q[i];
		cin>>x1>>y1>>x2>>y2>>c;
		cnt[1][1]+=c;
		cnt[n+1][m+1]-=c;
		cnt[x2+1][y2+1]-=c;
		cnt[x1][y2+1]+=c;
		cnt[x2+1][y1]+=c;
		cnt[x1][y1]-=c;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cnt[i][j]+=cnt[i][j-1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cnt[i][j]+=cnt[i-1][j];
		}
	}
	cout<<max(solve1(),solve2())<<'\n';
	
	cout.flush();
	
	/*fclose(stdin);
	fclose(stdout);*/
	return 0;
}
/*
0
2 1 2
1 1 1 1 3
1 2 1 2 4

9
*/
/*
0
3 7 3
1 1 3 3 1
5 1 7 3 1
3 2 5 3 1

3
*/
/*
0
7 2 3
2 1 2 1 10000
2 1 2 3 3696
1 3 2 3 4870
1 3 2 3 5406
1 3 2 3 732
1 3 1 3 5797
1 1 1 3 1555


466348485
*/
