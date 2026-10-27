#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
int a[N + 5], ans[N + 5];
signed main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
    	cin >> a[i];
    deque<int> q;
    for (int r = 1; r <= n; r ++) {
        while (!q.empty() && q.front() < r - k + 1) q.pop_front();
        while (!q.empty() && a[q.back()] <= a[r]) q.pop_back();
        q.push_back(r);
        if (r >= k)
            ans[r - k + 1] = q.front();
	}
    for (int i = 1; i <= n - k + 1; i ++)
        cout << a[ans[i]] << " ";
	return 0;
}