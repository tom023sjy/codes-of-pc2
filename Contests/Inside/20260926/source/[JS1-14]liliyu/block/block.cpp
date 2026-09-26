#include<bits/stdc++.h>
using namespace std;
int a[100005];
vector<int> tree[100005];
int ban[100005];
int sum[100005];
int all_ans;
int build(int u){
    int ans = a[u];
    for(int v : tree[u]){
    	if(ban[u] == v || ban[v] == u) continue;
        ans += build(v);
    }
    return ans;
}
void dfs(int u){
    for(int v : tree[u]){
        if(ban[u] == v || ban[v] == u) continue;
        if(sum[v] > 0) all_ans += sum[v];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        int s;
        cin >> s;
        for(int j = 1;j <= s;j++){
            int x;
            cin >> x;
            tree[i].push_back(x);
        }
    }
    for(int i = 1;i <= m;i++){
        int u,v;
        cin >> u >> v;
        ban[u] = v;
        ban[v] = u;
    }
    build(1);
    dfs(1);
    cout << all_ans;
}
