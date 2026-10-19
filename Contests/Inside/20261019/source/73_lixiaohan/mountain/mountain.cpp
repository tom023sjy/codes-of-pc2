#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
int cnt[15],a[15];
int ss[5005];
signed main(){
    freopen("mountain.in","r",stdin);
    freopen("mountain.out","w",stdout);
    int C,j=1;
    string s;
    cin>>C>>s;
    int n=s.size();
    s=' '+s;
    if(C==10){
        int d=1;
        for(int i=1;i<n;i++){
            cout<<d<<" ";
            d*=2;
            d%=mod;
        }
        cout<<1;
        return 0;
    }
    if(C==11){
        int d=1;
        for(int i=1;i<n;i++){
            ss[i]=d;
        }
        ss[n]=1;
        for(int i=n;i>=1;i--){
            cout<<ss[i]<<" ";
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        a[i]=n-i+1;
        j*=i;
    }
    while(j--){
        int shang=a[1],flag=(s[a[1]]=='U');
        bool bigflag=true;
        for(int i=2;i<=n;i++){
            if(flag==true){
                if(shang<a[i]){
                    shang=a[i];
                    flag=(s[a[i]]=='U');
                }
                else{
                    bigflag=false;
                    break;
                }
            }
            else{
                if(shang>a[i]){
                    shang=a[i];
                    flag=s[a[i]]=='U';
                }
                else{
                    bigflag=false;
                    break;
                }
            }
        }
        if(bigflag){
            cnt[a[n]]++;
        }
        next_permutation(a+1,a+1+n);
    }
    for(int i=1;i<=n;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
