#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n,m,q;
int a[N][N];

int main(){
    freopen("familiar.in","r",stdin);
    freopen("familiar.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    while (q--){
        int op,x,y,k; cin >> op >> x >> y;
        if (op == 1){
            cin >> k;
            k = 2*m - k + 1;
            int l = 0, r = 1e9;
            while (l <= r){
                int mid = l+r >> 1;
                int i1 = lower_bound(a[x]+1, a[x]+m+1, mid) - a[x] - 1, i2 = lower_bound(a[y]+1, a[y]+m+1, mid) - a[y] - 1;
                //printf("m %d %d %d\n", mid, i1,i2);
                if (i1 + i2 <= k-1) l = mid + 1;
                else r = mid - 1;
            }
            cout << r << '\n';
        }
        else{
            int id = upper_bound(a[x]+1,a[x]+m+1, y) - a[x] - 1;
            if (id >= 1)
                a[x][id] = y;
        }
    }
    return 0;
}
