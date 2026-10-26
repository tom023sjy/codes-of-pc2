#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
struct Task {
    int s, t, id;
} a[N + 5];
bool cmp(Task x, Task y) {
    return x.t < y.t;
}
struct Printer {
    int id, ends;
};
bool operator >(Printer x, Printer y) {
    if (x.ends != y.ends)
        return x.ends > y.ends;
    return x.id > y.id;
}
vector<int> his[N + 5];
signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].s >> a[i].t, a[i].id = i;
    sort(a + 1, a + n + 1, cmp);
    priority_queue<Printer, vector<Printer>, greater<Printer>> q1, q2;
    for (int i = 1; i <= m; i ++)
        q2.push({i, 0});
    for (int i = 1; i <= n; i ++) {
        if (!q1.empty()) {
            vector<int> idx;
            while (!q1.empty()) {
                Printer t = q1.top();
                if (t.ends > a[i].t) 
                    break;
                idx.push_back(t.id);
                q1.pop();
            }
            for (int id : idx)
                q2.push({id, 0});
        }
        int p;
        if (!q2.empty()) {
            p = q2.top().id;
            q2.pop();
            q1.push({p, a[i].s + a[i].t});
        }
        else {
            p = q1.top().id;
            q1.push({p, a[i].s + q1.top().ends});
            q1.pop();
        }
        his[p].push_back(a[i].id);
    }
    for (int i = 1; i <= m; i ++) {
        cout << his[i].size() << " ";
        sort(his[i].begin(), his[i].end());
        for (int val : his[i])
            cout << val << " ";
        cout << endl;
    }
    return 0;
}