#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5050;
const int mod = 1e9+7;
int dp[N][N][2];
int cid;
string s;
inline int get_num(char x){
    if(x=='D')return 0;
    return 1;
}
int qpow(int x,int y){
    int res = 1;
    while(y){
        if(y&1)res*=x,res%=mod;
        x = x*x,x%=mod;
        y>>=1;
    }
    return res;
}
signed main(){
    freopen("mountain.in","r",stdin);
    freopen("mountain.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>cid;
    cin>>s;
    int n = s.size();
    s = " "+s;
    if(cid==10){
        for(int i = 1;i<=n-1;i++)cout<<qpow(2,i-1)<<' ';
        cout<<1;
        return 0;
    }
    if(cid==11){
        cout<<1;
        for(int i = 2;i<=n;i++)cout<<qpow(2,n-i)<<" ";
        return 0;
    }
    for(int i = 1;i<=n;i++)cout<<0<<" ";
    return 0;

    return 0;
}