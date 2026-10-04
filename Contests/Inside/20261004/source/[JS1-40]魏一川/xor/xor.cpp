#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,power[35];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//ios::sync_with_stdio(0);cin.tie(0);
	power[0]=1;
	for(int i=1;i<=31;i++)power[i]=power[i-1]*2;
	cin>>t;
	while(t--){
		int n,ans=0;
		cin>>n;
		bitset<30>a;
		for(int i=0;i<n;i++){
			char c;
			cin>>c;
			a[i]=c-'0';
		}
		for(int l1=0;l1<n;l1++){
			for(int r1=l1;r1<n;r1++){
				int x=0,cnt=0;
				for(int i=r1;i>=l1;i--)x+=a[i]*power[cnt++];
				for(int l2=0;l2<n;l2++){
					for(int r2=l2;r2<n;r2++){
						int y=0,cnt1=0;
						for(int i=r2;i>=r1;i--)y+=a[i]*power[cnt1++];
						ans=max(ans,x^y);
					}
				}
			}
		}
		stack<int>st;
		while(ans){
			st.push(ans/2);
			ans/=2;
		}
		while(!st.empty()){
			cout<<st.top();
			st.pop();
		}
		cout<<"\n";
	}
	return 0;
}
