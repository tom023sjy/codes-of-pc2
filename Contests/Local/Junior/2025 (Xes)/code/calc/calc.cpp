#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("calc.in", "r", stdin);
    freopen("calc.out", "w", stdout);
    string a, b;
    char op;
    cin >> a >> op >> b;
    if (op == '*') {
        cout << 1;
        for (int i = 1; i <= a.size() + b.size() - 2; i ++)
            cout << 0;
    }
    else {
        /*
        1 0 0 0 0 0 0 7
                1 0 0 3
        1 0 0 0 1 0 0
        */
        if (a.size() < b.size())
            swap(a, b);
        int p1 = a.find('1');
        int p2 = b.find('1');
        if (a.size() != b.size()) {
            cout << 1;
            for (int i = 1; i < a.size() - b.size(); i ++)
                cout << 0;
            cout << 1;
            for (int i = 1; i < b.size(); i ++)
                cout << 0;
        }
        else {
            cout << 2;
            for (int i = 2; i <= a.size(); i ++)
                cout << 0;
        }
    }
    return 0;
}
