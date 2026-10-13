#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rand_ll(ll L, ll R) {
    uniform_int_distribution<ll> dis(L,R);
    return dis(rng);
}

// 从a抽取子序列，保持原序，保证非空
vector<int> get_random_subseq(const vector<int>& a) {
    vector<int> b;
    for(int x : a) {
        if(rand_ll(0, 1)) {
            b.push_back(x);
        }
    }
    if(b.empty()) b.push_back(a[0]);
    return b;
}

void gen_case(int caseid, int &n, vector<int>&a, vector<int>&b) {
    if(caseid >= 1 && caseid <= 6) {
        n = 10;
        a.resize(n);
        for(int i=0;i<n;i++) a[i] = rand_ll(1, n);
        b = get_random_subseq(a);
    } else if(caseid >=7 && caseid <=14) {
        n = 5000;
        a.resize(n);
        for(int i=0;i<n;i++) a[i] = rand_ll(1, n);
        b = get_random_subseq(a);
    } else if(caseid ==15 || caseid ==16) {
        n = 100000;
        a.resize(n);
        for(int i=0;i<n;i++) a[i] = i+1; // a严格递增
        b = get_random_subseq(a);
        // 15,16特殊性质：b必须严格递增，禁止shuffle！
        return;
    } else if(caseid >=17 && caseid <=20) {
        n = 100000;
        a.resize(n);
        for(int i=0;i<n;i++) a[i] = i+1;
        shuffle(a.begin(), a.end(), rng); // a是排列，元素互不相同
        b = get_random_subseq(a);
    } else { // 21~25
        n = 100000;
        a.resize(n);
        for(int i=0;i<n;i++) a[i] = rand_ll(1, n);
        b = get_random_subseq(a);
    }

    // 只有非15/16才执行0.5概率shuffle
    if(rand_ll(0, 1) == 1) {
        shuffle(b.begin(), b.end(), rng);
    }
}

void write_one_file(int caseid, const vector<int>& all_n, const vector<vector<int>>& all_a, const vector<vector<int>>& all_b) {
    string fname = "minmax" + to_string(caseid) + ".in";
    ofstream f(fname);
    if(!f) {
        cerr << "Failed to open " << fname << endl;
        exit(EXIT_FAILURE);
    }
    int T = all_n.size();
    f << T << "\n";
    for(int t=0; t<T; t++) {
        int n = all_n[t];
        int m = (int)all_b[t].size();
        f << n << " " << m << "\n";
        for(size_t i=0; i<all_a[t].size(); i++) {
            if(i>0) f << " ";
            f << all_a[t][i];
        }
        f << "\n";
        for(size_t i=0; i<all_b[t].size(); i++) {
            if(i>0) f << " ";
            f << all_b[t][i];
        }
        f << "\n";
    }
    f.close();
    cout << "Generated " << fname << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int total_test_files = 25;
    for(int cas = 1; cas <= total_test_files; cas++) {
        vector<int> all_n;
        vector<vector<int>> all_a, all_b;
        const int T = 10;
        for(int t=0; t<T; t++) {
            int n;
            vector<int> a,b;
            gen_case(cas, n, a, b);
            all_n.push_back(n);
            all_a.push_back(a);
            all_b.push_back(b);
        }
        write_one_file(cas, all_n, all_a, all_b);
        all_n.clear();
        all_a.clear();
        all_b.clear();
    }
    cout << "\nAll 25 minmax input files generated\n";
    return 0;
}
