#include <bits/stdc++.h>
using namespace std;
int n,m,b[500],an;
int main(){
	freopen("three.in","r",stdin);
	freopen("three.out","w",stdout);
	cin>>n>>m;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		b[x]++;
	}
	if(n<=4){
		for(int i=1;i<=1667;i++){
			for(int j=1;j<=1667;j++){
				b[1]-=i;
				b[2]-=i+j;
				b[3]-=i+j;
				b[4]-=j;
				if(b[1]%3==0&&b[2]%3==0&&b[3]%3==0&&b[4]%3==0&&b[1]>=0&&b[2]>=0&&b[3]>=0&&b[4]>=0){
					an++;
				}
			}
		}
		cout<<an;
		return 0;
	}
	bool h=0;
	for(int i=1;i<=m;i++){
		int k=min(b[i],min(b[i+2],b[i+1]));
		b[i]-=k;
		b[i+1]-=k;
		b[i+2]-=k;
		if(b[i]){
			h=1;
			break;
		}
	}
	if(h){
		cout<<0;
	}
	else cout<<1;
	return 0;
}
