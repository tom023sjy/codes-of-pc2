#include<bits/stdc++.h>
using namespace std;
int n,m,c[5005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("three.in","r",stdin);
	freopen("three.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x;
	for(int i=1;i<=n;i++){cin>>x;c[x]++;}
	int h=1;
	for(int i=1;i<=m-2;i++){
		int k=min(c[i],min(c[i+1],c[i+2]));
		c[i]-=k;
		c[i+1]-=k;
		c[i+2]-=k;
		if(c[i]){
			h=0;break;
		}
	}
	printf("%d",h);
	return 0;
}
