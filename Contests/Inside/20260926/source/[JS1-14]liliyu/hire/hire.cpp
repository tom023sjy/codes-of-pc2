#include<bits/stdc++.h>
using namespace std;
int a[500005],ton[500005];
int n,m,k,d;
void init(int n){
    for(int i = 1;i <= n;i++){
        a[i] = k;
    }
}
bool find_plan(){
    for(int i = 1;i <= n;i++){
        if(ton[i] != 0){
            int sum = 0;
            for(int j = i;j <= i + d;j++){
                sum += a[j];
            }
            if(sum < ton[i]) return false;
            else{
                int peo = ton[i];
                for(int j = i;j <= i + d;j++){
                    if(peo == 0) break;
                    if(peo >= a[j]) peo -= a[j],a[j] = 0;
                    else a[j] -= peo,peo = 0;
                }
            }
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("hire.in","r",stdin);
    freopen("hire.out","w",stdout);
    cin >> n >> m >> k >> d;
    while(m--){
        int x,y;
        cin >> x >> y;
        init(n);
        ton[x] += y;
        bool ans = find_plan();
        if(ans){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}