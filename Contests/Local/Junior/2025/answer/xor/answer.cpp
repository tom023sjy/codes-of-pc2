#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],f[5005]={1},ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        for(int j=5001;j>a[i];j--)(ans+=f[j])%=mod;
        for(int j=5001;j>=5001-a[i];j--)(f[5001]+=f[j])%=mod;
        for(int j=5000;j>=a[i];j--)(f[j]+=f[j-a[i]])%=mod;
    }
    cout<<ans;
    return 0;
}
