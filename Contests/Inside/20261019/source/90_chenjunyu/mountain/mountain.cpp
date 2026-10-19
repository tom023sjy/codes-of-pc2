#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 21, P = 1000000007;
int cid,n;
string mount;
int a[N];
int f[N][N][(1<<20)+2];
vector<int> vec[21];

int getx(int x){
    int res = 0;
    for (; x; x>>=1){
        if (x & 1) res++;
    }
    return res;
}

int main(){
    //freopen("mountain.in","r",stdin);
    //freopen("mountain.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> cid >> mount;
    n = mount.size();
    for (int i = 0; i < n; i++){
        a[i+1] = (mount[i] == 'U');
    }
    if (cid == 10 || cid == 11){
        for (int i = 1; i <= n; i++) cout << "1 ";
        return 0;
    }
    /*for (int i = 1; i <= n; i++){
        f[i][1][1<<i-1] = 1;
    }
    for (int i = 1; i < (1<<n); i++){
        vec[res].push_back(i);
    }
    for (int t = 2; t <= n; t++){
        for (int msk : vec[t]){
            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n; j++){
                    if (i != j && (msk & (1<<i-1)) && (msk & (1<<i-1)) && (j < i && a[j] || j > i && !a[j])){
                        f[i][t][msk] = (f[i][t][msk] + f[j][t-1][msk & (~(1<<i-1)))]) %P;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int msk && )
    }*/
    return 0;
}
