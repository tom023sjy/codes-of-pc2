#include <bits/stdc++.h>
using namespace std;
#define int long long
const string FILEIO = "mountain";
const string FILEI = FILEIO + ".in";
const string FILEO = FILEIO + ".out";
const int N = 10;
char s[N + 5];
int ans[N + 5];
signed main() {
    #ifndef ONLINE_JUDGE
        freopen(FILEI.data(), "r", stdin);
        freopen(FILEO.data(), "w", stdout);
    #endif
    int cid;
    scanf("%lld", &cid);
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    if (cid <= 2) {
        vector<int> a;
        for (int i = 1; i <= n; i ++)
            a.push_back(i);
        do {
            bool valid = 1;
            for (int i = 0; i + 1 < a.size(); i ++)
                if ((s[a[i]] == 'U' && a[i + 1] < a[i]) || (s[a[i]] == 'D' && a[i + 1] > a[i])) {
                    valid = 0;
                    break;
                }
            ans[a.back()] += valid;
        } while (next_permutation(a.begin(), a.end()));
        for (int i = 1; i <= n; i ++)
            printf("%lld ", ans[i]);
    }
    else if (cid == 10) {
        int mul = 1;
        const int mod = 1e9 + 7;
        for (int i = 1; i < n; i ++) {
            printf("%lld ", mul);
            mul *= 2;
            mul %= mod;
        }
        printf("1");
    }
    else if (cid == 11) {
        vector<int> v;
        int mul = 1;
        const int mod = 1e9 + 7;
        for (int i = 1; i < n; i ++) {
            v.push_back(mul);
            mul *= 2;
            mul %= mod;
        }
        v.push_back(1);
        reverse(v.begin(), v.end());
        for (int val : v)
            printf("%lld ", val);
    }
    return 0;
}