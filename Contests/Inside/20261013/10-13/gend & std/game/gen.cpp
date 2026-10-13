#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <chrono>
#include <vector>
using namespace std;
typedef long long ll;

ll rand_ll(ll L, ll R) {
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<ll> dis(L,R);
    return dis(gen);
}

// 生成链 1-2-3-...-n
vector<pair<int,int>> gen_chain(int n) {
    vector<pair<int,int>> edges;
    for(int i=1;i<=n-1;i++){
        edges.emplace_back(i,i+1);
    }
    return edges;
}

// 构造：n/2长主链保证深度O(n)；剩余点随机连到已存在节点，保持最大度O(n)
vector<pair<int,int>> gen_big_tree(int n) {
    vector<pair<int,int>> edges;
    vector<int> nodes;
    int chain_len = n/2;
    // 主干链 1 - 2 - ... - chain_len
    for(int i=1; i < chain_len; i++) {
        edges.emplace_back(i, i+1);
        nodes.push_back(i);
    }
    nodes.push_back(chain_len);

    // 剩下的点从 chain_len+1 ~ n，逐个随机连到nodes里的点
    // 故意提高1被选中概率，保证deg(1)是O(n)级别
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    for(int v = chain_len + 1; v <= n; v++) {
        // 加权：一半概率选1，另一半从已存在节点随机选
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

void gen_param(int caseid, int &n, vector<pair<int,int>>& edges) {
    if(caseid <= 2) {
        n = 7;
        edges = gen_big_tree(n);
    } else if(caseid <=6) {
        //3~6 n<=3000 链
        n = 3000;
        edges = gen_chain(n);
    } else if(caseid <=12) {
        //7~12 n<=3000 无特殊
        n = 3000;
        edges = gen_big_tree(n);
    } else if(caseid <=18) {
        //13~18 n<=2e5 链
        n = 200000;
        edges = gen_chain(n);
    } else {
        //19~25 n<=2e5，无特殊性质，深度O(n),最大度数O(n)
        n = 200000;
        edges = gen_big_tree(n);
    }
}

void write_in(int caseid, int n, const vector<pair<int,int>>& edges) {
    string fname = "game" + to_string(caseid) + ".in";
    ofstream f(fname);
    if (!f) {
        cerr << "Failed create " << fname << "\n";
        exit(1);
    }
    f << n << "\n";
    for(auto &e : edges) {
        f << e.first << " " << e.second << "\n";
    }
    f.close();
    cout << "Generate " << fname << "\n";
}

void write_out(int caseid) {
    string in = "game" + to_string(caseid) + ".in";
    string out = "game" + to_string(caseid) + ".out";
    string cmd = "./game_std < " + in + " > " + out + " 2>/dev/null";
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
        vector<pair<int,int>> edges;
        gen_param(cas,n,edges);
        write_in(cas,n,edges);
        write_out(cas);
    }
    cout << "\nAll 25 testcases generated (game1~game25 .in+.out)\n";
    return 0;
}
