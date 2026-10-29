#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1000005;
int n;
int a[N];
ll f[N];

int main(){
    freopen("express.in","r",stdin);
    freopen("express.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    memset(f,0x3f,sizeof(f));
    //f[0][0] = 0;
    //f[1][0] = a[1];
    f[0] = a[1];
    for (int i = 2; i <= n; i++){
        for (int j = 0; j <= i-2; j++){
            f[i-1] = min(f[i-1], f[j] + abs(a[i] - a[j]));
            f[j] += abs(a[i] - a[i-1]);
        }
        /*for (int k = 0; k <= i-2; k++){
            f[i][i-1] = min(f[i][i-1], f[i-1][k] + abs(a[i] - a[k]));
            f[i][k] = f[i-1][k] + abs(a[i] - a[i-1]);
        }*/
    }
    //for (int i = 1; i < n; i++)
      //  ans = min(ans, f[n][i]);
    cout << f[n-1];
    return 0;
}
