// 以 读入__int128 为例
#include <bits/stdc++.h>
using namespace std;
__int128 read() {
    __int128 res = 0; bool vis = 0;
    int c = getchar_unlocked();
    for (; !isdigit(c); c = getchar_unlocked()) {
        if (c == '-')
            vis = 1;
    }
    for (; isdigit(c); c = getchar_unlocked())
        res = res * 10 + c - '0';
    if (vis) res *= -1;
    return res;
}
void write(__int128 x) {
    if (x < 0) {
        putchar_unlocked('-');
        write(-x);
        return;
    }
    if (x >= 10) write(x / 10);
    putchar_unlocked(x % 10 + '0');
}
int main() {
    __int128 n = read();
    __int128 ans = 0;
    while (n --) 
        ans += read();
    write(ans);
}