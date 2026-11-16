#include <bits/stdc++.h>
using namespace std;
#define int32 signed
#define int __int128
pair<int, pair<int, int>> exgcd(int a, int b) {
    if (b == 0) return {a, {1, 0}};
    auto ret = exgcd(b, a % b);
    int g = ret.first, x = ret.second.first, y = ret.second.second;
    int rx = y, ry = x - a / b * y;
    return {g, {rx, ry}};
}
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
void scanf(int &x) {
    x = 0;
    string str;
    cin >> str;
    for (char ch : str)
        x = x * 10 + ch - '0';
}
void printf(int x) {
    if (x < 0) cout << '-', x = -x;
    if (x == 0) return ;
    printf(x / 10);
    char ch = x % 10 + '0';
    cout << ch;
}
int32 main() {
	int n, m, l;
    scanf(n), scanf(m), scanf(l);
    /*
第m轮的时候
x号牌在(2^m * x) mod (n + 1) 这个位置上
现在不知道x，但是有替代 l
(2^m * x) mod (n + 1) = l
可以得
fp(2, m, n + 1) * x + y * (n + 1) = l
令 A = fp(2, m, n + 1), B = (n + 1)
则 Ax+By=l
也就是exgcd的模
    */
    int A = fp(2, m, n + 1), B = n + 1;
    auto ret = exgcd(A, B);
    if (l % ret.first) 
        return puts("what happend???");
    int x = ret.second.first, g = ret.first;
    x = x * l / g;
    x %= B;
    x += B;
    x %= B;
    printf(x);
    return 0;
}
