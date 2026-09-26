#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=1e9+7;
const int inv=500000004;

void solve() {
    int len;
    cin>>len;
    string s;
    cin>>s;
    int L=0,R=0;
    for(int i=0;i<len;i++) {
        if(s[i]=='0') L++;
        else break;
    }
    for(int i=len-1;i>=0;i--) {
        if(s[i]=='0') R++;
        else break;
    }
    int num=len-L-R;
    if(num&1) num--;
    int ans=0;
    for(int i=0;i<=num;i+=2) {
        for(int j=0;i+j<=num;j+=2) {
            int a=i/2;
            int b=j/2;
            int u=a*L%MOD-a+1;
            int v=b*R%MOD-b+1;
            if(u<0) u+=MOD;
            if(v<0) v+=MOD;
            ans=(ans+u*v%MOD)%MOD;
        }
    }
    cout<<ans;
    return ;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
    solve();
    return 0;
}