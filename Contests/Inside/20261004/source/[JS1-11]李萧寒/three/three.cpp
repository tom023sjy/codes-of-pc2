#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
int n,m,x[5005],d[5];
int do3(int a,int b,int c){
	d[1]=a;
	d[2]=b;
	d[3]=c;
	sort(d+1,d+1+3);
	a=d[1];
	b=d[2];
	c=d[3];
	int cnt=0;
	for(int i=0;i<=a;i++){
		if((a-i)%3==0&&(b-i)%3==0&&(c-i)%3==0){
			cnt++;
		}
	}
	return cnt;
}
signed main(){
	freopen("three.in","r",stdin);
	freopen("three.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		x[a]++;
	}
	if(m==1){
		cout<<1;
		return 0;
	}
	if(m==2){
		if(x[1]%3==0){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	if(m==3){
		cout<<do3(x[1],x[2],x[3]);
		return 0;
	}
	if(m==4){
		int sum=0;
		for(int i=0;i<=x[1];i+=3){
			int x1h=x[1]-i;
			if(x[2]-x1h<0||x[3]-x1h<0){
				continue;
			}
			sum+=do3(x[2]-x1h,x[3]-x1h,x[4]);
		}
		cout<<sum;
		return 0;
	}
	bool flag=true;
	for(int i=1;i<=m;i++){
		if(x[i]>2){
			flag=false;	
		}
	}
	if(flag==true){
		for(int i=1;i<=m-2;i++){
			if(x[i]<0){
				cout<<0;
				return 0;
			}
			x[i+1]-=x[i];
			x[i+2]-=x[i];
		}
		if(x[m]==0&&x[m-1]==0){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	int sum=1;
	for(int i=1;i<=m;i+=4){
		sum*=do3(x[i],x[i+1],x[i+2]);
		sum%=mod;
	}
	cout<<sum;
	return 0;
}
