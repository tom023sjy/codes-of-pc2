#include <bits/stdc++.h>
using namespace std;
#define i128 __int128
#define ll long long

i128 m, imx = 1000000000000000000ll;
const ll INF = 1000000000000000000ll;

void readi128(i128& x){
    x = 0; char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while ('0' <= ch && ch <= '9'){
        x = (x<<3) + (x<<1) + (ch^48);
        ch = getchar();
    }
}
void readint(int& x){
    x = 0; char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while ('0' <= ch && ch <= '9'){
        x = (x<<3) + (x<<1) + (ch^48);
        ch = getchar();
    }
}

char buf[1<<10];
void writei128(i128 x){
    int buftot = 0;
    while (x){
        buf[++buftot] = x % 10;
        x /= 10;
    }
    for (int i = buftot; i >= 1; i--){
        putchar(buf[i] + '0');
    }
}
void writeint(int x){
    int buftot = 0;
    while (x){
        buf[++buftot] = x % 10;
        x /= 10;
    }
    for (int i = buftot; i >= 1; i--){
        putchar(buf[i] + '0');
    }
}

i128 solvep(){
    i128 l = 1, r = INF;
    while (l <= r){
        i128 mid = l+r >> 1;
        //write(mid); putchar('\n');
        if (mid * (mid-1) / 2 <= m) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}

bool solvea(){
    for (int n = 2; n <= 400; n++){
        ll res = 0;
        for (int x = 1; x < n; x++){
            if (__gcd(x,n) == 1)
                res += x;
        }
        if (res == m){
            writeint(n); putchar('\n');
            return true;
        }
    }
    return false;
}

void solve(){
    readi128(m);
    if (solvea()) return;
    i128 res = solvep();
    writei128(res); putchar('\n');
}

int main(){
    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    imx *= imx;
    //write(imx); putchar('\n');
    int t; readint(t);
    while (t--) solve();
    return 0;
}
