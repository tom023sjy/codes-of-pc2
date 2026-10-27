const int N = 3e6;
int mmp[128], curr;
struct Node {
    int sums;
    vector<int> sons;
    Node() {
        sums = 0;
        sons.resize(62, 0);
    }
} tree[N + 5];
void clean(int idx) {
    tree[idx].sums = 0;
    for (int nxt : tree[idx].sons)
        if (nxt)
            clean(nxt);
    fill(tree[idx].sons.begin(), tree[idx].sons.end(), 0);
}
void insert(string str) {
    int idx = 0;
    for (char c : str) {
        if (tree[idx].sons[mmp[c]] == 0) {
            curr ++;
            tree[idx].sons[mmp[c]] = curr;
        }
        idx = tree[idx].sons[mmp[c]];
        tree[idx].sums ++;
    }
}
void init() {
    int p = 0;
    for (char c = '0'; c <= '9'; c ++)
        mmp[c] = p ++;
    for (char c = 'A'; c <= 'Z'; c ++)
        mmp[c] = p ++;
    for (char c = 'a'; c <= 'z'; c ++)
        mmp[c] = p ++;
}
int query(string s) {
    int idx = 0;
    for (char c : s) {
        idx = tree[idx].sons[mmp[c]];
        if (!idx)
            break;
    }
    if (idx)
        return tree[idx].sums;
    return 0;
}