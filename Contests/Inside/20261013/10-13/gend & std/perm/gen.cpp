#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rand_ll(ll L, ll R) {
    uniform_int_distribution<ll> dis(L,R);
    return dis(rng);
}

// 生成链：1-2-3-...-n
vector<pair<int,int>> gen_chain(int n) {
    vector<pair<int,int>> edges;
    for(int i=1;i<=n-1;i++){
        edges.emplace_back(i,i+1);
    }
    return edges;
}

// 生成普通大树：主干链n/2，剩下节点一半连根，一半随机挂靠
vector<pair<int,int>> gen_big_tree(int n) {
    vector<pair<int,int>> edges;
    vector<int> nodes;
    int chain_len = n/2;
    for(int i=1; i < chain_len; i++) {
        edges.emplace_back(i, i+1);
        nodes.push_back(i);
    }
    nodes.push_back(chain_len);

    for(int v = chain_len + 1; v <= n; v++) {
        int u;
        if(rand_ll(0,1) == 0) {
            u = 1;
        } else {
            u = nodes[rand_ll(0, (int)nodes.size()-1)];
        }
        edges.emplace_back(u, v);
        nodes.push_back(v);
    }
    return edges;
}

struct SegTreeMin {
    int n;
    vector<int> val;
    SegTreeMin(int sz) {
        n = 1;
        while(n < sz) n <<= 1;
        val.assign(2*n, INF);
    }
    void modify(int p, int v) {
        p += n - 1;
        val[p] = v;
        for(p >>= 1; p >= 1; p >>= 1) {
            val[p] = min(val[p<<1], val[p<<1|1]);
        }
    }
    int query(int l, int r) { // [l, r]
        int res = INF;
        l += n - 1;
        r += n - 1;
        for(; l <= r; l >>=1, r >>=1) {
            if(l & 1) res = min(res, val[l++]);
            if(!(r & 1)) res = min(res, val[r--]);
        }
        return res;
    }
};

vector<int> compute_d(int n, const vector<pair<int,int>>& edges, const vector<int>& P) {
    vector<vector<int>> adj(n+1);
    for(auto &e : edges) {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }
    vector<int> in(n+1), out(n+1), depth(n+1);
    int dfn = 0;
    auto dfs_build = [&](auto&& self, int u, int fa) -> void {
        in[u] = ++dfn;
        for(int v : adj[u]) {
            if(v == fa) continue;
            depth[v] = depth[u] + 1;
            self(self, v, u);
        }
        out[u] = dfn;
    };
    dfs_build(dfs_build, 1, -1);

    vector<int> pos(n+1);
    for(int i=0;i<n;i++) {
        pos[P[i]] = i;
    }

    SegTreeMin seg(n);
    vector<int> d(n+1, -1);

    // 扫描线：按排列P顺序处理
    for(int i=0; i<n; i++) {
        int u = P[i];
        int minD = seg.query(in[u], out[u]);
        if(minD != INF) {
            d[u] = minD - depth[u];
        } else {
            d[u] = -1;
        }
        seg.modify(in[u], depth[u]);
    }

    vector<int> res;
    for(int i=1;i<=n;i++) {
        res.push_back(d[i]);
    }
    return res;
}

void gen_param(int caseid, int &n, vector<int>&d, vector<pair<int,int>>& edges) {
    if(caseid == 1 || caseid == 2) {
        n = 10;
        edges = gen_big_tree(n);
        if(caseid == 1) {
            // case1：d直接随机生成，不经过compute_d
            d.resize(n);
            for(int i=0;i<n;i++) {
                d[i] = rand_ll(-1, 20);
            }
        } else {
            // case2：随机排列P，真实计算d
            vector<int> P(n);
            for(int i=0;i<n;i++) P[i] = i+1;
            shuffle(P.begin(), P.end(), rng);
            d = compute_d(n, edges, P);
        }
    } else if(caseid >=3 && caseid <=6) {
        n = 18;
        edges = gen_big_tree(n);
        vector<int> P(n);
        for(int i=0;i<n;i++) P[i] = i+1;
        shuffle(P.begin(), P.end(), rng);
        d = compute_d(n, edges, P);
    } else if(caseid >=7 && caseid <=12) {
        n = 3000;
        edges = gen_big_tree(n);
        vector<int> P(n);
        for(int i=0;i<n;i++) P[i] = i+1;
        shuffle(P.begin(), P.end(), rng);
        d = compute_d(n, edges, P);
    } else if(caseid ==13 || caseid ==14) {
        n = 500000;
        edges = gen_chain(n); // 链特殊性质 u_i=i, v_i=i+1
        vector<int> P(n);
        for(int i=0;i<n;i++) P[i] = i+1;
        shuffle(P.begin(), P.end(), rng);
        d = compute_d(n, edges, P);
    } else { // 15~25
        n = 500000;
        edges = gen_big_tree(n);
        vector<int> P(n);
        for(int i=0;i<n;i++) P[i] = i+1;
        shuffle(P.begin(), P.end(), rng);
        d = compute_d(n, edges, P);
    }
}

void write_in(int caseid, int n, const vector<int>&d, const vector<pair<int,int>>& edges) {
    string fname = "perm" + to_string(caseid) + ".in";
    ofstream f(fname);
    if (!f) {
        cerr << "Failed create " << fname << "\n";
        exit(1);
    }
    f << n << "\n";
    for(int i=0;i<n;i++) {
        if(i>0) f << " ";
        f << d[i];
    }
    f << "\n";
    for(auto &e : edges) {
        f << e.first << " " << e.second << "\n";
    }
    f.close();
    cout << "Generate " << fname << "\n";
}

void write_out(int caseid) {
    string in = "perm" + to_string(caseid) + ".in";
    string out = "perm" + to_string(caseid) + ".out";
    string cmd = "./perm_std < " + in + " > " + out + " 2>/dev/null";
    int ret = system(cmd.c_str());
    if (ret == 0) {
        cout << "Generate " << out << "\n";
    } else {
        cerr << "Warning: fail generate " << out << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int cas = 1; cas <= 25; ++cas) {
        int n;
        vector<int> d;
        vector<pair<int,int>> edges;
        gen_param(cas,n,d,edges);
        write_in(cas,n,d,edges);
        write_out(cas);
    }
    cout << "\nAll testcases generated\n";
    return 0;
}
