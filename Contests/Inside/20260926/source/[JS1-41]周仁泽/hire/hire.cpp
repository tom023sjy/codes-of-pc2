#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e3+7;
int n,m,k,d,x,y,pos;
int val[MAXN],vis[MAXN],id[MAXN];
int num[MAXN];
bool flag;
signed main(){
	freopen("hire.in","r",stdin);
	freopen("hire.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k>>d;
	while(m--){
		memset(num,0,sizeof(num));
		cin>>x>>y;
		if(id[x]) val[id[x]]+=y;
		else{
			pos++;
			val[pos]=y;
			vis[pos]=x;
			id[x]=pos;
		}
		flag=1;
		/*for(int i=1;i<=3;i++) cout<<id[i]<<" ";
		cout<<endl;
		for(int i=1;i<=pos;i++) cout<<val[i]<<" ";
		cout<<endl;*/
		//for(int i=1;i<=pos;i++) cout<<vis[i]<<" ";
		//cout<<endl;
		//cout<<pos<<endl;
		for(int i=1;i<=pos;i++){
			//cout<<i<<" ";
			//cout<<vis[i]<<" ";
			int tmp=val[i];
			for(int j=vis[i];j<=vis[i]+d;j++){
				//cout<<j<<" ";
				if(num[j]<k){
					int sub=k-num[j];
					if(sub>=tmp){
						tmp=0;
						num[j]+=tmp;
						break;
					}
					else{
						num[j]=k;
						tmp-=sub;
					}
				}
				//cout<<num[j]<<" ";
			}
			//cout<<endl;
			if(!tmp){
				flag=0;
				break;
			}
			//cout<<val[i]<<" ";
		}
		//cout<<endl;
		//for(int i=1;i<=n;i++) cout<<num[i]<<" ";
		//cout<<endl;
		if(flag)  cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
