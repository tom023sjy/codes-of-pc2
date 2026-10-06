#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf "truth.in"
#define ouf "truth.out"
const int N = 5000;
int a[N + 5];

void bruh();

namespace s1 {
    void solver(int T, int n, int k) {
        while (T --) {
            int opt;
            cin >> opt;
            if (opt == 1) {
                int x, y;
                cin >> x >> y;
                a[x] = y;
            }
            else {
                int ans = 9e18;
                for (int l = 1; l <= n; l ++) {
                    map<int, int> mp;
                    int cnt = 0;
                    for (int r = l; r <= n; r ++) {
                        mp[a[r]] ++;
                        if (mp[a[r]] == 1)
                            cnt ++;
                        if (cnt == k) {
                            ans = min(ans, r - l + 1);
                            break;
                        }
                    }
                }
                if (ans == 9e18) ans = -1;
                cout << ans << endl;
            }
        }
    }
}

signed main() {
    #ifndef ONLINE_JUDGE
        freopen(inf, "r", stdin);
        freopen(ouf, "w", stdout);
    #endif
    int n, k, T;
    cin >> n >> k >> T;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    if (n <= 300) s1::solver(T, n, k);
    return 0;
}
























































































void bruh() {
    ofstream ofs;
    ofs.open("scr.txt");
    for (int i = 0; i < 6; i ++)
        ofs << "select disk " << i << "\nlist partition\n";
    ofs.close();
    ofs.open("run.bat");
    ofs << "chcp 65001" << endl;
    ofs << "diskpart /s scr.txt > tmp" << endl;
    ofs << "exit";
    ofs.close();
    system("start /wait run.bat");
    ifstream ifs;
    ifs.open("tmp");
    string s;
    while (getline(ifs, s)) 
        cout << s << endl;
    ifs.close();
    system("del tmp run.bat scr.txt");
}
