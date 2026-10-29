#include<bits/stdc++.h>
using namespace std;
int n,h[2005];
bool ans[100005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("cup.in","r",stdin);
	freopen("cup.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>h[i];
	sort(h+1,h+n+1);
	do{
		int sum=0;
		for(int i=2;i<n;i++)sum+=max(0,min(h[i-1]-h[i],h[i+1]-h[i]));
		ans[sum]=1;
	}while(next_permutation(h+1,h+n+1));
	for(int i=0;i<=100000;i++)if(ans[i])cout<<i<<' ';
	return 0;
}
