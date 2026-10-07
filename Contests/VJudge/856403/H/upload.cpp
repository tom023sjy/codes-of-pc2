#include <bits/stdc++.h>
using namespace std;
#define int long long
class SegT {
private:
    // Static Variable Declarations
    static const int N = 4e6;
    const int m1 = 1e9 + 7, m2 = 998244353, m3 = 65537;
    const int bs = 233;
    // Hash Template
    struct Hash {
        int a, b, c;
        inline void operator = (Hash z) {
            a = z.a;
            b = z.b;
            c = z.c;
        }
        friend bool operator == (Hash x, Hash y) {
            return x.a == y.a && x.b == y.b && x.c == y.c;
        }
        friend bool operator < (Hash x, Hash y) {
            if (x.a != y.a) return x.a < y.a;
            if (x.b != y.b) return x.b < y.b;
            return x.c < y.c;
        }
    } t[N + 5];
    
public:

} lft, rgt;
signed main() {
    int n, T;
    cin >> n >> T;
    
    return 0;
}
