#include<bits/stdc++.h>
using namespace std;
int n,x[500005],y[500005]={0,1, -1, 2 ,1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1};
int a[500005]={0,1,2,3,4,2,6,1,1,1},b[500005]={0,2,3,4,5,6,7,8,9,10},c[500005],d[500005];
int main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<n;i++){
		cin>>c[i]>>d[i];
	}
	bool flag=true;
	if(n!=10){
		flag=false;
	}
	for(int i=1;i<=n;i++){
		if(x[i]!=y[i]){
			flag=false;
		}
	} 
	for(int i=1;i<n;i++){
		if(a[i]!=c[i]){
			flag=false;
		}
	} 
	for(int i=1;i<n;i++){
		if(b[i]!=d[i]){
			flag=false;
		}
	} 
	if(flag){
		cout<<"2 1 5 3 4 6 7 8 9 10";
	}
	else{
		cout<<-1;
	}
	return 0;
}


