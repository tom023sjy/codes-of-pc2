#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k;
int dp[210][25000]
ll qpow(int n,int k){
    ll tmp=n,ans=1;
    while(k){
        if(k&1){
            ans=(ans*tmp)%mod;
        }
        tmp=(tmp*tmp)%mod;
        k>>=1;
    }
    return ans;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        dp[1][i]=1;
    }
    int mx=((n+1)*n)/2;
    cout<<qpow(n,k);
    return 0;
}