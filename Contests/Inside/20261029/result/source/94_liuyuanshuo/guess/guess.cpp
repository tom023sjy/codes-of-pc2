#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
void sv1(){
    int res=0;
    for (int i=0;i<s.size();i++) res=res*10+s[i]-'0';
    for (int i=1;i<=400;i++){
        int sum=0;
        for (int j=1;j<i;j++) if (__gcd(i,j)==1) sum+=j;
        //cout<<sum<<"\n";
        if (sum==res) {
            cout<<i<<"\n";
            return ;
        }
    }
}
void sv2(){
    __int128 res=0,O=1,E=8,T=2;
    for (int i=0;i<s.size();i++) res=res*10+s[i]-'0';
    cout<<(int)((O+sqrt(O+res*E))/T)<<"\n";
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>s;
        if (s.size()<6) sv1();
        else sv2();
    }
    return 0;
}
