#include<bits/stdc++.h>
#define I return
#define AK 0
#define IOI
#define ll long long
using namespace std;
int n,a[400010],c[400010],cnt;
vector<int> g[400010];
struct nd{
	int l,r,x;
}b[400010];
bool cmp(nd x,nd y){
	return x.x<y.x;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		g[x].push_back(i);
	}
	for(int i=1;i<=n;i++){
		cnt=0;
		for(int j=1;j<g[i].size();j++){
			b[++cnt]={g[i][j-1],g[i][j],g[i][j]-g[i][j-1]};
		}
		sort(b+1,b+cnt+1,cmp);
		int l=1,r=n;
		for(int j=1;j<=cnt;j++){
			if()
		}
	}
    I AK IOI;
}
