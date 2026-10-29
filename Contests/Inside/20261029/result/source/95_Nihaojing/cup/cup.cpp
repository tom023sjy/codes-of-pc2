#include<bits/stdc++.h>
#define I return
#define AK 0
#define IOI 
#define ll long long
using namespace std;
ll n,a[510],b[510],c[510],l[510],r[510],ans;
bool vis[1000010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("cup.in","r",stdin);
    freopen("cup.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=i;
	}
	do{
		for(int i=1;i<=n;i++){
			c[i]=a[b[i]];
		}
		for(int i=1;i<=n;i++){
			l[i]=max(l[i-1],c[i]);
		}
		for(int i=n;i>=1;i--){
			r[i]=max(r[i+1],c[i]);
		}
		ll tmp=0;
		for(int i=1;i<=n;i++){
			tmp+=max(0ll,min(l[i],r[i])-c[i]);
		}
		vis[tmp]=1;
	}while(next_permutation(b+1,b+n+1));
	for(int i=0;i<=100000;i++){
		if(vis[i]) cout<<i<<" ";
	}
    I AK IOI;
}

/**
*　　┏┓　　　┏┓+ +
*　┏┛┻━━━┛┻┓ + +
*　┃　　　　　　　┃
*　┃　　　━　　　┃ ++ + + +
*  ████━████+
*  ◥██◤　◥██◤ +
*　┃　　　┻　　　┃
*　┃　　　　　　　┃ + +
*　┗━┓　　　┏━┛
*　　　┃　　　┃ + + + +Code is far away from 　
*　　　┃　　　┃ + bug with the animal protecting
*　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
*　　　┃ 　　　　　　 ┣┓
*　　  ┃ 　　　　　 　┏┛
*　    ┗┓┓┏━┳┓┏┛ + + + +
*　　　　┃┫┫　┃┫┫
*　　　　┗┻┛　┗┻┛+ + + +
*/

