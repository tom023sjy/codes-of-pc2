#include<bits/stdc++.h>
using namespace std;
int T,n,a[10000005],b[10000005];
char s[10000005];int ans[10000005],up[10000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		vector<int>v;
		cin>>(s+1);
		for(int i=1;i<=n;i++)
			a[i]=s[i]-'0';
		int flag=0,cnt=0,f0=0;
		for(int i=1;i<=n;i++){
			if(a[i]) flag=1;
			if(!a[i]) f0=1;
			if(flag) b[++cnt]=a[i];
		}
		if(!flag){cout<<"0\n";continue;} 
		if(!f0){
			for(int i=1;i<cnt;i++) cout<<1;
			cout<<"0\n";continue;
		}
		int tot=0;
		for(int i=1;i<=cnt;i++)
			if(!b[i]) tot++;
		if(!tot){
			for(int i=1;i<=cnt;i++) cout<<b[i];
			cout<<"\n";continue;
		} 
		int k=0;
		for(int i=1;i<=cnt;i++){
			k++;if(!b[i]) break;
		}
		int r=cnt-k+1;
		for(int i=1;i<=cnt;i++)
			ans[i]=b[i];
		int now=k-1;
		for(int i=k+1;i<=cnt;i++){
			if(now>1&&b[i]==0) now--;
			else break;
		}
		for(int i=k;i<=cnt;i++)
			ans[i]^=b[now+i-k];
		for(int i=1;i<=cnt;i++)
			cout<<ans[i];
		cout<<"\n";
	}
	return 0;
}
