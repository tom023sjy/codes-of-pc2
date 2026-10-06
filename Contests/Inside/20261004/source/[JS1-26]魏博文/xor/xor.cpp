#include<bits/stdc++.h>
using namespace std;
int b[3005],c[3005],d[3005],r[3005];
//string mx;
int main(){
	int t;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>t;
	while(t--){
		string mx;
		int n,p;
		cin>>n;
		string a;
		cin>>a;
		for(int i=0;i<a.size();i++){
			b[i+1]=a[i]-'0';
		}
		for(int i=1;i<=n;i++){
			if(b[i]==1){
				p=i;
				break;
			}
		}
		//cout<<p<<"ppp";
		for(int i=p;i<=n;i++){
			c[i-p+1]=b[i];
			mx+='0';
			//cout<<c[i-p+1]<<" ";
		}
		//cout<<mx<<"ppp\n";
		int h=n-p+1;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(j-i+1>h) break;
				int cnt=0;
				for(int k=1;k<=h-(j-i+1);k++){
					r[++cnt]=0;
				}
				for(int k=i;k<=j;k++){
					r[++cnt]=b[k];
				}
				/*for(int i=1;i<=cnt;i++){
					cout<<r[i]<<" ";
				}*/
				string w;
				//cout<<"pp\n";
				for(int i=1;i<=cnt;i++){
					if(r[i]==c[i]) w+='0';
					else w+='1';
				}
				mx=max(mx,w);
			}
		}
		int f=0;
		for(int i=0;i<h;i++){
			if(mx[i]=='1'||i==h-1){
				f=1;
			}
			if(f==1) cout<<mx[i];
		}
		cout<<"\n";
	}
	//cout<<mx;
}
