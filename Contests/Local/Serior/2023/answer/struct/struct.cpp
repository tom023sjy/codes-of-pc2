#include <bits/stdc++.h>
using namespace std;
#define int long long
// byte  1B
// short 2B
// int   4B
// long  8B
inline int BasicSize(string s) {
    if (s == "byte") return 1;
    if (s == "short") return 2;
    if (s == "int") return 4;
    if (s == "long") return 8;
    return 0;
}
class mix {
private:
    unordered_map<string, int> mp; // 为了效率，建反向name
public:
    int n; // 元素个数
    int size4k; //单块大小
    vector<string> type; // 类型
    vector<string> name; // 名称
    int size() {
        return n * size4k;
    }
    void init() {
        // 假设用户事先存储了 n name type
        // 这个函数将会计算 size4k mp
        for (int i = 1; i <= n; i ++)
            size4k = max(size4k, BasicSize(type[i])),
            mp[name[i]] = i;
    }
    int find(string val) {
        return (mp[val] - 1) * size4k;
    }
    string find(int addr) {
        addr /= size4k;
        addr ++;
        return name[addr];
    }
};;
struct data {
    mix type;
    int addr;
    int id;
    string name;
};
string name[1000];
signed main() {
	#ifndef ONLINE_JUDGE
        freopen("struct.in", "r", stdin);
        freopen("struct.out", "w", stdout);
    #endif
    unordered_map<string, mix> type; // 类型池
    unordered_map<string, data> dat; // 数据池
    int curr = 0, addr = 0; 
    // curr 当前分配的dataID
    // addr 下一个分配的data的ADDR偏移量
    int T;
    cin >> T;
    while (T --) {
        int opt;
        cin >> opt;
        if (opt == 1) {      // 申请一个Struct
            string s;
            int k;
            cin >> s >> k;
            mix t;
            t.n = k;
            t.name.resize(k + 1);
            t.type.resize(k + 1);
            for (int i = 1; i <= k; i ++) 
                cin >> t.type[i] >> t.name[i];
            t.init();
            type[s] = t;
            cout << type[s].size() << " " << type[s].size4k << endl;
        }
        else if (opt == 2) { // 申请一个Data
            string t, n;
            cin >> t >> n;
            dat[n] = {type[t], addr, ++ curr, n};
            name[curr] = n;
            cout << addr << endl;
            addr += type[t].size();
        }
        else if (opt == 3) {
            string s;
            cin >> s;
            cout << dat[s].addr + dat[s].type.find(s) << endl;
        }
        else {
            int addr;
            cin >> addr;
            int l = 1, r = curr, ans;
            while (l <= r) {
                int mid = l + r >> 1;
                if (dat[name[mid]].addr <= addr)
                    ans = mid, l = mid + 1;
                else r = mid - 1;
            }
            // ans 就是 addr 的 对应 data 段
            addr -= dat[name[ans]].addr;
            cout << dat[name[ans + 1]].type.find(addr) << endl;
        }
    }
    return 0;
}