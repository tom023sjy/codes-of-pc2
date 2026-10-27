#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    sort(s.begin(), s.end(), greater<char>());
    for (char c : s) 
        if (isdigit(c))
            cout << c;
    return 0;
}