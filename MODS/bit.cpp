struct BIT {
    int s[N + 5];
    void init() {
        memset(s, 0, sizeof s);
    }
    BIT() { init(); }
    int lowbit(int x) {
        return x & -x;
    }
    void update(int x, int d) {
        for (; x <= N; x += lowbit(x))
            s[x] += d;
    }
    int query(int x) {
        int ret = 0;
        for (; x; x -= lowbit(x))
            ret += s[x];
        return ret;
    }
};