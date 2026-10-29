#include<bits/stdc++.h>
using namespace std;
int d[25],n,k,ans=0,l;
int x[200005];
bool ss[1000];
int y[200005]={0,5,4,3,1,2},a[25];
signed main(){
    freopen("cup.in","r",stdin);
    freopen("cup.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int t=1,sum,now,ma,id;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		a[i]=n-i+1;
		t*=i;
	}
	while(t--){
        next_permutation(a+1,a+1+n);
        for(int i=1;i<=n;i++){
            y[i]=x[a[i]];
        }
        sum=0,now=1;
        while(now<n){
            ma=-1,id=0;
            for(int i=now+1;i<=n;i++){
                if(y[i]>y[now]){
                    id=i;
                    break;
                }
                if(y[i]>ma){
                    ma=y[i];
                    id=i;
                }
            }
            int l=min(y[id],y[now]);
            for(int i=now+1;i<id;i++){
                sum+=l-y[i];
            }
            now=id;
        }
        ss[sum]=1;
	}
	for(int i=0;i<=990;i++){
        if(ss[i])cout<<i<<" ";
	}
	return 0;
}
