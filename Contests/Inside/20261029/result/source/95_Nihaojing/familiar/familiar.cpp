#include<bits/stdc++.h>
#define I return
#define AK 0
#define IOI 
#define ll long long
using namespace std;
ll n,m,q,a[1010][1010];
ll qry(ll x,ll y){
	ll l=1,r=m,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[x][mid]<y){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("familiar.in","r",stdin);
    freopen("familiar.out","w",stdout);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	while(q--){
		int op;
		cin>>op;
		if(op==1){
			ll x,y,k;
			cin>>x>>y>>k;
			k=2*m+1-k;
			ll l=1,r=m,ans1=-1,ans2=-1;//在x中
			while(l<=r){
				int mid=(l+r)/2;
				if(qry(x,a[x][mid])+qry(y,a[x][mid])+1<=k){
					ans1=a[x][mid];
					l=mid+1;
				}
				else r=mid-1;
			}
			l=1,r=m;
			while(l<=r){
				int mid=(l+r)/2;
				if(qry(x,a[y][mid])+qry(y,a[y][mid])+1<=k){
					ans2=a[y][mid];
					l=mid+1;
				}
				else r=mid-1;
			}
			cout<<max(ans1,ans2)<<"\n";
		}
		if(op==2){
			ll x,y;
			cin>>x>>y;
			ll l=1,r=m,ans=-1;//在x中
			while(l<=r){
				int mid=(l+r)/2;
				if(a[x][mid]<=y){
					ans=mid;
					l=mid+1;
				}
				else r=mid-1;
			}
			if(ans!=-1) a[x][ans]=y;
		}
	}
    I AK IOI;
}

/**
diff ex_familiar4.out familiar.out
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

