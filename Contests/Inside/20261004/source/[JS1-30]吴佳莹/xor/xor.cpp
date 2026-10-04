#include<bits/stdc++.h>
using namespace std;
int T;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>T;
	while(T--){
		int n,pos=-1,flag=1,flag2=0,num=0;
		string s;
		cin>>n;
		cin>>s;
		for(int i=0;i<n;i++) if(s[i]=='0') flag=0;
		if(flag==1){
			for(int i=0;i<n-1;i++) cout<<1;
			cout<<0;
			cout<<endl;
			continue;
		}
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				flag2=1;
				num++;
			}
			if(s[i]=='0'&&flag2==1){
				pos=i;
				break;
			}
		}
		if(pos==-1){
			cout<<0<<endl;
			continue;
		}
		int ans=0,maxn=0,ppos;
		for(int i=0;i<n;i++){
			if(s[i]=='0') continue;
			if(n-i<n-pos-1) continue;
			int p=pos,res=0,res2=0,bj=0;
			for(int j=i;j<n;j++){
				int ss=0,ppp=0;
				if(s[j]=='1') ss=1;
				if(s[p]=='1') ppp=1;
				if((ss==(ppp^1))&&bj==0) res++;
				else{
					if(ss==(ppp^1)) res2++;
					bj=1;
					break;
				}
				p++;
				if(p==n) break;
			}
	//		cout<<'a'<<res<<endl;
			if(res>ans||res==ans&&res2>maxn){
				ppos=i;
				maxn=max(maxn,res2);
				ans=res;
			}
		}
		for(int i=1;i<=num;i++) cout<<1;
		for(int i=pos;i<n;i++){
			int r=0,pp=0;
			if(s[ppos]=='1') pp=1;
			if(s[i]=='1') r=1;
			cout<<(r^pp);
			ppos++;
		}
		cout<<endl;
	}
	return 0;
}
