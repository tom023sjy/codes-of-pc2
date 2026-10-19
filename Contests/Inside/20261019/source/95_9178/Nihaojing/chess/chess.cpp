#include<bits/stdc++.h>
#define ll long long
using namespace std;
int sb,n,m,t,cnt;
bool b[5010][5010];
pair<int,int> ls[5010][5010],nx[5010][5010];
struct nd{
	int l1,r1,l2,r2,c,sz;
}a[100010];
bool cmp(nd x,nd y){
	return x.c>y.c;
}
unsigned ll ans,now;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>sb>>n>>m>>t;
	if(sb>=9&&sb<=10){
		for(int i=1;i<=n;i++){
			cin>>a[i].l1>>a[i].l2>>a[i].r1>>a[i].r2>>a[i].c;
			now+=a[i].c;
		}
		ll tmp=now;
		ans+=tmp*(tmp-1)/2;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].l1>>a[i].l2>>a[i].r1>>a[i].r2>>a[i].c;
	}
	for(int i=1;i<=n;i++){
		for(int j=a[i].l1;j<=a[i].r1;j++){
			for(int k=a[i].l2;k<=a[i].r2;k++){
				if(!b[j][k]) cnt++;
				b[j][k]=1;
			}
		}
		if(cnt==m*t){
			ll tmp=now;
			ans+=tmp*(tmp-1)/2;
			now=0;
			memset(b,0,sizeof(b));
			cnt=0;
			for(int j=a[i].l1;j<=a[i].r1;j++){
				for(int k=a[i].l2;k<=a[i].r2;k++){
					if(!b[j][k]) cnt++;
					b[j][k]=1;
				}
			}
		}
		now+=a[i].c;
	}
	ll tmp=now;
	ans+=tmp*(tmp-1)/2;
	cout<<ans;
	return 0;
}
