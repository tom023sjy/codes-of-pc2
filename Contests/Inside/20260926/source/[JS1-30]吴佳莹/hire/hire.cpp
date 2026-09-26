#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e3+5;
int n,m,k,d,a[N],vis[N];
signed main(){
	freopen("hire.in","r",stdin);
	freopen("hire.out","w",stdout);
	cin>>n>>m>>k>>d;
	for(int p=1;p<=m;p++){
		int x,y;
		cin>>x>>y;
		a[x]+=y;
		int nowx=0,nowy=0,flag=1;
		for(int i=1;i<=n;i++){
			if(a[i]){
				if(nowx==0&&nowy==0){
					nowx=(a[i]-1)/k+1;
					nowy=k-a[i]%k;
					if(nowy==k) nowy=0;
				}
				else{
					if(nowx<i) nowx=i,nowy=k;
					if(a[i]<=nowy) nowy-=a[i];
					else{
						int t=a[i]-nowy;
						nowx+=(t-1)/k+1;
						nowy=k-t%k;
						if(nowy==k) nowy=0;
					}
				}
				if(nowx>n||nowx>i+d){
					flag=0;cout<<"NO"<<endl;
					break;
				}
			
			}
		}
		if(flag) cout<<"YES"<<endl;
	}
	return 0;
}
