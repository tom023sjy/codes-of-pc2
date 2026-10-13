#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <chrono>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ll rand_ll(ll L, ll R) {
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<ll> dis(L,R);
    return dis(gen);
}

// 生成排列
vector<int> gen_perm(int n) {
    vector<int> p(n);
    for(int i=0;i<n;i++) p[i]=i+1;
    shuffle(p.begin(),p.end(),mt19937_64(chrono::steady_clock::now().time_since_epoch().count()));
    return p;
}

void gen_param(int caseid, int &n, vector<int>&a, vector<int>&b) {
    if(caseid <=3) {
        //1~3 n<=300
        n = 300;
        a = gen_perm(n);
        b = gen_perm(n);
    } else if(caseid <=11) {
        //4~11 n<=5000
        n = 5000;
        a = gen_perm(n);
        b = gen_perm(n);
    } else if(caseid <=13) {
        //12~13 n<=5e5, a_i = b_i
        n = 500000;
        a = gen_perm(n);
        b = a;
    } else if(caseid <=17) {
        //14~17 n<=5e5, a_i = i
        n = 500000;
        a.resize(n);
        for(int i=0;i<n;i++) a[i]=i+1;
        b = gen_perm(n);
    } else {
        //18~25 n<=5e5, no special
        n = 500000;
        a = gen_perm(n);
        b = gen_perm(n);
    }
}

void write_in(int caseid, int n, const vector<int>&a, const vector<int>&b) {
    string fname = "maxmin" + to_string(caseid) + ".in";
    ofstream f(fname);
    if (!f) {
        cerr << "Failed create " << fname << "\n";
        exit(1);
    }
    f << n << "\n";
    for(int i=0;i<n;i++) {
        if(i>0) f << " ";
        f << a[i];
    }
    f << "\n";
    for(int i=0;i<n;i++) {
        if(i>0) f << " ";
        f << b[i];
    }
    f << "\n";
    f.close();
    cout << "Generate " << fname << "\n";
}

void write_out(int caseid) {
    string in = "maxmin" + to_string(caseid) + ".in";
    string out = "maxmin" + to_string(caseid) + ".out";
    string cmd = "./maxmin_std < " + in + " > " + out + " 2>/dev/null";
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
        vector<int> a,b;
        gen_param(cas,n,a,b);
        write_in(cas,n,a,b);
        write_out(cas);
    }
    cout << "\nAll 25 testcases generated (maxmin1~maxmin25 .in+.out)\n";
    return 0;
}
