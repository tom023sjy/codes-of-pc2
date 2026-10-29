#include <bits/stdc++.h>
using namespace std;

const int N = 502, H = 52;
int n, ht[H], hs[N];
bitset<N*H> bit[N];
bitset<N*H> ans;

int main(){
    freopen("cup.in","r",stdin);
    freopen("cup.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> hs[i];
    }
    sort(hs+1,hs+n+1);
    for (int i = 1; i <= n; i++){
        ht[i] = hs[i];
        hs[i] += hs[i-1];
    }
    ans[0] = bit[0][0] = true;
    for (int i = 1; i <= n; i++){
        for (int c = 0; c < i; c++){
            for (int j = hs[i-1]; j >= 0; j--){
                bit[c+1][j + ht[i]] = bit[c+1][j + ht[i]] | bit[c][j];
                //if (bit[c][j])
                  //  bit[c+1][j + ht[i]] = true;
            }
        }
        for (int j = i+1; j < n; j++){
            for (int c = 1; c <= i; c++){
                for (int sz = 1; sz <= hs[i]; sz++){
                    //ans[c*ht[j] - sz] |= bit[c][sz];
                    if (c*ht[j] - sz < 0) break;
                    ans[c*ht[j] - sz] = ans[c*ht[j] - sz] | bit[c][sz];
                    //if (bit[c][sz])
                      //  ans[c*ht[j] - sz] = true;
                }
            }
        }
    }
    for (int sz = 0; sz <= n*50; sz++){
        if (ans[sz]){
            cout << sz << ' ';
        }
    }
    return 0;
}
