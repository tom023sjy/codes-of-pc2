#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2020;
int n;
int h[N];
bitset<200010> dp[N];
int num[N];
vector<int>e;
signed main(){
    freopen("cup.in","r",stdin);
    freopen("cup.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int sum = 0;
    for(int i = 1;i<=n;i++){
        cin>>h[i];
    }
    sort(h+1,h+n+1);
    for(int i = 1;i<=n-1;i++)num[h[i]]++;
    dp[0][0] = 1;
    // for(int i = 1;i<=n-1;i++){
    //     sum+=h[i];
    //     for(int k = i;k<=n-1;k++){
    //         //dp[i][j+h[k]]|=dp[i-1][j];
    //         dp[i]|=(dp[i-1]<<h[k]);
    //     }
    // }
    for(int i = 1;i<=n-1;i++){
        sum+=h[i];
        for(int k = h[i];k<=50;k++){
            //dp[i][j+h[k]]|=dp[i-1][j];
            if(num[k]!=0)dp[i]|=(dp[i-1]<<k);
        }
    }
    for(int i = 0;i<=200000;i++){
        if(dp[n-1][i])cout<<i-sum<<' ';
    }
    cout<<"\n";
    return 0;
}