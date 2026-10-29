#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
int num[5050];
int gcd(int x,int y){
    if(y==0)return x;
    return gcd(y,x%y);
}
void init(){
    for(int i = 1;i<=5000;i++){
        for(int j = 1;j<=i;j++){
            if(gcd(i,j)==1)num[i]+=j;
        }
    }
}
signed main(){
    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);
    init();
    cin>>T;
    while(T--){
        int x;
        cin>>x;
        for(int i = 1;i<=5000;i++){
            if(num[i]==x){
                cout<<i<<"\n";
                break;
            }
        }
    }



    return 0;
}