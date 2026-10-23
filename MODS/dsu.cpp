struct DSU {
    vector<int> f;
    int sz;
    DSU (int n = 0) {
        resize(n);
    }
    int find(int id) {
        if (f[id] != id)
            f[id] = find(f[id]);
        return f[id];
    }
    void merge(int a, int b) {
        int fta = find(a), ftb = find(b);
        if (fta != ftb)
            f[fta] = ftb;
    }
    bool query(int a, int b) {
        return find(a) == find(b);
    }
    void clear() {
        f.clear();
        sz = 0;
    }
    void resize(int nsz) {
        clear();
        f.resize(nsz + 5);
        sz = nsz;
        f[0] = 0;
        f[nsz + 1] = f[nsz + 2] = f[nsz + 3] = f[nsz + 4] = 0;
        for (int i = 1; i <= nsz; i ++)
            f[i] = i;
    }
    void operator = (DSU b) {
        sz = b.sz;
        f = b.f;
    }
};