#include<bits/stdc++.h>
#define florr(a,b,c) for(int a=(b);a<=(c);a++)
#define AC_AK return 0;
using namespace std;
int t,n;
string s;
inline void slv(){
    cin>>n>>s;
    string s1="",s2="0",s3="",s4="";
    bool fl=0,ok=0;
    int pos=0;
    for(int i=0;i<s.size();i++)
        if(!fl&&s[i]=='0'){
        	ok=1;
			continue;
		}
        else fl=1,s1+=s[i];
    if(fl==0||s1==""){
    	cout<<"0\n";
    	return;
	}
    fl=0;
    for(int i=0;i<s1.size();i++)
        if(s1[i]=='0'){
            fl=1,pos=i;
            break;
        }
    if(!fl){
        for(int i=0;i<s1.size()-1;i++) cout<<1;
        cout<<(ok?"1\n":"0\n");
        return;
    }
    for(int i=0;i<pos;i++) s4+='1';
    for(int i=0;i<pos;i++){
        s3=s4;
        for(int j=pos;j<s1.size();j++) s3+=(s1[j]==s1[j-pos+i])?'0':'1';
        s2=max(s2,s3);
    }
    cout<<s2<<'\n';
    return;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>t;
    while(t--) slv();
	AC_AK
}
