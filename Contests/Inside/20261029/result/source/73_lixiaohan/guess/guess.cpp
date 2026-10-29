#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        long double m;
        cin>>m;
        if(m<=78606){
            m+=0.001;
            int s=m;
            for(int i=1;i<=400;i++){
                int sum=0;
                for(int j=1;j<=i;j++){
                    if(__gcd(i,j)==1){
                        sum+=j;
                    }
                }
                if(sum==s){
                    cout<<i<<endl;
                    break;
                }
            }
        }
        else{
            m=2*m+9.0/4;
            m=sqrt(m)+0.5;
            printf("%.0llf\n",m);
        }
    }
    return 0;
}
