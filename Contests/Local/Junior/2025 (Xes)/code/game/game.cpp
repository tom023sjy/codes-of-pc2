#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
string ops[N + 5];
int opts[N + 5];

void ExecOp(int x, int y, int l, int r) {
    for (int i = l; i <= r; i ++) {
        if (ops[i] == "swap") swap(x, y);
        if (ops[i] == "x") x += opts[i];
        if (ops[i] == "y") y += opts[i];
    }
    cout << x << " " << y << endl;
}

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n, sx, sy;
    cin >> n >> sx >> sy;
    for (int i = 1; i <= n; i ++) {
        cin >> ops[i];
        if (ops[i] != "swap")
            cin >> opts[i];
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i ++) {
        int l, r;
        cin >> l >> r;
        ExecOp(sx, sy, l, r);
    }
    return 0;
}
