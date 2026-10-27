#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int a[N + 5], box[N + 5];
signed main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        box[a[i]] ++;
    cout << *max_element(box + 1, box + N + 1);
    return 0;
}
