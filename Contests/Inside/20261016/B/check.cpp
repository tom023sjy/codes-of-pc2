#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    system("g++ upload.cpp -std=c++14 -O2 -Wall -o upd");
    system("g++ force.cpp -std=c++14 -O2 -Wall -o ans");
    system("g++ rand.cpp -std=c++14 -O2 -Wall -o rnd");
    for (int i = 1; ; i ++) {
        system("./rnd > data.in");
        system("./upd < data.in > data.out");
        system("./ans < data.in > data.ans");
        if (system("diff -w data.out data.ans"))
            return 0;
        cout << i << "\n";
    }
    return 0;
}