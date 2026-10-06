#include <bits/stdc++.h>
using namespace std;
#define int long long

// Config.ini
#define readf "xor.in"
#define writf "xor.out"

const int N = 1e7;
char s[N + 5];
string del0(string s) {
    int pos = 0;
    while (pos < s.size() && s[pos] == '0') pos ++;
    if (pos >= s.size()) return "0";
    return s.substr(pos);
}
class Trie {
private:
    struct Node {
        bool val;
        vector<int> child;
        Node() { val = 0; child.resize(2, -1); }
    };
    Node a[N + 5];
    Node null;
    int curr = 0;
public: 
    void clean(int id) {
        for (int b = 0; b < 2; b ++)
            if (a[id].child[b] != -1)
                clean(a[id].child[b]);
        a[id] = null;    
    }
    void update(string s) {
        int ptr = 0;
        for (char c : s) {
            if (a[ptr].child[c == '1'] == -1) {
                curr ++;
                a[ptr].child[c == '1'] = curr;
                a[curr].val = (c == '1');
            }
            ptr = a[ptr].child[c == '1'];
        }
        // cerr << ptr << endl; 
    }
    string query(string s) {
        int ptr = 0;
        string res;
        for (char c : s) {
            if (a[ptr].child[c == '0'] != -1)
                res += '1', ptr = a[ptr].child[c == '0'];
            else res += '0', ptr = a[ptr].child[c == '1'];
        }
        return res;
    }
} trie;
signed main() {
    freopen(readf, "r", stdin);
    freopen(writf, "w", stdout);
    deque<char> q;
    int T;
    cin >> T;
    while (T --) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i ++)
            cin >> s[i];
        for (int len = 1; len <= n; len ++) {
            q.clear();
            int l = 1, r = len;
            for (int i = l; i <= r; i ++)
                q.push_back(s[i]);
            while (r <= n) {
                string ps;
                for (int i = 1; i <= n - len; i ++)
                    ps += '0';
                for (char c : q)
                    ps += c;
                trie.update(ps);
                r ++;
                q.pop_front();
                q.push_back(s[r]);
            }
        }
        string ans;
        for (int len = 1; len <= n; len ++) {
            q.clear();
            int l = 1, r = len;
            for (int i = l; i <= r; i ++)
                q.push_back(s[i]);
            while (r <= n) {
                string ps;
                for (int i = 1; i <= n - len; i ++)
                    ps += '0';
                for (char c : q)
                    ps += c;
                string res = trie.query(ps);
                if (ans < res)
                    ans = res;
                r ++;
                q.pop_front();
                q.push_back(s[r]);
            }
        }
        cout << del0(ans) << endl;
        trie.clean(0);
    }
    return 0;
}
