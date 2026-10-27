#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
struct Node {
    int id, w;
};
vector<Node> g[N + 5];
bool operator > (Node x, Node y) {
    return x.w > y.w;
}
int dis[N + 5];
bool vis[N + 5];
void dijkstra(int s) {
    priority_queue<Node, vector<Node>, greater<Node>> q;
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    q.push({s, 0});
    dis[s] = 0;
    while (!q.empty()) {
        Node t = q.top();
        q.pop();
        if (vis[t.id]) continue;
        vis[t.id] = 1;
        for (Node nxt : g[t.id])
            if (dis[nxt.id] > dis[t.id] + nxt.w) {
                dis[nxt.id] = dis[t.id] + nxt.w;
                q.push({nxt.id, dis[nxt.id]});
            }
    }
}