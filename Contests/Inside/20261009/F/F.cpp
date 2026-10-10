#include<bits/stdc++.h>
#define I return
#define AK 0
#define IOI
#define ll long long
using namespace std;
int n,q,a[400010],f[60][400010],sum[60];
vector<int> g[400010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
	sum[0]=n;
    while(q--){
    	string op;
    	cin>>op;
    	if(op=="F"){
    		int x,y;
    		cin>>x>>y;
    		g[x].push_back(y);
    		g[y].push_back(x);
    		f[a[y]][x]++;
    		f[a[x]][y]++;
		}
		if(op=="A"){
			int x;
			cin>>x;
			int ax=a[x];
			a[x]=min(a[x]+1,50);
			sum[ax]--;
			sum[a[x]]++;
			for(auto v:g[x]){
				f[ax][v]--;
				f[a[x]][v]++;
			}
		}
		if(op=="Q"){
			int x;
			cin>>x;
			bool fl=0;
			for(int i=50;i>=0;i--){
				if(f[i][x]<sum[i]-(i==a[x])){
					cout<<i<<"\n";
					fl=1;
					break;
				}
			}
			if(!fl) cout<<-1<<"\n";
		}
	}
    I AK IOI;
}

