#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
#define int long long
const int N = 100000;
int a[N + 5], s[N + 5];
vector<int> pos[N + 5];
signed main() {
	int c, n;
    while (1) {
        cin >> c >> n;
        if (c == 0 && n == 0) return c;
        for (int i = 1; i <= n; i ++)
            cin >> a[i];
        for (int i = 1; i <= n; i ++)
            s[i] = s[i - 1] + a[i], s[i] %= c;
        for (int i = 0; i < c; i ++)
            pos[i].clear();
        for (int i = 0; i <= n; i ++)
            pos[s[i]].push_back(i);
        bool flg = 0;
        int l, r;
        for (int i = 0; i < c; i ++)
            if (pos[i].size() >= 2) {
                l = pos[i][0], r = pos[i][1];
                flg = 1;
            }
        if (flg) 
            for (int i = l + 1; i <= r; i ++)
                cout << i << " ";
        else printf("no sweets");
        puts(" ");
    }
    return 0;
}
