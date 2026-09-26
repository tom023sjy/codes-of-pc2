#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int f[25000],a[25000],b[25000];
long long qpow(long long a,long long b){
    long long ans = 1;
    while(b != 0){
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("set.in","r",stdin);
    freopen("set.out","w",stdout);
    long long n;
    cin >> n;
    f[0] = f[1] = 1;
    a[1] = 1;
    for(long long i = 2;i <= n;i++){
        a[i] = 1;
        long long len = i * (i + 1) / 2;
        for(long long j = 0;j <= len;j++) b[j] = f[j];
        for(long long j = 0;j <= len - i;j++) f[i + j] = (f[i + j] + b[j]) % (mod - 1);
        // for(long long j = 1;j <= len;j++) cout << f[j] << " "; 
        // cout << '\n';
        for(int j = 1;j <= len;j++) a[i] = (a[i] * qpow(j,f[j])) % mod;
    }
    cout << a[n];
}